#include <pthread.h>
#include <algorithm>
#include <iostream>
#include <omp.h>
#include "barrier.h"
typedef struct timespec timespec;

typedef unsigned long long ull;
inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi) );
    return ((unsigned long long)hi << 32) | lo;
}

const size_t iterations = 1024L*80L*1024L*8L;
template<size_t OFFSET, int THREADS=2>
void recalcField(char*const main, char*const result, const size_t N, const size_t M, const size_t count) {
    BarrierOMP<OFFSET> barrier{THREADS};
     ull global_min = UINT64_MAX, sum_ticks = 0, sum_elems = 0;
    #pragma omp parallel num_threads(THREADS) 
    {
        ull start, end, min = UINT64_MAX;
        char* mainField = main;
        char* resultField = result;

        for (size_t i = 0; i < count; ++i) {
            #pragma omp for
            for (size_t row = 0; row < N; ++row) {
                for (size_t colon = 0; colon < M; ++colon) {
                    size_t pos = row*M + colon;
                    int neighbors = 0;
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            size_t neighborPos = pos + i*M + j;
                            if ((i != 0 || j != 0) && neighborPos >= 0 && neighborPos < M*N && mainField[neighborPos]) {
                                ++neighbors;
                            }
                        }
                    }
                    if (mainField[pos]) {
                        if (neighbors < 2 || neighbors > 3) {
                            resultField[pos] = 0;
                        } else {
                            resultField[pos] = 1;
                        }
                    } else {
                        if (neighbors != 3) {
                            resultField[pos] = 0;
                        } else {
                            resultField[pos] = 1;
                        }
                    }
                }
            }

            std::swap(mainField, resultField);


            start = rdtsc();
            barrier.wait();
            end = rdtsc();
            min = end - start > min ? min : end - start;
            #pragma omp critical
            {
                if (end - start < 1000000) {
                    sum_ticks += (end - start);
                    ++sum_elems;
                }
            }
        }
        #pragma omp critical
        {
            global_min = global_min <= min ? global_min : min;
        }
    }
    std::cout << global_min << "," << sum_ticks / sum_elems << std::endl;
    std::cout.flush();
}

int main(int argc, char** argv) {
    std::cout.precision(10);
    char* mainField = new char[1024*1024*80]{0};
    char* tmpField = new char[1024*1024*80];
    int N[] = {128, 512, 2048, 1024*8};
    int M[] = {128, 256, 2048, 1024*10};
    for (int i = 0; i < 4; ++i) {
        recalcField<0,8>(mainField, tmpField, N[i], M[i], iterations / N[i] / M[i]);
        recalcField<1,8>(mainField, tmpField, N[i], M[i], iterations / N[i] / M[i]);
        recalcField<64,8>(mainField, tmpField, N[i], M[i], iterations / N[i] / M[i]);
        recalcField<4096,8>(mainField, tmpField, N[i], M[i], iterations / N[i] / M[i]);
        std::cout << std::endl;
    }
    delete[] mainField;
    delete[] tmpField;
}

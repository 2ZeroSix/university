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

const size_t iterations = 1024*64;
template<size_t OFFSET, int THREADS=2>
void recalcField(char*const main, char*const result, const size_t N, const size_t M, const size_t count) {
    BarrierOMP<OFFSET> barrier{THREADS};
    volatile ull global_min = UINT64_MAX, global_average = UINT64_MAX, average;
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
                            if (i != 0 && j != 0 && neighborPos >= 0 && neighborPos < M*N && mainField[neighborPos]) {
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
            start = rdtsc();
            barrier.wait();
            end = rdtsc();
            #pragma omp single
            {
                average = 0;
            }
            min = end - start > min ? min : end - start;
            #pragma omp critical
            {
                average += (end - start) / THREADS;
            }
            barrier.wait();
            #pragma omp single
            {
                global_average = global_average <= average ? global_average : average ;
            }
            barrier.wait();
            std::swap(mainField, resultField);
        }
        #pragma omp critical
        {
            global_min = global_min <= min ? global_min : min;
        }
    }
    std::cout << global_min << "," << global_average << std::endl;
}
void recalcField(const char* mainField, char* resultField, size_t N, size_t M) {
    for (size_t row = 0; row < N; ++row) {
        for (size_t colon = 0; colon < M; ++colon) {
            size_t pos = row*M + colon;
            int neighbors = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    size_t neighborPos = pos + i*M + j;
                    if (i != 0 && j != 0 && neighborPos >= 0 && neighborPos < M*N && mainField[neighborPos]) {
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
}
void printField(const char* field, size_t N, size_t M) {
    for (size_t colon = 0; colon < M; ++colon)
        std::cout << "-";
    std::cout << std::endl;

    for (size_t row = 0; row < N; ++row) {
        for (size_t colon = 0; colon < M; ++colon) {
            std::cout << (field[row*M + colon] ? "X" : "O");
        }
        std::cout << std::endl;
    }

    for (size_t colon = 0; colon < M; ++colon)
        std::cout << "-";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    std::cout.precision(10);
    char* mainField = new char[2048*1024];
    char* tmpField = new char[2048*1024];
    for (size_t i = 0; i < 2048*1024; ++i) {
        mainField[i] = i%5;
    }
    for (size_t N = 64, M = 32; N <= 1024; N *= 2, M *= 4) {
        recalcField<0>(mainField, tmpField, N, M, iterations);
        recalcField<1>(mainField, tmpField, N, M, iterations);
        recalcField<64>(mainField, tmpField, N, M, iterations);
        recalcField<4096>(mainField, tmpField, N, M, iterations);
        std::cout << std::endl;
    }
    delete[] mainField;
    delete[] tmpField;
}

#include <pthread.h>
#include <algorithm>
#include <iostream>
#include <omp.h>
#include "barrier.h"
typedef struct timespec timespec;
#define THREADS 2
#define LIB 1
inline timespec gettime() {
    timespec time;
    clock_gettime(CLOCK_MONOTONIC_RAW, &time);
    return time;
}

inline void update_min(const timespec& start, const timespec& end, timespec& min) {
    timespec tmp = {end.tv_sec - start.tv_sec - (end.tv_nsec - start.tv_nsec < 0), (end.tv_nsec - start.tv_nsec + 1000000000) % 1000000000};
    min = min.tv_sec < tmp.tv_sec ? min : (min.tv_nsec < tmp.tv_nsec ? min : tmp); 
}

const size_t iterations = 100;
template<size_t offset>
void recalcField(char*const main, char*const result, const size_t N, const size_t M, const size_t count) {
	#if LIB == 0
	BarrierOMP<offset> barrier{THREADS};
	#endif
	#pragma omp parallel num_threads(THREADS) 
	{
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
			#if LIB == 1
			#pragma omp barrier
			#else
			barrier.wait();
			#endif
			std::swap(mainField, resultField);
		}
	}
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
	size_t N = 64, M = 32;
	for (int i = 0; i < 4; ++i) {
		timespec start, end, min = {INT64_MAX, INT64_MAX};
		for (size_t iter = 0; iter < 100; ++iter) {
			start = gettime();
			recalcField<1>(mainField, tmpField, N, M, iterations);
			end = gettime();
			update_min(start, end, min);
		}
		std::cout << std::fixed << min.tv_sec + min.tv_nsec*0.000000001 << std::endl;
		N *= 2;
		M *= 4;
	}
	N = 64, M = 32;
	for (int i = 0; i < 4; ++i) {
		timespec start, end, min = {INT64_MAX, INT64_MAX};
		for (size_t iter = 0; iter < 100; ++iter) {
			start = gettime();
			recalcField<64>(mainField, tmpField, N, M, iterations);
			end = gettime();
			update_min(start, end, min);
		}
		std::cout << std::fixed << min.tv_sec + min.tv_nsec*0.000000001 << std::endl;
		N *= 2;
		M *= 4;
	}
	N = 64, M = 32;
	for (int i = 0; i < 4; ++i) {
		timespec start, end, min = {INT64_MAX, INT64_MAX};
		for (size_t iter = 0; iter < 100; ++iter) {
			start = gettime();
			recalcField<4096>(mainField, tmpField, N, M, iterations);
			end = gettime();
			update_min(start, end, min);
		}
		std::cout << std::fixed << min.tv_sec + min.tv_nsec*0.000000001 << std::endl;
		N *= 2;
		M *= 4;
	}
	delete[] mainField;
	delete[] tmpField;
}
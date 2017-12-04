#include <vector>
#include <iostream>
#include <cstdint>
#include <complex>
#include <immintrin.h>
using namespace std;
typedef unsigned long long ull;
inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi) );
    return ((unsigned long long)hi << 32) | lo;
}

typedef struct timespec timespec;

inline timespec gettime() {
    timespec time;
    clock_gettime(CLOCK_MONOTONIC_RAW, &time);
    return time;
}

inline void update_min(timespec start, timespec end, timespec& min) {
    timespec tmp = {end.tv_sec - start.tv_sec - (end.tv_nsec - start.tv_nsec < 0), (end.tv_nsec - start.tv_nsec + 1000000000) % 1000000000};
    min = min.tv_sec < tmp.tv_sec ? min : (min.tv_nsec < tmp.tv_nsec ? min : tmp); 
}

template<class T>
void func(size_t size = sizeof(T)) {
    vector<T> *v1 = new vector<T>(1024 * 1024 * 100 / size);
    vector<T> *v2 = new vector<T>(1024 * 1024 * 100 / size);
    {
        ull start, end, min = UINT64_MAX;
        for (size_t i = 0; i < 100; ++i) {
            start = rdtsc();
            for (auto it1 = v1->begin(), it2 = v2->begin(); it1 != v1->end(); ++it1, ++it2) {
                *it1 = *it2;
            }
            end = rdtsc();
            min = min < end - start ? min : end - start;
        }
        cout << size << " : " << endl << ((double)min / (1024 * 1024 * 100 / size)) << *(int*)&(*v1)[100] << *(int*)&(*v2)[100]<< endl;
    delete v1;
    delete v2;
    v1 = new vector<T>(1024 * 1024 * 100 / size);
    v2 = new vector<T>(1024 * 1024 * 100 / size);
        min = UINT64_MAX;
        for (size_t i = 0; i < 100; ++i) {
            start = rdtsc();
            *v1 = *v2;
            end = rdtsc();
            min = min < end - start ? min : end - start;
        }
        cout << ((double)min / (1024 * 1024 * 100 / size)) << *(int*)&(*v1)[100] << *(int*)&(*v2)[100]<< endl;
    delete v1;
    delete v2;
    }
    {
    v1 = new vector<T>(1024 * 1024 * 100 / size);
    v2 = new vector<T>(1024 * 1024 * 100 / size);
        timespec start, end, min = {INT64_MAX, INT64_MAX};
        for (size_t i = 0; i < 100; ++i) {
            start = gettime();
            for (auto it1 = v1->begin(), it2 = v2->begin(); it1 != v1->end(); ++it1, ++it2) {
                *it1 = *it2;
            }
            end = gettime();
            update_min(start, end, min);
        }
        cout << size << " : " << *(int*)&(*v1)[100] << *(int*)&(*v2)[100]<< endl;
        cout << fixed << (100) / ((double)min.tv_sec + min.tv_nsec / 1000000000.) << endl;
        cout.flush();
    delete v1;
    delete v2;
    v1 = new vector<T>(1024 * 1024 * 100 / size);
    v2 = new vector<T>(1024 * 1024 * 100 / size);
        min = {INT64_MAX,INT64_MAX};
        for (size_t i = 0; i < 100; ++i) {
            start = gettime();
            *v1 = *v2;
            end = gettime();
            update_min(start, end, min);
        }
        cout << fixed << (100) / ((double)min.tv_sec + min.tv_nsec / 1000000000.) << endl;
        cout << *(int*)&(*v1)[100] << *(int*)&(*v2)[100]<< endl;
        cout.flush();
    delete v1;
    delete v2;
    }
}

int main() {
    cout.precision(15);
    func<int8_t>();
    func<int16_t>();
    func<int32_t>();
    func<int64_t>();
    func<__int128>();
    func<__m256i>();
}

#include <vector>
#include <iostream>
#include <cstdint>
#include <complex>

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
    timespec tmp = {end.tv_sec - start.tv_sec - (end.tv_nsec - start.tv_nsec < 0), end.tv_nsec - start.tv_nsec + (end.tv_nsec - start.tv_nsec < 0)}
    min = min.sec < tmp.sec ? min : (min.nsec < tmp.nsec ? min : tmp); 
}

template<class T>
void func(size_t size) {
    vector<T> *v1 = new vector<T>(8 * 1024 * 1024 * 100 / size);
    vector<T> *v2 = new vector<T>(8 * 1024 * 1024 * 100 / size);
    {
        ull start, end, min = UINT64_MAX;
        for (size_t i = 0; i < 100; ++i) {
            start = rdtsc();
            *v1 = *v2;
            end = rdtsc();
            min = min < end - start ? min : end - start;
        }
        cout << size << " : " << endl << ((double)min / (8 * 1024 * 1024 * 100 / size)) << (*v1)[100] << (*v2)[100]<< endl;
        for (size_t i = 0; i < 100; ++i) {
            start = rdtsc();
            for (auto it1 = v1->begin(), it2 = v2->begin(); it1 != v1->end(); ++it1, ++it2) {
                *it1 = *it2;
            }
            end = rdtsc();
            min = min < end - start ? min : end - start;
        }
        cout << ((double)min / (8 * 1024 * 1024 * 100 / size)) << (*v1)[100] << (*v2)[100]<< endl;
    }
    {
        timespec start, end, min = {99999999};
        for (size_t i = 0; i < 100; ++i) {
            start = gettime();
            *v1 = *v2;
            end = gettime();
            update_min(start, end, min);
        }
        cout << size << " : " << endl << ((double)min / (8 * 1024 * 1024 * 100 / size)) << (*v1)[100] << (*v2)[100]<< endl;
        for (size_t i = 0; i < 100; ++i) {
            start = gettime();
            for (auto it1 = v1->begin(), it2 = v2->begin(); it1 != v1->end(); ++it1, ++it2) {
                *it1 = *it2;
            }
            end = gettime();
            update_min(start, end, min);
        }
        cout << ((double)min / (8 * 1024 * 1024 * 100 / size)) << (*v1)[100] << (*v2)[100]<< endl;
    }
    delete v1;
    delete v2;
}

int main() {
    func<int8_t>(8);
    func<int16_t>(16);
    func<int32_t>(32);
    func<int64_t>(64);
    func<complex<int64_t>>(128);
}

#include <stdio.h>
#include <utility>
#include <random>
typedef unsigned long long ull;
inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi) );
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    int arr[1024*1024*25] = {0};
    for (int i = 0; i < 1024*1024*25; ++i) {
        arr[i] = i;
    }
    std::random_device rd;
    for (int i = 0; i < 1024*1024*25; ++i) {
        std::swap(arr[i], arr[i + rd() % (1024*1024*25 - i)]);
    }
    int k = 0;
    ull start, end, min = __UINT64_MAX__;
    for (int j = 0; j < 10000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    printf("%d\b", k%2);
    printf("1 : %llu\n", min);
    return 0;
}
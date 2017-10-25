#include <stdio.h>

inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi) );
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    int a = 1;
    unsigned long long min = __UINT64_MAX__, clock, clock2;
    for (int j = 0; j < 1000000; ++j) {
        clock = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            a = a*a;
        }
        clock2 = rdtsc();
        min = clock2 - clock < min ? clock2 - clock : min;
    }
    printf("%llu\n",  min);
    return 0;
}
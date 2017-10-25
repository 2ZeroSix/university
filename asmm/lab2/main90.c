
#include <stdio.h>
typedef unsigned long long ull;
inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi) );
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    int arr[1] = {0};
    int k;
    ull start, end, min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 100; ++i) {
            k = arr[1];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    printf("90 : %llu\n", min);
    return 0;
}
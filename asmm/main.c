#include <stdio.h>


int main() {
    unsigned clock = 0;
    int a = 1;
    asm ("rdtsc;"
        "mov clock, %eax;");

    unsigned clo = clock;
    for (int i = 0; i < 1000000; ++i) {
        a += a;
    }
    
    asm ("rdtsc;"
        "mov clock, %eax;");
    printf("%u\n",  clock);
    clock = clock - clo;
    return 0;
}
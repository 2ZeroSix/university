from subprocess import Popen

arr = []
for i in range(1, 256):
    with open("main" + str(i) + ".c", "w") as file:
        file.write("""
#include <stdio.h>
#include <utility>
#include <random>
typedef unsigned long long ull;
inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\\n" : "=a" (lo), "=d" (hi) );
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
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 100; ++i) {
            k = arr[k];""")
        for j in range(i):
            file.write("\tasm(\"nop\");")
        file.write("""
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    printf("%d\\b", k%2);
    printf(\"""" + str(i) + """ : %llu\\n", min);
    return 0;
}""")
    comp = Popen(["g++", "main" + str(i) + ".c", "-O3", "-std=c++11"])
    exitcode = comp.wait()
    if exitcode:
        raise SystemExit("compiler returned non-zero exit code: " + str(exitcode))
    prog = Popen(["./a.out"])
    # stdout, _ = prog.communicate()
    exitcode = prog.wait()
    if exitcode:
        raise SystemExit("program returned non-zero exit code: " + str(exitcode))
    # arr.append(int(stdout))
print(arr)

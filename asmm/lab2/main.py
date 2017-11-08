#!/usr/bin/python3
from subprocess import Popen

print("generating source")
with open("main.c", "w") as file:
    file.write("""
#include <iostream>
#include <utility>
#include <random>
typedef unsigned long long ull;
using namespace std;
inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\\n" : "=a" (lo), "=d" (hi) );
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    int* arr = new int[1024*1024*25];
    cout << "generating array" << endl;

    for (int i = 0; i < 1024*1024*25; ++i) {
        arr[i] = i;
    }
    std::random_device rd;
    cout << "randomize array" << endl;
    for (int i = 0; i < 1024*1024*25; ++i) {
        std::swap(arr[i], arr[i + rd() % (1024*1024*25 - i)]);
    }
    cout << "run tests" << endl;
    int k = 0;
    ull start, end, min;""")
    for i in range(1, 256):
        file.write("""
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];""")
        for j in range(i):
            file.write("\tasm(\"nop\");")
        file.write("""
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\\b" <<  min << ", ").flush();""")
    file.write("""
    delete[] arr;
    return 0;
}""")
print("compiling")
comp = Popen(["g++", "main.c", "-O3", "-std=c++11"])
exitcode = comp.wait()
if exitcode:
    raise SystemExit("compiler returned non-zero exit code: " + str(exitcode))
print("run")
prog = Popen(["./a.out"])
exitcode = prog.wait()
if exitcode:
    raise SystemExit("program returned non-zero exit code: " + str(exitcode))

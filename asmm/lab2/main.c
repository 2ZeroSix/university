
#include <iostream>
#include <utility>
#include <random>
typedef unsigned long long ull;
using namespace std;
inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi) );
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
    ull start, end, min;
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    min = __UINT64_MAX__;
    for (int j = 0; j < 100000; ++j) {
        start = rdtsc();
        for (int i = 0; i < 1000; ++i) {
            k = arr[k];	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");	asm("nop");
        }
        end = rdtsc();
        min = end - start < min ? end - start : min;
    }
    (cout << k%2 << "\b" <<  min << ", ").flush();
    delete[] arr;
    return 0;
}
#include <iostream>

const int iter = 10000;
const int maxL = 10;
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

inline void update_min(const timespec& start, const timespec& end, timespec& min) {
    timespec tmp = {end.tv_sec - start.tv_sec - (end.tv_nsec - start.tv_nsec < 0), (end.tv_nsec - start.tv_nsec + 1000000000) % 1000000000};
    min = min.tv_sec < tmp.tv_sec ? min : (min.tv_nsec < tmp.tv_nsec ? min : tmp); 
}

int main(int argc, char** argv) {
    cout.precision(5);
    int a = 1;
    int type = atoi(argv[1]);
    int L = 7;
    switch (type) {
        case -1: {
            for (int L = 1; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (j%(L) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 0: {
            for (int L = 1; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (j%(L) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 1: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 2: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 3: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 4: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 5: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 6: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 7: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 8: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 9: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 10: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 11: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
        case 12: {
            for (int L = 2; L < maxL; ++L) {
                ull start, end, min = __UINT64_MAX__;
                for (int i = 0; i < 1000; ++i) {
                    start = rdtsc();
                    for (int j = 0; j < iter; ++j) {
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (i<0) a=1; else a=0;
                        if (j%(L-1) == 0) a = 0; else a=1;
                    }
                    end = rdtsc();
                    cout << a%2 << "\b \b";
                    min = min < end - start ? min : end - start;
                }
                cout << fixed << (double)min / iter << ",";
            }
            break;
        }
    }
}
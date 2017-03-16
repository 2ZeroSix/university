#include<iostream>

template<bool b, typename T=void>
struct enable_if {};

template<typename T>
struct enable_if<true, T> {
    typedef T val;
};

template<typename T>
struct is_integral {
    const static bool val = false;
};

template<>
struct is_integral<bool> {
    const static bool val = true;
};

template<>
struct is_integral<signed char> {
    const static bool val = true;
};

template<>
struct is_integral<unsigned char> {
    const static bool val = true;
};

template<>
struct is_integral<char16_t> {
    const static bool val = true;
};

template<>
struct is_integral<char32_t> {
    const static bool val = true;
};

template<>
struct is_integral<wchar_t> {
    const static bool val = true;
};

template<>
struct is_integral<signed short> {
    const static bool val = true;
};

template<>
struct is_integral<unsigned short> {
    const static bool val = true;
};

template<>
struct is_integral<signed int> {
    const static bool val = true;
};

template<>
struct is_integral<unsigned int> {
    const static bool val = true;
};

template<>
struct is_integral<signed long> {
    const static bool val = true;
};

template<>
struct is_integral<unsigned long> {
    const static bool val = true;
};

template<>
struct is_integral<signed long long> {
    const static bool val = true;
};

template<>
struct is_integral<unsigned long long> {
    const static bool val = true;
};

template<typename T>
void f(T arg) {
    if (is_integral<T>::val) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}

int main () {
    f(10);
}

#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <vector>
#include <utility>
#include <ostream>
#include <cmath>
namespace matrix {
    template<typename T>
    class Matrix;
}
namespace matrixMPI {
    template<typename T>
    class Matrix;
}
template<typename T>
class Vector {
private:
    friend matrix::Matrix<T>;
    friend matrixMPI::Matrix<T>;
    std::size_t size;
    std::vector<T> data;
public:
    explicit Vector(std::size_t size = 0, const T& init = T())
    :   size(size), data(size, init) {}
    
    Vector(const Vector<T>& vec)
    :   size(vec.size),
        data(vec.data) {}
    
    Vector(Vector<T>&& vec)
    :   size(vec.size),
        data(std::move(vec.data))
        {vec.size = 0;}

    const Vector<T>& operator=(const Vector<T>& vec) {
        size = vec.size;
        data = vec.data;
        return *this;
    }

    const Vector<T>& operator=(Vector<T>&& vec) {
        std::swap(size = 0, vec.size);
        data = std::move(vec.data);
        return *this;
    }

    std::size_t getSize() const {return size;}

    T operator*(const Vector<T>& vec) const {
        //TODO add exception
        T result = T();
        if(size == vec.size) {
            for(std::size_t i = 0; i < size; ++i) {
                result += (*this)[i]*vec[i];
            }
        }
        return result;
    }

    Vector<T>& operator*=(const T& scalar) {
        for (std::size_t i = 0; i < size; ++i) data[i] *= scalar;
        return *this;
    }

    friend Vector<T> operator*(const Vector<T>& vec, const T& scalar) {
        Vector<T> res(vec);
        return res *= scalar;
    }

    friend Vector<T> operator*(const T& scalar, const Vector<T>& vec) {
        Vector<T> res(vec);
        return res *= scalar;
    }


    Vector<T>& operator+=(const Vector<T>& vec) {
        if(size == vec.size) {
            for(std::size_t i = 0; i < size; ++i) {
                (*this)[i] += vec[i];
            }
        }
        return *this;
    }

    friend Vector<T> operator+(const Vector<T>& a, const Vector<T>& b) {
        Vector<T> result(a);
        return result+=b;
    }

    Vector<T>& operator-=(const Vector<T>& vec) {
        if(size == vec.size) {
            for(std::size_t i = 0; i < size; ++i) {
                (*this)[i] -= vec[i];
            }
        }
        return *this;
    }

    friend Vector<T> operator-(const Vector<T>& a, const Vector<T>& b) {
        Vector<T> result(a);
        return result-=b;
    }

    T& operator[](std::size_t n) {
        return data[n];
    }

    const T& operator[](std::size_t n) const {
        return data[n];
    }

    T norm2() const{
        T sumPow2 = T();
        for(std::size_t i = 0; i < size; ++i) {
            sumPow2 += data[i]*data[i];
        }
        return std::sqrt(sumPow2);
    }

    ~Vector() {}

    friend void swap(Vector<T>&& a, Vector<T>&& b) {
        std::swap(a.size, b.size);
        std::swap(a.data, b.data);
    }

    friend std::ostream& operator<< (std::ostream& fout, const Vector<T>& vec) {
        for (std::size_t i = 0; i < vec.size; ++i) fout << vec[i] << " ";
        fout << std::endl;
        return fout;
    }
};

#endif

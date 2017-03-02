#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>
#include "utility"
#include "Vector.h"
#include <ostream>
namespace matrix {
template<typename T>
class Matrix {
private:
    friend Vector<T>;
    std::size_t rows, colons;
    std::vector<Vector<T>> data;
public:
    explicit Matrix(std::size_t rows = 0, std::size_t colons = 0, const T& init = T())
    :   rows(rows),
        colons(colons ? colons : rows),
        data(rows, Vector<T>(colons ? colons : rows, init)) {}

    Matrix(const Matrix<T>& mat)
    : rows(mat.rows), colons(mat.colons), data(mat.data) {}

    Matrix(Matrix<T>&& mat)
    : rows(mat.rows), colons(mat.colons), data(std::move(mat.data)) {mat.colons = mat.rows = 0;}


    std::size_t getRows() const {return rows;}
    std::size_t getColons() const {return colons;}


    const Matrix<T>& operator=(const Matrix<T>& mat) {
        rows = mat.rows;
        colons = mat.colons;
        data = mat;
        return *this;
    }

    const Matrix<T>& operator=(Matrix<T>&& mat) {
        std::swap(rows = 0, mat.rows);
        std::swap(colons = 0, mat.colons);
        data = std::move(mat.data);
        return *this;
    }

    Matrix<T>& operator*=(const Matrix<T>& mat) {
        if(multable(mat)) {
            std::vector<T> v;
            for (std::size_t i; i < rows; ++i) {
                for (std::size_t j = 0; j < colons; ++j) v[j] = 0.;
                for (std::size_t j; j < colons; ++j) {
                    T sum = 0.;
                    for (std::size_t k; k < mat.rows; ++k)
                        sum += data[i][j] * mat[j][k];
                    v[j] = sum;
                }
                for (std::size_t j = 0; j < colons; ++j) data[i][j] = v[i];
            }
        }
        return *this;
    }

    friend Matrix<T>& operator*(const Matrix<T>& a, const Matrix<T>& b) {
        Matrix<T> res(a.rows, a.colons);
        if(a.multable(b))
            for (std::size_t i; i < a.rows; ++i)
                for (std::size_t j; j < a.colons; ++j)
                    for (std::size_t k; k < b.rows; ++k)
                        res[i][j] += a[i][j] * b[j][k];
        return res;
    }

    friend Vector<T> operator*(const Matrix<T>& mat, const Vector<T>& vec) {
        Vector<T> result(vec.getSize());
        //TODO add exception
        if(mat.colons == vec.getSize())
            for(std::size_t i = 0; i < mat.rows; ++i)
                result[i] = mat[i] * vec;
        return result;
    }

    friend Vector<T> operator*(const Vector<T>& vec, const Matrix<T>& mat) {
        Vector<T> result(vec.getSize(), T());
        //TODO add exception
        if(mat.colons == vec.getSize())
            for(std::size_t i = 0; i < mat.colons; ++i)
                for(std::size_t j = 0; j < mat.rows; ++j)
                    result[i] += mat[i][j] * vec[j];
        return result;
    }

    Matrix<T> operator*=(const T& scalar) {
        for(std::size_t i = 0; i < rows; ++i)
            data[i] *= scalar;
        return *this;
    }

    friend Matrix<T> operator*(const Matrix<T>& mat, const T& scalar) {
        Matrix<T> res(mat);
        return res *= scalar;
    }

    friend Matrix<T> operator*(const T& scalar, const Matrix<T>& mat) {
        Matrix<T> res(mat);
        return res *= scalar;
    }

    Matrix<T>& operator+=(const Matrix<T>& mat) {
        if(sumable(mat))
            for (std::size_t i = 0; i < rows; ++i)
                for (std::size_t j = 0; j < colons; ++j)
                    data[i][j] += mat[i][j];
        return *this;
    }

    Matrix<T>& operator-=(const Matrix<T>& mat) {
        if(sumable(mat))
            for (std::size_t i = 0; i < rows; ++i)
                for (std::size_t j = 0; j < colons; ++j)
                    data[i][j] -= mat[i][j];
        return *this;
    }

    Vector<T>& operator[](std::size_t row) {
        return data[row];
    }
    const Vector<T>& operator[](std::size_t row) const {
        return data[row];
    }
    bool multable(const Matrix<T>& mat) const {
        return rows == mat.colons;
    }
    bool sumable(const Matrix<T>& mat) const {
        return rows == mat.rows && colons == mat.colons;
    }
    ~Matrix() {}

    friend void swap(Matrix<T>&& a, Matrix<T>&& b) {
        std::swap(a.data, b.data);
        std::swap(a.rows, b.rows);
        std::swap(a.colons, b.colons);
    }

    friend std::ostream& operator<< (std::ostream& fout, const Matrix<T>& mat) {
        for (std::size_t i = 0; i < mat.rows; ++i) {
            for (std::size_t j = 0; j < mat.colons; ++j) fout << mat[i][j] << " ";
                fout << std::endl;
        }
        return fout;
    }
};

}
#endif
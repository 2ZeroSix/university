#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <omp.h>
using namespace std;


void multMatrixVector(const double* mat, const double* vec,
                         size_t rows, size_t colons,
                         double* res, bool setNull = true) {
    #pragma omp parallel for
    for (size_t row = 0; row < rows; ++row) {
        if(setNull) res[row] = 0;
        for (size_t colon = 0; colon < colons; ++colon) {
            res[row] += mat[row*colons + colon] * vec[colon];
        }
    }
}

void vectorAssignSub(double* other, size_t size, double* res) {
    #pragma omp parallel for
    for (size_t i = 0; i < size; ++i) {
        res[i] -= other[i];
    }
}

void vectorMulScalar(double* vec, size_t size, double scalar) {
    #pragma omp parallel for
    for (size_t i = 0; i < size; ++i) {
        vec[i] *= scalar;
    }
}

double norm2(double* vec, size_t size) {
    double sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < size; ++i) {
        sum += vec[i]*vec[i];
    }
    return sum;
}

double* slauSolveIteration(double* mat,
                                  double* result,
                                  size_t size,
                                  double epsilon = 0.000000001,
                                  double tau = 0.01) {
    double* x   = new double[size]();
    double* tmp = new double[size]();
    multMatrixVector(mat, x, size, size, tmp);
    vectorAssignSub(result, size, tmp);
    epsilon = epsilon*epsilon;
    double prevCriterion = norm2(tmp, size) / norm2(result, size);
    double criterion = prevCriterion;
    while(true) {
        if      ( criterion < epsilon )         break;
        else if ( criterion > prevCriterion )   tau *= 0.1;
        vectorMulScalar(tmp, size, tau);
        vectorAssignSub(tmp, size, x);
        multMatrixVector(mat, x, size, size, tmp);
        vectorAssignSub(result, size, tmp);
        prevCriterion = criterion;
        criterion = norm2(tmp, size) / norm2(result, size);
    }
    delete[] tmp;
    return x;
}
double* getMatrix(size_t N) {
    double* mat = new double[N*N]();
    #pragma omp parallel for
    for (size_t i = 0; i < N*N; ++i) mat[i] = 1.;
    #pragma omp parallel for
    for (size_t i = 0; i < N; ++i) mat[i*N + i] = 2.;
    return mat;
}

double* getVector(size_t N) {
    double* answer = new double[N]();
    #pragma omp parallel for
    for(size_t i = 0; i < N; ++i) answer[i] = 1. / (i + 1.);
    return answer;
}

double* getResult(const double* mat, const double* answer, size_t N) {
    double* result = new double[N]();
    multMatrixVector(mat, answer, N, N, result, false);
    return result;
}

int main(int argc, char** argv) {
    size_t N = 200;
    double* mat = getMatrix(N);
    double* answer = getVector(N);
    #pragma omp parallel
    {
        #pragma omp single
        cout << "threads: " << omp_get_num_threads() << endl;
    }
    cout << "real answer:" << endl;
    #pragma omp parallel for ordered
    for (int i = 0; i < N; ++i) {
        #pragma omp ordered
        {
            cout << answer[i] << " ";
        }
    }
    cout << endl;
    double* result = getResult(mat, answer, N);
    double* x = slauSolveIteration(mat, result, N);
    cout << "answer:" << endl;
    #pragma omp parallel for ordered
    for (int i = 0; i < N; ++i) {
        #pragma omp ordered
        {
            cout << x[i] << " ";
        }
    }
    cout << endl;
    delete[] mat;
    delete[] answer;
    delete[] result;
    delete[] x;
}

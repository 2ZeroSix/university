#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <omp.h>
using namespace std;


void multMatrixVector(const double* mat, const double* vec,
                         size_t rows, size_t colons,
                         double* res, bool setNull = true) {
    #pragma omp for
    for (size_t row = 0; row < rows; ++row) {
        if(setNull) res[row] = 0;
        for (size_t colon = 0; colon < colons; ++colon) {
            res[row] += mat[row*colons + colon] * vec[colon];
        }
    }
}

void vectorAssignSub(double* other, size_t size, double* res) {
    #pragma omp for
    for (size_t i = 0; i < size; ++i) {
        res[i] -= other[i];
    }
}

void vectorMulScalar(double* vec, size_t size, double scalar) {
    #pragma omp for
    for (size_t i = 0; i < size; ++i) {
        vec[i] *= scalar;
    }
}

void norm2(double* vec, size_t size, double& sum) {
    #pragma omp for reduction(+:sum)
    for (size_t i = 0; i < size; ++i) {
        sum += vec[i]*vec[i];
    }
}

void criterion(double* x, double* res, size_t size, double &crit, double &sum) {
    #pragma omp master
    {
        sum = 0;
        crit = 0;
    }
    norm2(x, size, crit);
    norm2(res, size, sum);
    #pragma omp master atomic
    {
        crit /= sum;
    }
}

double* slauSolveIteration(double* mat,
                                  double* result,
                                  size_t size,
                                  double epsilon = 0.000000001,
                                  double tau = 0.01) {
    double* x   = new double[size]();
    double* tmp = new double[size]();
    epsilon = epsilon*epsilon;
    double prevCriterion;
    double crit;
    double sum;
    #pragma omp parallel firstprivate(tau)
    {
        #pragma omp master
        cout << "tau: " << tau << endl;
        multMatrixVector(mat, x, size, size, tmp);
        vectorAssignSub(result, size, tmp);
        criterion(x, result, size, crit, sum);
        while(true) {
            vectorMulScalar(tmp, size, tau);
            vectorAssignSub(tmp, size, x);
            multMatrixVector(mat, x, size, size, tmp);
            vectorAssignSub(result, size, tmp);
            #pragma omp master
            prevCriterion = crit;
            // #pragma omp barrier
            criterion(x, result, size, crit, sum);
            #pragma omp master
            cout << "crit: " << crit << endl;
            if ( crit < epsilon ) break;
            else if ( crit > prevCriterion ) tau *= 0.1;
        }
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
    #pragma omp parallel
    {
        multMatrixVector(mat, answer, N, N, result, false);
    }
    return result;
}

int main(int argc, char** argv) {
    size_t N = 10;
    double* mat = getMatrix(N);
    double* answer = getVector(N);
    #pragma omp parallel
    {
        #pragma omp single
        cout << "threads: " << omp_get_num_threads() << endl;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << mat[i*N + j] << " ";
        cout << endl;
    }
    cout << "real answer:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;
    double* result = getResult(mat, answer, N);
    double* x = slauSolveIteration(mat, result, N);
    cout << "answer:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
    delete[] mat;
    delete[] answer;
    delete[] result;
    delete[] x;
}

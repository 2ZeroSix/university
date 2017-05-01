#include <iostream>
#include <limits>
#include <omp.h>
using namespace std;

double dotProduct(double* f, double* s, int N) {
    double res = 0;

    for (int i = 0; i < N; i++)
        res += f[i]*s[i];

    return res;
}

double* slauSolveIteration(double* matrix,
                                  double* b,
                                  size_t N,
                                  double epsilon = 0.00001,
                                  double tau = 0.01) {
    double bVal = 0;
    #pragma omp parallel for reduction(+:bVal)
    for (int i = 0; i < N; ++i) bVal += b[i] * b[i];

    double* x = new double[N];
    double* tmpRes = new double[N];
    double tmpVal;

    epsilon *= epsilon;
    double crit;
    double prevcrit = numeric_limits<double>::max();
    while(true) {
        tmpVal = 0;
        #pragma omp parallel for reduction(+:tmpVal)
        for (int i = 0; i < N; i++) {
            tmpRes[i] = dotProduct(matrix + i*N, x, N) - b[i];
            tmpVal += tmpRes[i] * tmpRes[i];
        }
        crit = tmpVal / bVal;
        if (crit < epsilon) break;
        if (crit > prevcrit) tau *= 0.1;
        prevcrit = crit;
        #pragma omp parallel for
        for (int i = 0; i < N; ++i) {
            x[i] = x[i] - tau*tmpRes[i];
            tmpRes[i] = 0;
        }

    }
    delete[] tmpRes;
    return x;
}

int main(void) {
    int N = 32000;

    double* matrix = new double[N * N];
    double* b = new double[N];

    double st, cm, fn;
    // int tn = omp_get_num_threads();

    st = omp_get_wtime();

    #pragma omp parallel for 
    for (int i = 0; i < N; i++) {
        b[i] = N + 1;
        for (int j = 0; j < N; j++)
            matrix[i * N + j] = (i == j)? 2 : 1;
    }
    cm = omp_get_wtime();

    double* x = slauSolveIteration(matrix, b, N);

    fn = omp_get_wtime();
    cout << "time = " << fn - st << "; computing: " << fn - cm << endl;
    delete[] matrix;
    delete[] b;
    delete[] x;
    return 0;
}

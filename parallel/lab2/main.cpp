#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "slau_solve.h"


int MainIterative(int argc, char** argv) {
    using namespace matrix;
    using namespace std;
    std::size_t N = 199;
    Matrix<double> mat(N, N, 1.);
    #pragma omp parralel for
    for (std::size_t i = 0; i < N; ++i) mat[i][i] = 2.;
    Vector<double> result = mat * Vector<double>(N, 100*sin(6.28/N));
    cout << "real answer:" << endl << Vector<double>(N, 100*sin(6.28/N));
    Vector<double> x = slauSolveIteration(mat, result);
    cout << "answer:" << endl << x;
    // x = slauSolveMinUnbounds(mat, result);
    // cout << "answer:" << endl << x;
    // x = slauSolveGradients(mat, result);
    // cout << "answer:" << endl << x;
    return 0;
}

int main(int argc, char** argv) {
    return MainIterative(argc, argv);
}
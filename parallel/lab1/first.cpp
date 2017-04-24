#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <mpi.h>
#include <string.h>

using namespace std;
int procRank = 0, procSize = 0;

size_t maxChunkSize(size_t realSize, int size=procSize) {
    return realSize / size + (realSize % size ? 1 : 0);
}
size_t getChunkSize(size_t realSize, int rank=procRank, int size=procSize) {
    return realSize / size +
            (rank ? (realSize % size > rank - 1 ? 1 : 0) : 0);
}


void multMatrixVector(double* mat, double* vec,
                         size_t rows, size_t colons,
                         double* res, size_t rowLength = 0,
                         size_t matOffset = 0, bool setNull = true) {
    rowLength = rowLength ? rowLength : colons;
    if(setNull) fill_n(res, rows, 0);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t colon = 0; colon < colons; ++colon) {
            res[row] += mat[row*rowLength + colon + matOffset] * vec[colon];
        }
    }
}

void vectorAssignSub(double* other, size_t size, double* res) {
    for (size_t i = 0; i < size; ++i) {
        res[i] -= other[i];
    }
}

void vectorMulScalar(double* vec, size_t size, double scalar) {
    for (size_t i = 0; i < size; ++i) {
        vec[i] *= scalar;
    }
}

double norm2(double* vec, size_t size) {
    double sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += vec[i]*vec[i];
    }
    return sum;
}

double* multMPIMatrixVector(double* mat, double* vec, size_t rows, size_t colons, double* result = nullptr) {
    double* resultb = new double[getChunkSize(rows, procRank, procSize)]();
    result = result == nullptr ? new double[rows]() : result;
    multMatrixVector(mat, vec, getChunkSize(rows, procRank, procSize), colons, resultb);
    int *recv = new int[procSize]();
    int *disp = new int[procSize]();
    for (int i = 0; i < procSize; ++i) {
        recv[i] = getChunkSize(rows, i, procSize);
        if (i == 0) disp[i] = 0;
        else disp[i] = disp[i - 1] + recv[i - 1];
    }
    MPI::COMM_WORLD.Allgatherv(resultb, getChunkSize(rows, procRank, procSize), MPI::DOUBLE, result, recv, disp, MPI::DOUBLE);
    delete[] recv;
    delete[] disp;
    delete[] resultb;
    return result;
}


double* slauSolveIteration(double* mat,
                                  double* result,
                                  size_t size,
                                  double epsilon = 0.00001,
                                  double tau = 0.01) {
    double* x   = new double[size]();
    double* tmp = new double[size]();
    multMPIMatrixVector(mat, x, size, size, tmp);
    vectorAssignSub(result, size, tmp);
    if (procRank == 0) {
        epsilon = epsilon*epsilon;
        double prevCriterion = norm2(tmp, size) / norm2(result, size);
        double criterion = prevCriterion;
        while(true) {
            if ( criterion < epsilon ) {
                tau = 0.;
                MPI::COMM_WORLD.Bcast(&tau, 1, MPI::DOUBLE, 0);
                break;
            } else if ( criterion > prevCriterion ) {
                tau *= 0.1;
            }
            MPI::COMM_WORLD.Bcast(&tau, 1, MPI::DOUBLE, 0);
            vectorMulScalar(tmp, size, tau);
            vectorAssignSub(tmp, size, x);
            multMPIMatrixVector(mat, x, size, size, tmp);
            vectorAssignSub(result, size, tmp);
            prevCriterion = criterion;
            criterion = norm2(tmp, size) / norm2(result, size);
            // cout << criterion << endl;
        }
    } else {
        while(true) {
            MPI::COMM_WORLD.Bcast(&tau, 1, MPI::DOUBLE, 0);
            if (tau == 0.) {
                break;
            } else {
                vectorMulScalar(tmp, size, tau);
                vectorAssignSub(tmp, size, x);
                multMPIMatrixVector(mat, x, size, size, tmp);
                vectorAssignSub(result, size, tmp);
            }
        }
    }
    delete[] tmp;
    return x;
}

void init(int argc, char** argv) {
    MPI::Init(argc, argv);
    procSize = MPI::COMM_WORLD.Get_size();
    procRank = MPI::COMM_WORLD.Get_rank();    
}

double* getMatrix(size_t N) {
    size_t chunkSize = getChunkSize(N, procRank, procSize);
    size_t chunkOffset = 0;
    for (size_t i = 0; i < procRank; ++i) {
        chunkOffset += getChunkSize(N, i, procSize);
    }
    double* mat = new double[N*chunkSize]();
    for (size_t i = 0; i < N*chunkSize; ++i) mat[i] = 1.;
    for (size_t i = 0; i < chunkSize; ++i) mat[i + chunkOffset + i*N] = 2.;
    return mat;    
}

double* getVector(size_t N) {
    double* answer = new double[N]();
    for(size_t i = 0; i < N; ++i) answer[i] = 1. / (i + 1.);
    return answer;
}

int main(int argc, char** argv) {
    init(argc, argv);
    size_t N = 2048;

    double* mat = getMatrix(N);
    double* answer = getVector(N);
    double* result = multMPIMatrixVector(mat, answer, N, N);

    // if(procRank == 0) cout << "mat:" << endl;
    // for (int proc = 0; proc < procSize; ++proc) {
    //     if (procRank == proc) {
    //         for (size_t i = 0; i < chunkSize; ++i) {
    //             for (size_t j = 0; j < N; ++j) {
    //                 cout << mat[i*N + j] << " ";
    //             }
    //             cout << endl;
    //         }
    //     }
    //     cout.flush();
    //     MPI::COMM_WORLD.Barrier();
    // }
    double* x = slauSolveIteration(mat, result, N);
    // if (procRank == 0) {
    //     cout << "result:" << endl;
    //     for (size_t i = 0; i < N; ++i) cout << result[i] << " ";
    //     cout << endl;

    //     cout << "real answer:" << endl;
    //     for (size_t i = 0; i < N; ++i) cout << answer[i] << " ";
    //     cout << endl;

    //     cout << "answer:" << endl;
    //     for (size_t i = 0; i < chunkSize; ++i) cout << x[i] << " ";
    //     cout << endl;
    // }
    delete[] x;
    delete[] mat;
    delete[] answer;
    delete[] result;
    MPI::Finalize();
    return 0;
}

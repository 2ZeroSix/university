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
    if(setNull) memset(res, 0, sizeof(double)*rows);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t colon = 0; colon < colons; ++colon) {
            res[row] += mat[row*rowLength + colon + matOffset] * vec[colon];
        }
    }
}

void MPIVectorMulScalar(double* vec, size_t size, double scalar) {
    size_t chunkSize = getChunkSize(size, procRank, procSize);
    for (size_t i = 0; i < chunkSize; ++i) {
        vec[i] *= scalar;
    } 
}

void MPIVectorAssignSub(double* other, size_t size, double* res) {
    size_t chunkSize = getChunkSize(size, procRank, procSize);
    for (size_t i = 0; i < chunkSize; ++i) {
        res[i] -= other[i];
    }
}

double MPInorm2(double* vec, size_t size) {
    double tmpSum = 0;
    size_t chunkSize = getChunkSize(size, procRank, procSize);
    for (size_t i = 0; i < chunkSize; ++i) {
        tmpSum += vec[i]*vec[i];
    }
    double sum;
    MPI::COMM_WORLD.Allreduce(&tmpSum, &sum, 1, MPI::DOUBLE, MPI::SUM);
    return sum;
}

double* multMPIMatrixMPIVector(double* mat, double* vec, size_t rows, size_t colons, double* result = nullptr) {
    int *disp = new int[procSize]();
    for (size_t i = 1; i < procSize; ++i) {
        disp[i] = disp[i - 1] + getChunkSize(colons, i - 1, procSize);
    }

    size_t RowChunkSize     = getChunkSize(rows, procRank, procSize);
    size_t ColonChunkSize   = getChunkSize(colons, procRank, procSize);
    result = result ? result : new double[ColonChunkSize]();

    multMatrixVector(mat, vec, RowChunkSize, ColonChunkSize, result, colons, disp[procRank]);

    int nextProc = (procRank + 1) % procSize;
    int prevProc = (procRank - 1 + procSize) % procSize;
    double* curVec = new double[maxChunkSize(colons, procSize)]();
    memcpy(curVec, vec, ColonChunkSize*sizeof(double));

    for (int i = 1; i < procSize; ++i) {
        int curDataProc = (procRank - i + procSize) % procSize;

        MPI::COMM_WORLD.Sendrecv_replace(curVec, maxChunkSize(colons), MPI::DOUBLE, nextProc, 0, prevProc, 0);
        RowChunkSize    = getChunkSize(rows, curDataProc, procSize);
        ColonChunkSize  = getChunkSize(colons, curDataProc, procSize);
        multMatrixVector(mat, curVec, RowChunkSize, ColonChunkSize, result, colons, disp[curDataProc], false);
    }

    delete[] curVec;
    delete[] disp;
    return result;
}

double* slauSolveIterationParallelVectors(  double* mat,
                                            double* result,
                                            size_t size,
                                            double epsilon = 0.00001,
                                            double tau = 0.01) {
    size_t chunkSize = getChunkSize(size);
    double* x   = new double[chunkSize]();
    double* tmp = new double[chunkSize]();
    multMPIMatrixMPIVector(mat, x, size, size, tmp);
    MPIVectorAssignSub(result, size, tmp);
    epsilon = epsilon*epsilon;
    double prevCriterion = MPInorm2(tmp, size) / MPInorm2(result, size);
    double criterion = prevCriterion;
    while(true) {
        if ( criterion < epsilon ) {
            break;
        } else if ( criterion > prevCriterion ) {
            tau *= 0.1;
        }
        MPIVectorMulScalar(tmp, size, tau);
        MPIVectorAssignSub(tmp, size, x);
        multMPIMatrixMPIVector(mat, x, size, size, tmp);
        MPIVectorAssignSub(result, size, tmp);
        prevCriterion = criterion;
        criterion = MPInorm2(tmp, size) / MPInorm2(result, size);
    }
    delete[] tmp;
    return x;
}

void init(int argc, char** argv) {
    MPI::Init(argc, argv);
    procSize = MPI::COMM_WORLD.Get_size();
    procRank = MPI::COMM_WORLD.Get_rank();    
}

void getMatrixAndVector(double** mat, double** answer, size_t N) {
    size_t chunkSize = getChunkSize(N, procRank, procSize);
    size_t chunkOffset = 0;
    for (size_t i = 0; i < procRank; ++i) {
        chunkOffset += getChunkSize(N, i, procSize);
    }
    *mat = new double[N*chunkSize]();
    for (size_t i = 0; i < N*chunkSize; ++i) (*mat)[i] = 1.;
    for (size_t i = 0; i < chunkSize; ++i)
        (*mat)[i + chunkOffset + i*N] = 2.;

    *answer = new double[chunkSize]();
    for(size_t i = 0; i < chunkSize; ++i)
        (*answer)[i] = 1. / (i + 1. + chunkOffset);
}

int main(int argc, char** argv) {
    init(argc, argv);
    size_t N = 2048;
    
    double *mat, *answer;
    getMatrixAndVector(&mat, &answer, N);
    double* result = multMPIMatrixMPIVector(mat, answer, N, N);

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

    // if (procRank == 0) cout << "result:" << endl;
    // for (int proc = 0; proc < procSize; ++proc) {
    //     if (procRank == proc) {
    //         for (size_t i = 0; i < chunkSize; ++i) cout << result[i] << " ";
    //     }
    //     cout.flush();
    //     MPI::COMM_WORLD.Barrier();
    // }
    // if (procRank == 0) cout << endl;

    // if (procRank == 0) cout << "real answer:" << endl;
    // for (int proc = 0; proc < procSize; ++proc) {
    //     if (procRank == proc) {
    //         for (size_t i = 0; i < chunkSize; ++i) cout << answer[i] << " ";
    //     }
    //     cout.flush();
    //     MPI::COMM_WORLD.Barrier();
    // }
    // if (procRank == 0) cout << endl;

    delete[] answer;
    // double* x = slauSolveIteration(mat, result, N);
    // if (procRank == 0) {
    //     cout << "answer:" << endl;
    //     for (size_t i = 0; i < N; ++i) cout << x[i] << " ";
    //     cout << endl;
    // }
    double* x = slauSolveIterationParallelVectors(mat, result, N);
    // size_t chunkSize = getChunkSize(N, procRank, procSize);
    // if (procRank == 0) cout << "answer:" << endl;
    // for (int proc = 0; proc < procSize; ++proc) {
    //     if(procRank == proc) {
    //         for (size_t i = 0; i < chunkSize; ++i) cout << x[i] << " ";
    //     }
    //     cout.flush();
    //     MPI::COMM_WORLD.Barrier();
    // }
    // if (procRank == 0) cout << endl;
    delete[] x;
    delete[] mat;
    delete[] result;
    MPI::Finalize();
    return 0;

}

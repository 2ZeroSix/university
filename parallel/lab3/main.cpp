#include <mpi.h>
#include <algorithm>
#include <iostream>
using namespace std;

int procSize[2] = {0};
int procRank[2] = {0};
MPI::Cartcomm cartcomm;

size_t getChunkSize(size_t realSize, int dim, const int * const rank=procRank) {
    int size = procSize[dim];
    return realSize / size +
            (rank[dim]
             ? (realSize % size > rank[dim] - 1
                ? 1
                : 0)
             : 0);
}

namespace MPI {
    double* multMatrix(double* A, double* B, size_t n1, size_t n2, size_t n3) {
        double* result = new double[getChunkSize(n1, 0) * getChunkSize(n3, 1)]();
        for (int i = 0; i < getChunkSize(n1, 0); ++i) {
            for (int j = 0; j < n2; ++j) {
                for (int k = 0; k < getChunkSize(n3, 1); ++k) {
                    result[i*getChunkSize(n3,1) + k] += A[i*n2 + j] * B[j*getChunkSize(n3, 1) + k];
                }
            }
        }
        return result;
    }
}

void init(int argc, char** argv) {
    MPI::Init(argc, argv);
    MPI::Compute_dims(MPI::COMM_WORLD.Get_size(), 2, procSize);
    bool tmp[2] = {false, false};
    cartcomm = MPI::COMM_WORLD.Create_cart(2, procSize, tmp, true);
    cartcomm.Get_coords(cartcomm.Get_rank(), 2, procRank);
    // for (int p1 = 0; p1 < procSize[0]; ++p1) {
    //     for (int p2 = 0; p2 < procSize[1]; ++p2) {
    //         if (p1 == procRank[0] && p2 == procRank[1])
    //             cout << "rows: " << procRank[0] << "; colons: " << procRank[1] << endl;
    //         cout.flush();
    //         cartcomm.Barrier();
    //     }
    // }
}

void printMatrix(double* C, size_t n1, size_t n3) {
    size_t *rowOffset = new size_t[procSize[0]]();
    for (int p = 1; p < procSize[0]; ++p) {
        int rank[2] = {p, 0};
        rowOffset[p] = rowOffset[p - 1] + getChunkSize(n1, 0, rank); 
    }
    for (int p1 = 0; p1 < procSize[0]; ++p1) {
        for (size_t i = 0; i < n1; ++i) {
            int rank[2] = {p1, 0};
            if (rowOffset[p1] <= i && i < rowOffset[p1] + getChunkSize(n1, 0, rank)) {
                for (int p2 = 0; p2 < procSize[1]; ++p2) {
                    if (p1 == procRank[0] && p2 == procRank[1])
                        for(size_t j = 0; j < getChunkSize(n3, 1); ++j)
                            cout << C[(i - rowOffset[p1])*getChunkSize(n3, 1) + j] << " ";
                    cout.flush();
                    cartcomm.Barrier();
                }
                if (procRank[0] == p1 && procRank[1] == 0) cout << endl;
            } else {
                for (int p2 = 0; p2 < procSize[1]; ++p2) {
                    cout.flush();
                    cartcomm.Barrier();
                }
            }
            cout.flush();
            cartcomm.Barrier();
        }
    }
    delete[] rowOffset;
}

int main(int argc, char** argv) {
    init(argc, argv);
    size_t n1 = 30, n2 = 15, n3 = 15;
    double* A = new double[getChunkSize(n1, 0) * n2]();
    double* B = new double[n2 * getChunkSize(n3, 1)]();

    fill_n(A, getChunkSize(n1, 0) * n2, 1.5);
    fill_n(B, n2 * getChunkSize(n3, 1), 2);

    double* C = MPI::multMatrix(A, B, n1, n2, n3);
    printMatrix(C, n1, n3);

    MPI::Finalize();
    return 0;
} 
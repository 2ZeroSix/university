#include <mpi.h>
#include <algorithm>
#include <iostream>
using namespace std;


namespace MPI {
    int getChunkSize(int realSize, int dim, const Cartcomm& comm_2D) {
        int ranks[2];
        int sizes[2];
        bool tmp[2];
        comm_2D.Get_topo(2, sizes, tmp, ranks);
        int size = sizes[dim];
        int rank = ranks[dim];
        return realSize / size +
                (rank ? (realSize % size > rank - 1 ? 1 : 0) : 0);
    }

    void createTypes(const int *n, Datatype &typeb, Datatype &typec,
                     const int *chunkSizes) {
        Datatype types;
        types = MPI::DOUBLE.Create_vector(n[1], chunkSizes[1], n[2]);
        typeb = types.Create_resized(0, chunkSizes[1] * sizeof(double));
        typeb.Commit();
        types = MPI::DOUBLE.Create_vector(chunkSizes[0], chunkSizes[1], n[2]);
        typec = types.Create_resized(0, chunkSizes[1] * sizeof(double));
        typec.Commit();
    }

    double* multParalleledMatrix(const double* A, const double* B,
                                 const int *n, const int *chunkSizes) {
        double* result = new double[chunkSizes[0] * chunkSizes[1]]();
        for (int i = 0; i < chunkSizes[0]; ++i)
            for (int j = 0; j < n[1]; ++j)
                for (int k = 0; k < chunkSizes[1]; ++k)
                    result[i*chunkSizes[1] + k] += A[i*n[1] + j] * B[j*chunkSizes[1] + k];
        return result;
    }

    void calcSubmatrix(int *dispb, int *countb, int *dispc, int *countc,
                       const int *sizes, const int *chunkSizes) {
        for (int j = 0; j < sizes[1]; j++) {
            dispb[j] = j;
            countb[j] = 1;
        }
        for (int i = 0; i < sizes[0]; i++) {
            for (int j = 0; j < sizes[1]; j++) {
                dispc[i * sizes[1] + j] = (i * sizes[1] * chunkSizes[0] + j);
                countc[i * sizes[1] + j] = 1;
            }
        }
    }

    double* multMatrix(const double* A, const double* B, const int *n) {
        int sizes[2] = {};
        int ranks[2] = {};
        int rank = COMM_WORLD.Get_rank();
        int size = COMM_WORLD.Get_size();
        Compute_dims(size, 2, sizes);

        Cartcomm comm_2D;
        {
            bool tmp[2] = {false, false};
            comm_2D = COMM_WORLD.Create_cart(2, sizes, tmp, true);
        }
        comm_2D.Get_coords(comm_2D.Get_rank(), 2, ranks);

        Intercomm comm_1D[2];
        for(int i = 0; i < 2; i++) {
            bool remains[] = {i == 0, i == 1};
            comm_1D[i] = comm_2D.Sub(remains);
        }

        Datatype typeb, typec;
        int *dispa = NULL, *dispb = NULL, *dispc = NULL,
                *counta = NULL, *countb = NULL, *countc = NULL;

        int chunkSizes[2] = {getChunkSize(n[0], 0, comm_2D),
                            getChunkSize(n[2], 1, comm_2D)};

        if (rank == 0) {
            createTypes(n, typeb, typec, chunkSizes);

            dispa  = new int[sizes[1]];
            counta = new int[sizes[1]];
            dispb  = new int[sizes[1]];
            countb = new int[sizes[1]];
            dispc  = new int[sizes[0] * sizes[1]];
            countc = new int[sizes[0] * sizes[1]];
            calcSubmatrix(/*dispa, counta, */dispb, countb, dispc, countc, sizes, chunkSizes);
        }

        ////+broadcast
        double *subA = new double[chunkSizes[0] * n[1]];
        double *subB = new double[chunkSizes[1] * n[1]];

        if (ranks[1] == 0)
            comm_1D[0].Scatter(A, chunkSizes[0] * n[1], MPI::DOUBLE, subA,
                               chunkSizes[0] * n[1], MPI::DOUBLE, 0);
        if (ranks[0] == 0)
            comm_1D[1].Scatterv(B, countb, dispb, typeb, subB,
                                n[1] * chunkSizes[1], MPI::DOUBLE, 0);

        comm_1D[1].Bcast(subA, chunkSizes[0] * n[1], MPI::DOUBLE, 0);
        comm_1D[0].Bcast(subB, n[1] * chunkSizes[1], MPI::DOUBLE, 0);
        ////-broadcast
        double *subC = multParalleledMatrix(subA, subB, n, chunkSizes);
        ////+gather
        double* C = new double[n[0] * n[2]];
        comm_2D.Gatherv(subC, chunkSizes[0] * chunkSizes[1], MPI::DOUBLE,
                        C, countc, dispc, typec, 0);
        ////-gather
        delete[] dispa;
        delete[] counta;
        delete[] dispb;
        delete[] countb;
        delete[] dispc;
        delete[] countc;
        delete[] subA;
        delete[] subB;
        delete[] subC;
        return C;
    }
}


void printMatrix(double* C, int rows, int colons) {
    for (int row = 0; row < rows; ++row) {
        for (int colon = 0; colon < colons; ++colon)
            cout << C[row * colons + colon] << " ";
        cout << endl;
    }
}

int main(int argc, char** argv) {
    MPI::Init(argc, argv);

    int n[] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
    int rank = MPI::COMM_WORLD.Get_rank();
    if (rank == 0) {
        double *A = new double[n[0] * n[1]]();
        double *B = new double[n[1] * n[2]]();
        fill_n(A, n[0] * n[1], 1.5);
        fill_n(B, n[1] * n[2], 2);

        double start = MPI::Wtime();
        double* C = MPI::multMatrix(A, B, n);
        double final = MPI::Wtime();

        cout << final - start << endl;
        printMatrix(C, n[0], n[2]);
        delete[] A;
        delete[] B;
        delete[] C;
    } else {
        MPI::multMatrix(NULL, NULL, n);
    }

    MPI::Finalize();
    return 0;
}

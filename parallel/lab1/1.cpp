#include <iostream>
#include <mpi.h>
#include <limits>
using namespace std;

double  dotProduct(double*  f, double* s, int size) {
        double res = 0;
        for (int i = 0; i < size; i++)
                res += f[i] * s[i];
        return res;
}

double squareNorm(double* vec, int size) {
        return dotProduct(vec, vec, size);
}

size_t getChunkSize(size_t realSize, int rank, int size) {
    return realSize / size +
            (rank ? (realSize % size > rank - 1 ? 1 : 0) : 0);
}

double* slauSolveIteration(double* matrix,
                                  double* b,
                                  size_t N,
                                  int* recv_counts,
                                  int* displs,
                                  double epsilon = 0.00001,
                                  double tau = 0.01) {
    int procRank = MPI::COMM_WORLD.Get_rank();

    double* x = new double[N]();
    double* part = new double[recv_counts[procRank]];
    double pr_norm;
    double res_norm;

    // computing square of the b norm
    double b_norm;
    if (procRank == 0)
        b_norm = squareNorm(b, N);

    double crit;
    double prevcrit = numeric_limits<double>::max();
    epsilon *= epsilon;
    while (true) {
        pr_norm = 0;

        for (int i = 0; i < recv_counts[procRank]; i++) {
            part[i] = dotProduct(matrix + i * N, x, N) - b[displs[procRank] + i];
            pr_norm += part[i] * part[i];
        }

        // check criterion
        MPI::COMM_WORLD.Reduce(&pr_norm, &res_norm, 1, MPI::DOUBLE, MPI_SUM, 0);
        if (procRank == 0) {
            crit = res_norm / b_norm;
            if      (crit < epsilon)    tau  = 0.0;
            else if (crit > prevcrit)   tau *= 0.1;
            prevcrit = crit;
        }
        MPI::COMM_WORLD.Bcast(&tau, 1, MPI::DOUBLE, 0);
        if (tau == 0.) break;


        for (int i = 0; i < recv_counts[procRank]; i++)
            part[i] = x[displs[procRank] + i] - tau * part[i];

        MPI::COMM_WORLD.Allgatherv(part, recv_counts[procRank], MPI::DOUBLE, x, recv_counts, displs, MPI::DOUBLE);
    }
    delete[] part;
    return x;
}


int main(int argc, char** argv) {
    MPI::Init(argc, argv);

    int procRank = MPI::COMM_WORLD.Get_rank();
    int procSize = MPI::COMM_WORLD.Get_size();

    double start, computing, finish;
    if (procRank == 0) start = MPI::Wtime();

    int N = 4096;

    int* recv_counts = new int[procSize];
    int* displs = new int[procSize];

    // init tables for MPI exchanging
    for (int i = 0; i < procSize; i++) {
        recv_counts[i] = getChunkSize(N, i, procSize);
        displs[i] = (i == 0) ? 0 : displs[i - 1] + recv_counts[i - 1];
    }

    // init matrix
    double* matrix = new double[recv_counts[procRank] * N];
    for (int i = 0; i < recv_counts[procRank]; i++) {
        for (int j = 0; j < N; j++)
            if (displs[procRank] + i == j)
                matrix[i*N + j] = 2;
            else
                matrix[i*N + j] = 1;
    }

    // init result vector
    double* b = new double[N];
    for (int i = 0; i < N; i++)
        b[i] = N + 1;

    if (procRank == 0) computing = MPI::Wtime();

    double* x = slauSolveIteration(matrix, b, N, recv_counts, displs);

    if (procRank == 0) {
        finish = MPI::Wtime();
        std::cout << "Time taken: " << finish - start << "; Only computing: " << finish - computing << std::endl;
    }

    delete[] x;
    delete[] recv_counts;
    delete[] displs;
    delete[] matrix;
    delete[] b;
    MPI::Finalize();
    return 0;
}

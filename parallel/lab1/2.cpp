#include <iostream>
#include <limits>
#include <mpi.h>

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

size_t getChunkSize(size_t realSize, int procRank, int procSize) {
    return realSize / procSize +
            (procRank ? (realSize % procSize > procRank - 1 ? 1 : 0) : 0);
}
size_t maxChunkSize(size_t realSize, int procSize) {
    return realSize / procSize + (realSize % procSize ? 1 : 0);
}

double* slauSolveIteration(double* matrix,
                                  double* b,
                                  size_t N,
                                  int* recv_counts,
                                  int* displs,
                                  double epsilon = 0.00001,
                                  double tau = 0.01) {
    int procRank = MPI::COMM_WORLD.Get_rank();
    int procSize = MPI::COMM_WORLD.Get_size();
    double part_b_norm = 0;
    for (int i = 0; i < recv_counts[procRank]; i++) {
        b[i] = N + 1;
        part_b_norm += (b[i] * b[i]);
    }
    int x_size = maxChunkSize(N, procSize);
    double* x = new double[x_size]();


    double b_norm;
    MPI::COMM_WORLD.Reduce(&part_b_norm, &b_norm, 1, MPI::DOUBLE, MPI::SUM, 0);

    double* pr = new double[recv_counts[procRank]];
    double pr_norm;
    double res_norm;

    int whom_send = (procRank - 1 >= 0) ? procRank - 1 : procSize - 1;
    int fr_wh_recv = (procRank + 1 < procSize) ? procRank + 1 : 0;

    double crit;
    double prevcrit = numeric_limits<double>::max();
    epsilon *= epsilon;
    while (true) {
        pr_norm = 0;

        int xp_size = recv_counts[procRank];

        for (int i = 0; i < procSize; i++) {
            for (int j = 0; j < recv_counts[procRank]; j++)
                pr[j] += dotProduct(matrix + j*N + displs[(procRank + i) % procSize], x, xp_size);

            xp_size = recv_counts[(procRank + i + 1) % procSize];

            if (procSize > 1)
                MPI::COMM_WORLD.Sendrecv_replace(x, x_size, MPI::DOUBLE, whom_send, 0, fr_wh_recv, 0);
        }

        for (int i = 0; i < recv_counts[procRank]; i++)
        {
            pr[i] -=  b[i];
            pr_norm += (pr[i] * pr[i]);
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
        {
            x[i] = x[i] - tau * pr[i];
            pr[i] = 0;
        }
    }
    delete[] pr;
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

    for (int i = 0; i < procSize; i++) {
        recv_counts[i] = getChunkSize(N, i, procSize);
        displs[i] = (i == 0) ? 0 : displs[i - 1] + recv_counts[i - 1];
    }

    double* matrix = new double[recv_counts[procRank] * N];
    for (int i = 0; i < recv_counts[procRank]; i++) {
        for (int j = 0; j < N; j++)
            if (displs[procRank] + i == j)
                matrix[i*N + j] = 2.;
            else
                matrix[i*N + j] = 1.;
    }

 
    double* b = new double[recv_counts[procRank]];
    for (int i = 0; i < recv_counts[procRank]; i++) {
        b[i] = N + 1;
    }

    double* result = 0;
    if (procRank == 0) {
        result = new double[N];
    }

    if (procRank == 0) computing = MPI::Wtime();

    double* x = slauSolveIteration(matrix, b, N, recv_counts, displs);
    MPI::COMM_WORLD.Gatherv(x, recv_counts[procRank], MPI::DOUBLE, result, recv_counts, displs, MPI::DOUBLE, 0);

    if (procRank == 0) {
        finish = MPI::Wtime();
        std::cout << "Time taken: " << finish - start << "; Only computing: " << finish - computing << std::endl;
    }

    delete[] x;
    delete[] recv_counts;
    delete[] displs;
    delete[] matrix;
    delete[] b;
    delete[] result;

    MPI::Finalize();
    return 0;
}

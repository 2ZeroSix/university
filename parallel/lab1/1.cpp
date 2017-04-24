#include <iostream>
#include <cmath>
#include <mpi.h>
#include <cstdlib>

//скалярное произведение векторов
double  mul_v(double*  f, double* s, int size)
{
        double res = 0;

        for (int i = 0; i < size; i++)
                res += f[i] * s[i];
        return res;
}


//норма вектора
double squareNorm(double* vec, int size)
{
        double res = 0;

        for (int i = 0; i < size; i++)
                res += vec[i] * vec[i];

        return res;
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
    int procSize = MPI::COMM_WORLD.Get_size();

    double* x = new double[N]();
    //инициализация части вычислений для каждого процесса и значения нормы res_norm для 0 процесса
    double* pr = new double[recv_counts[procRank]];;
    double pr_norm;
    double res_norm;

    //для 0 процесса вычисляем норму b
    double b_norm;
    if (procRank == 0)
        b_norm = squareNorm(b, N);

    int check = 0;
    double crit;
    double prevcrit = 99999999999999999999999999999;
    epsilon = epsilon*epsilon;
    while (true) {
        pr_norm = 0;

        for (int i = 0; i < recv_counts[procRank]; i++) {
            pr[i] = mul_v(matrix + i * N, x, N) - b[displs[procRank] + i];
            pr_norm += pr[i] * pr[i];
        }

        MPI::COMM_WORLD.Reduce(&pr_norm, &res_norm, 1, MPI_DOUBLE, MPI_SUM, 0);

        if (procRank == 0 && (crit = res_norm / b_norm) < epsilon) check = 1;
        MPI::COMM_WORLD.Bcast(&check, 1, MPI::INT, 0);

        if (check == 1)         break;
        if (crit > prevcrit)    tau *= 0.1;
        prevcrit = crit;
        for (int i = 0; i < recv_counts[procRank]; i++)
            pr[i] = x[displs[procRank] + i] - tau * pr[i];

        MPI::COMM_WORLD.Allgatherv(pr, recv_counts[procRank], MPI::DOUBLE, x, recv_counts, displs, MPI::DOUBLE);
    }
    return x;
}


int main(int argc, char** argv) {
    MPI::Init(argc, argv);

    int procRank = MPI::COMM_WORLD.Get_rank();
    int procSize = MPI::COMM_WORLD.Get_size();
    //размер матрицы
    int N = 4096;


    double start, finish;

    if (procRank == 0)
        start = MPI::Wtime();

    int* recv_counts = new int[procSize];
    int* displs = new int[procSize];

    for (int i = 0; i < procSize; i++) {
        recv_counts[i] = getChunkSize(N, i, procSize);
        displs[i] = (i == 0) ? 0 : displs[i - 1] + recv_counts[i - 1];
    }

    //инициализация части матрицы для данного процесса, далее инициализация вектора b и начального значения вектора x
    double* matrix = new double[recv_counts[procRank] * N];
    for (int i = 0; i < recv_counts[procRank]; i++) {
        for (int j = 0; j < N; j++)
            if (displs[procRank] + i == j)
                matrix[i*N + j] = 2;
            else
                matrix[i*N + j] = 1;
    }

    double* b = new double[N];
    for (int i = 0; i < N; i++)
        b[i] = N + 1;

    double* x = slauSolveIteration(matrix, b, N, recv_counts, displs);

    if (procRank == 0) {
        finish = MPI_Wtime();
        std::cout << "Time taken: " << finish - start << std::endl;
    }

    MPI::Finalize();
    return 0;
}

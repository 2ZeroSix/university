#include <vector>
#include <iostream>
#include <cmath>
#include <mpi.h>
#include <cstdlib>
#include <cstring>


//скалярное произведение векторов
double  mul_v(double*  f, double* s, int size)
{
        double res = 0;

        for (int i = 0; i < size; i++)
                res += f[i] * s[i];
        return res;
}



int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //размер матрицы
    int N = 32000;

    //массивы количества обрабатываемых элементов и смещений по строке матрицы
        int* recv_counts = (int*)malloc(sizeof(int) * size);
        int* displs = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++)
        {
                recv_counts[i] = N / size + ((i < (N % size)) ? 1 : 0);
                displs[i] = (i == 0) ? 0 : displs[i - 1] + recv_counts[i - 1];
        }

    //инициализация части матрицы для данного процесса, далее инициализация частей вектора b и начального значения вектора x
    double** matrix = (double**)malloc(sizeof(double*) * recv_counts[rank]);
    for (int i = 0; i < recv_counts[rank]; i++)
    {
        matrix[i] = (double*)malloc(sizeof(double) * N);
        for (int j = 0; j < N; j++)
            if (displs[rank] + i  == j)
                matrix[i][j] = 2;
            else
                matrix[i][j] = 1;
    }

    //максимальный размер х для пересылки между процессами, выделение памяти для части b, подсчет куска для нормы b
    int x_size = N / size + ((N % size > 0) ? 1 : 0);
    double* x = (double*)calloc(x_size, sizeof(double));

    double* b = (double*)malloc(sizeof(double) * recv_counts[rank]);
    double b_val = 0;
    for (int i = 0; i < recv_counts[rank]; i++)
    {
        b[i] = N + 1;
        b_val += (b[i] * b[i]);
    }

    //нужно собрать норму вектора b в нулевом процессе
    double res_b_val;
    MPI_Reduce(&b_val, &res_b_val, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    //инициализация мессива, в который в конце соберем решение
    double* result;
        if (rank == 0)
    {
            result = (double*)malloc(sizeof(double) * N);
        res_b_val = sqrt(res_b_val);
    }
    //инициализация части вычислений для каждого процесса, части ее нормы, а так же будущей суммы этих норм
    double* pr = (double*)calloc(recv_counts[rank], sizeof(double));
    double pr_val;
    double res_val;

    //для выхода с помощью Bcast
    int check = 0;

    //вычисляем, кому будем отправлять кусочек x, от кого получать
    int whom_send = (rank - 1 >= 0) ? rank - 1 : size - 1;
        int fr_wh_recv = (rank + 1 < size) ? rank + 1 : 0;

    while (true)
    {
        pr_val = 0;

        int xp_size = recv_counts[rank];

        for (int i = 0; i < size; i++)
        {
            //получив новый кусочек x, перемножаем его с частью матрицы для всех доступных строк
            for (int j = 0; j < recv_counts[rank]; j++)
                pr[j] += mul_v(matrix[j] + displs[(rank + i) % size], x, xp_size);

            xp_size = recv_counts[(rank + i + 1) % size];

            if (size > 1)
                MPI_Sendrecv_replace(x, x_size, MPI_DOUBLE, whom_send, 2, fr_wh_recv, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        //довычисляем pr для подсчета нормы, считаем часть норм
        for (int i = 0; i < recv_counts[rank]; i++)
        {
            pr[i] -=  b[i];
            pr_val += (pr[i] * pr[i]);
        }

        MPI_Reduce(&pr_val, &res_val, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        if (rank == 0 && sqrt(res_val) / res_b_val < 1.0/1000000000)
            check = 1;

        MPI_Bcast(&check, 1, MPI_INT, 0, MPI_COMM_WORLD);
        if (check == 1)
            break;

        for (int i = 0; i < recv_counts[rank]; i++)
        {
            x[i] = x[i] - 0.00001 * pr[i];
            pr[i] = 0;
        }
    }

    MPI_Gatherv(x, recv_counts[rank], MPI_DOUBLE, result, recv_counts, displs, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0)
        std::cout << "result[0]=" << result[0] << std::endl;

    MPI_Finalize();
    return 0;
}

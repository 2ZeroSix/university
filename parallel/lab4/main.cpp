#include <iostream>
#include <cmath>
#include <mpi.h>
using namespace std;
double fi(double x, double y, double z) {
    return x*x + y*y + z*z;
}

double Ro(double x, double y, double z) {
    double a = 1.0 / 100000;
    return 6 - a*fi(x, y, z);
}

double coord(double j) {
    return (j * 0.04 - 1);
}

double maxF(double* Field, double* previous, int x, int y, int z) {
    double max = 0;
    for (int i = 1; i < z; i++)
        for (int j = 0; j < x; j++)
            for (int k = 0; k < y; k++)
                max = std::max(max, abs(Field[(i*x + j) * y + k]
                                   - previous[(i*x + j) * y + k]));
    return max;
}

double tm(double* Field, int x, int y, int z, int disp)
{
    double max = 0;
    for (int i = 1; i < z; i++)
        for (int j = 0; j < x; j++)
            for (int k = 0; k < y; k++)
                max = std::max(max, abs(Field[(i*x + j) * y + k]
                               - fi(coord(j), coord(k), coord(disp + i - 1))));
    return max;
}

double solvePoisson(double (*fi)(double, double, double),
                    double(*ro)(double, double, double)) {
    int rank = MPI::COMM_WORLD.Get_rank();
    int size = MPI::COMM_WORLD.Get_size();

    //дробление пространства
    int xN = 50 + 1;
    int yN = 50 + 1;
    int zN = 50 + 1;


    //смещения
    double hx = 2.0 / (xN - 1);
    double hy = 2.0 / (yN - 1);
    double hz = 2.0 / (zN - 1);
    //квадраты долей пространства для вычисления формулы
    double shx = hx * hx;
    double shy = hy * hy;
    double shz = hz * hz;

    double divider = 2.0 / shx + 2.0 / shy + 2.0 / shz + 1.0 / 100000;

    int* displs = new int[size];
    int* count  = new int[size];

    for (int i = 0; i < size; i++) {
        count[i] = zN / size + ((zN % size > i)? 1 : 0)
                   + ((i == 0 || i == size - 1) ? 1 : 2);
        displs[i] = (i == 0) ? 0 : displs[i - 1] - 2 + count[i - 1];
    }

    int disp = displs[rank] + 1;
    int last = count[rank];

    double *part[2];
    part[0] = new double[last * xN * yN]();
    part[1] = new double[last * xN * yN]();

    for (int i = 0; i < last; i++) {
        for (int j = 0; j < xN; j++) {
            for (int k = 0; k < yN; k++) {
                if (i + disp - 1 == 0
                    || j == 0
                    || k == 0
                    || i + disp == zN
                    || j == xN - 1
                    || k == yN - 1)
                    part[0][(i* xN + j) * yN + k] = fi(coord(j), coord(k),
                                                       coord(i + disp - 1));
                else
                    part[0][(i * xN + j) * yN + k] = 0;
                part[1][(i * xN + j) * yN + k] = part[0][(i * xN + j) * yN + k];
            }
        }
    }
    MPI::Request sendr1, sendr2, recvr1, recvr2;

    double maxInPart = 0;
    double max;

    double fx, fy, fz;

    int l1 = 0;
    int l2 = 1;

    while (true) {

        //обсчет краев в каждом процессе
        for (int x = 1; x < xN - 1; x++)
            for (int y = 1; y < yN - 1; y++) {
                if (disp + 1 == zN)
                    break;
                fz = (part[l1][(2*xN + x) * yN + y]
                      + part[l1][x*yN + y]) / shz;
                fx = (part[l1][(xN + x + 1) * yN + y]
                      + part[l1][(xN + x - 1) * yN + y]) / shx;
                fy = (part[l1][(xN + x) * yN + y + 1]
                      + part[l1][(xN + x) * yN + y - 1]) / shy;
                part[l2][(xN + x) * yN + y]
                        = (fz + fx + fy
                           - ro(coord(x), coord(y), coord(disp))) / divider;

                if (disp != last + disp - 3) {
                    fz = (part[l1][((last - 1)*xN + x) * yN + y]
                          + part[l1][((last - 3) * xN + x)*yN + y]) / shz;
                    fx = (part[l1][((last - 2) * xN + x + 1) * yN + y]
                          + part[l1][((last - 2) * xN + x - 1) * yN + y]) / shx;
                    fy = (part[l1][((last - 2) * xN + x) * yN + y + 1]
                          + part[l1][((last - 2) * xN + x) * yN + y - 1]) / shy;
                    part[l2][((last - 2) * xN + x) * yN + y]
                            = (fz + fx + fy - 
                            ro(coord(x), coord(y), coord(last + disp - 3))) / divider;
                }
            }

        //отправка краев
        if (rank != 0)
            sendr1 = MPI::COMM_WORLD.Isend(&part[l2][xN * yN],
                                           xN * yN, MPI::DOUBLE, rank - 1 , 2);
        if (rank != size - 1) {
            recvr1 = MPI::COMM_WORLD.Irecv(&part[l2][(last - 1) * xN * yN],
                                           xN * yN, MPI::DOUBLE, rank + 1, 2);
            sendr2 = MPI::COMM_WORLD.Isend(&part[l2][(last - 2) * xN * yN],
                                           xN * yN, MPI::DOUBLE, rank + 1, 3);
        }
        if (rank != 0)
            recvr2 = MPI::COMM_WORLD.Irecv(&part[l2][0],
                                           xN * yN, MPI::DOUBLE, rank - 1, 3);

        //обсчет от 2-го до последнего пластов в каждом процессе
        for (int z = 2; z < last - 2; z++)
            for (int x = 1; x < xN - 1; x++)
                for (int y = 1; y < yN - 1; y++) {
                    fz = (part[l1][((z + 1)*xN + x) * yN + y]
                          + part[l1][((z - 1) * xN + x) * yN + y]) / shz;
                    fx = (part[l1][(z * xN + x + 1) * yN + y]
                          + part[l1][(z * xN + x - 1) * yN + y]) / shx;
                    fy = (part[l1][(z * xN + x) * yN + y + 1]
                          + part[l1][(z * xN + x) * yN + y - 1]) / shy;
                    part[l2][(z * xN + x) * yN + y]
                            = (fz + fx + fy
                               - ro(coord(x), coord(y), coord(disp))) / divider;
                }
        if (rank != 0)
            sendr1.Wait();
        if (rank != size -1) {
            recvr1.Wait();
            sendr2.Wait();
        }
        if (rank != 0)
            recvr2.Wait();

        MPI::COMM_WORLD.Barrier();

        maxInPart = maxF(part[l2], part[l1], xN, yN, last - 1);
        MPI::COMM_WORLD.Allreduce(&maxInPart, &max, 1, MPI::DOUBLE, MPI::MAX);

//        if (rank == 0)
//            std::cout << "Max = " << max << std::endl;
        if (max < 0.00000001)
            break;

        l1 = 1 - l1;
        l2 = 1 - l2;
    }

    //подсчет возвращаемового значения
    maxInPart = tm(part[l2], xN, yN, last - 1, disp);
    MPI::COMM_WORLD.Reduce(&maxInPart, &max, 1, MPI::DOUBLE, MPI::MAX, 0);
    delete[] part[0];
    delete[] part[1];
    return max;
}

int main(int argc, char* argv[]) {
    MPI::Init(argc, argv);
    int rank = MPI::COMM_WORLD.Get_rank();
    double start, finish;

    if (rank == 0) start = MPI_Wtime();
    double max = solvePoisson(fi, Ro);
    if (rank == 0) {
        finish = MPI_Wtime();
        std::cout << finish - start << std::endl;
//        std::cout << "Result : " << max << std::endl;
    }

    MPI::Finalize();
    return 0;
}

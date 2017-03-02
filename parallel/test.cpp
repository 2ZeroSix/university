#include <mpi.h>
#include <iostream>
#include <cstddef>

using namespace std;

#define N 100
int main(int argc, char** argv) {
    MPI::Init(argc, argv);


    int size, rank;
    size = MPI::COMM_WORLD.Get_size();
    rank = MPI::COMM_WORLD.Get_rank();
    cout << "Hello from process #" << rank << " of " << size << endl;
    size_t vecLen = N/size + (!rank?N%size:0);
    double* v0 = new double[vecLen];
    double* v1 = new double[vecLen];
    for(size_t i = 0; i < vecLen; ++i) {
        v0[i] = 1;
        v1[i] = 2;
    }
    double ls = 0;

    for(size_t i = 0; i < vecLen; ++i) {
        ls+=v0[i]*v1[i];
    }
    if(!rank) {
        printf("receiving\n");
        double sum = ls;
        for( int proc = 1; proc < size; ++proc) {
            MPI::COMM_WORLD.Recv(&ls, 1, MPI::DOUBLE, proc, 0);
            sum += ls;
        }
        printf("sum == %lf\n", sum);
    } else {
        printf("sending\n");
        MPI::COMM_WORLD.Send(&ls, 1, MPI::DOUBLE, 0, 0);
        printf("sended\n");
    }

    MPI::Finalize();
    return 0;
}
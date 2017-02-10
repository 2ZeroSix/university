#include <mpi.h>
#include <iostream>


using namespace std;


int main(int argc, char** argv) {
    MPI::Init(argc, argv);


    int size, rank;
    size = MPI::COMM_WORLD.Get_size();
    rank = MPI::COMM_WORLD.Get_rank();
    cout << "Hello from process #" << rank << " of " << size << endl;


    MPI::Finalize();
    return 0;
}
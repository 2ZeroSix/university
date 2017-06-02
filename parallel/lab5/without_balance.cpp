#include <mpi.h>
#include <iostream>
#include <cmath>
#include <queue>

typedef struct Task {
    double start_value;
    size_t iterations;
} Task;

double solveTask(const Task& task) {
    double result = task.start_value;
    for (size_t i = 0; i < task.iterations; ++i)
        result = sqrt(result * result);
    return result;
}

std::size_t getTasksCount(std::size_t shift) {
    std::size_t total = 160;
    std::size_t add_weight = total / 10;
    std::size_t size = (std::size_t)MPI::COMM_WORLD.Get_size();
    std::size_t rank = ((std::size_t)MPI::COMM_WORLD.Get_rank() + shift) % size;
    return (total / size) + (total % size == rank ? total % size: 0)
           + (total % size == rank ? add_weight : 0);
}

bool getTasks(std::queue<Task> &tasks) {
    static std::size_t iteration = 0;
//    std::cout << MPI::COMM_WORLD.Get_rank() << ":" << iteration << std::endl;
    static std::size_t total = 23;
    MPI::COMM_WORLD.Barrier();
    if (iteration < total) {
        ++iteration;
        std::queue<Task> queue;
        for (std::size_t i = 0; i < getTasksCount(iteration); ++i) {
            Task task = {0.987654321 / (1 + iteration), 100000 * (1 + iteration % total)};
            queue.push(task);
        }
        tasks = queue;
        return true;
    } else {
        return false;
    }
}

double worker() {
    std::queue <Task> tasks;
    double result = 0;
    while (getTasks(tasks))
        while (!tasks.empty()) {
            result += solveTask(tasks.front());
            tasks.pop();

        }
    return result;
}

int main(int argc, char *argv[]) {
    int provided;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_SINGLE, &provided);
    if (provided < MPI_THREAD_SINGLE) {
        std::cout << "wrong level provided" << std::endl;
        return 1;
    }

    double start = MPI_Wtime();
    double sub_result = worker();
    double end = MPI_Wtime();
    double sub_time = end - start;
    int proc_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &proc_rank);
    if (proc_rank == 0) {
        int proc_size;
        MPI_Comm_size(MPI_COMM_WORLD, &proc_size);
        double time;
        double result;
        MPI_Reduce(&sub_result, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("%6.6lf, ", result);
        MPI_Reduce(&sub_time, &time, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("%6.6lf, ", time);
        MPI_Reduce(&sub_time, &time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
        printf("%6.6lf\n", time);
    } else {
        MPI_Reduce(&sub_result, NULL, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
        MPI_Reduce(&sub_time, NULL, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
        MPI_Reduce(&sub_time, NULL, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}

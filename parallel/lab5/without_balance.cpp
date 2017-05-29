#include <iostream>
#include <valarray>
#include <iterator>
#include <queue>
#include <mpi.h>

struct Task {
    double start_value;
    std::size_t iterations;
};

double solveTask(const Task &task) {
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
    std::cout << MPI::COMM_WORLD.Get_rank() << ":" << iteration << std::endl;
    static std::size_t total = 3;
    MPI::COMM_WORLD.Barrier();
    if (iteration < total) {
        ++iteration;
        std::queue<Task> queue;
        for (std::size_t i = 0; i < getTasksCount(iteration); ++i) {
            Task task = {.start_value = 0.987654321 / (1 + iteration),
                         .iterations = 10000 * (1 + iteration % total)};
            queue.push(task);
        }
        tasks = queue;
        return true;
    } else {
        return false;
    }
}

double worker() {
    std::queue<Task> tasks;
    double result = 0;
    while (getTasks(tasks))
        while (!tasks.empty()) {
            result += solveTask(tasks.front());
            tasks.pop();

        }
    return result;
}

int main(int argc, char *argv[]) {
    int provided = MPI::Init_thread(MPI::THREAD_SINGLE);
    if (provided < MPI::THREAD_SINGLE) {
        std::cout << "wrong level provided" << std::endl;
        return 1;
    }

    double start = MPI::Wtime();
    double sub_result = worker();
    double end = MPI::Wtime();
    double sub_time = end - start;
    if (MPI::COMM_WORLD.Get_rank() == 0) {
        int proc_size = MPI::COMM_WORLD.Get_size();
        double *time = new double[proc_size];
        double result;
        MPI::COMM_WORLD.Reduce(&sub_result, &result, 1, MPI::DOUBLE, MPI::SUM, 0);
        MPI::COMM_WORLD.Gather(&sub_time, 1, MPI::DOUBLE, time, 1, MPI::DOUBLE, 0);
        std::cout << result << ", ";
        std::valarray<double> time_vals = std::valarray<double>(time, (std::size_t)proc_size);
        std::cout << time_vals.sum() << ", ";
        std::cout << time_vals.max() << std::endl;
    }
    else {
        MPI::COMM_WORLD.Reduce(&sub_result, NULL, 1, MPI::DOUBLE, MPI::SUM, 0);
        MPI::COMM_WORLD.Gather(&sub_time, 1, MPI::DOUBLE, NULL, 1, MPI::DOUBLE, 0);
    }

    MPI::Finalize();
}

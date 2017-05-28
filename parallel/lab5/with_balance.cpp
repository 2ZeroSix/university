#include <iostream>
#include <valarray>
#include <iterator>
#include <queue>
#include <pthread.h>
#include <openmpi/ompi/mpi/cxx/mpicxx.h>

struct Task {
    double start_value;
    long iterations;
};

class Tasks{
private:
    std::queue<Task> tasks;
    pthread_mutex_t mutex;
    pthread_mutex_t balance;
    pthread_mutex_t stop_balance;
    pthread_t receiver_thread;
    MPI::Datatype task_info;
    std::size_t getTasksCount(std::size_t shift) const {
        std::size_t total = 100000;
        std::size_t add_weight = total / 10;
        std::size_t size = (std::size_t)MPI::COMM_WORLD.Get_size();
        std::size_t rank = ((std::size_t)MPI::COMM_WORLD.Get_rank() + shift) % size;
        return (total / size) + (total % size == rank ? total % size: 0)
               + (total % size == rank ? add_weight : 0);
    }

    bool getTasks() {
        static std::size_t iteration = 0;
        static std::size_t total = 23;
        std::cout << iteration << std::endl;
        if (iteration < total) {
            ++iteration;
            std::queue<Task> queue;
            for (std::size_t i = 0; i < getTasksCount(iteration); ++i) {
                Task task = {.start_value = 0.987654321 / (1 + iteration),
                        .iterations = 100 * (1 + iteration % total)};
                queue.push(task);
            }
            tasks = queue;
            return true;
        } else {
            return false;
        }
    }

    void* receiver(void *) {
        int size = MPI::COMM_WORLD.Get_size();
        int rank = MPI::COMM_WORLD.Get_rank();
        int* have_tasks = new int[size];
        pthread_mutex_lock(&balance);
        while(getTasks()) {
            for (int i = 1; i < size; ++i) {
                int from = (rank + i) % ranksNum;
                int code = 1;
                MPI::COMM_WORLD.Send(&code, 1, MPI::INT, from, 1);
                MPI::COMM_WORLD.Recv(&code, 1, MPI::INT, from, 2);
                if (code == 0) {
                    continue;
                }
                Task task;
                MPI::COMM_WORLD.Recv(&task, 1, task_info, from, 3);
                push(task);

                pthread_mutex_unlock(&balance);
                pthread_mutex_lock(&balance);
            }
        }
        pthread_mutex_unlock(&balance);
        return NULL;
    }
public:
    Tasks() {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        pthread_create(&receiver_thread, &attrs, balancer, &Tasks);
        pthread_attr_destroy(&attr);
        pthread_mutex_init(&mutex, NULL);
        MPI::Datatype parts[] = {MPI::DOUBLE, MPI::LONG};
        int block_lengths[] = {1, 1};
        MPI::Aint displacements[] = {0, sizeof(double)};
        task_info = MPI::Datatype::Create_struct(2, block_lengths, displacements, parts);
        task_info.Commit();
    }
    bool empty() const {
        pthread_mutex_lock(&mutex);
        if (tasks.empty()) {
            pthread_mutex_unlock(&mutex);
            pthread_mutex_lock(&balance);
            pthread_mutex_unlock(&balance);
            pthread_mutex_lock(&mutex);
        }
        if (tasks.empty()) {
            if (!(result = getTasks())) {
                pthread_mutex_lock(&stop_balance);
            }
        }
        pthread_mutex_unlock(&mutex);
        return result;
    }
    std::size_t size() const {
        pthread_mutex_lock(&mutex);
        std::size_t result = tasks.size();
        pthread_mutex_unlock(&mutex);
        return result;
    }
    Task pop() {
        pthread_mutex_lock(&mutex);
        Task result = tasks.front();
        tasks.pop();
        pthread_mutex_unlock(&mutex);
        return result;
    }
    void push(const Task& task) {
        pthread_mutex_lock(&mutex);
        tasks.push(task);
        pthread_mutex_unlock(&mutex);
    }
    ~Tasks() {
        pthread_mutex_destroy(&mutex);
        pthread_mutex_destroy(&balance);
        pthread_mutex_destroy(&stop_balance);
        pthread_join(receiver_thread, NULL);
    }
};

double solveTask(const Task &task) {
    double result = task.start_value;
    for (size_t i = 0; i < task.iterations; ++i)
        result = sqrt(result * result);
    return result;
}

double worker() {
    Tasks tasks;
    double result = 0;
    while (!tasks.empty())
        result += solveTask(tasks.pop());
    return result;
}


int main(int argc, char *argv[]) {
    int provided = MPI::Init_thread(MPI::THREAD_MULTIPLE);
    if (provided < MPI::THREAD_MULTIPLE) {
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
    }
    else {
        MPI::COMM_WORLD.Reduce(&sub_result, NULL, 1, MPI::DOUBLE, MPI::SUM, 0);
        MPI::COMM_WORLD.Gather(&sub_time, 1, MPI::DOUBLE, NULL, 1, MPI::DOUBLE, 0);
    }

    MPI::Finalize();
}

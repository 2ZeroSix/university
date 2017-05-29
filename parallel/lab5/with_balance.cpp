#include <iostream>
#include <valarray>
#include <iterator>
#include <queue>
#include <mpi.h>
#include <pthread.h>

struct Task {
    double start_value;
    long iterations;
};

class Tasks{
private:
    std::queue<Task> tasks;
    pthread_mutex_t main_mutex;
    pthread_mutex_t empty_mutex;
    pthread_cond_t need_new_task;
    pthread_mutex_t need_new_task_mutex;
    pthread_cond_t new_task;
    pthread_mutex_t new_task_mutex;
    pthread_t receiver_thread;
    pthread_t sender_thread;
    std::size_t count;
    std::size_t full_count;
    bool is_empty;
    bool empty_without_lock() {
        pthread_mutex_lock(&empty_mutex);
        bool result = is_empty;
        if (!is_empty) {
            if ((result = !count)) {
                pthread_mutex_lock(&need_new_task_mutex);
                pthread_cond_broadcast(&need_new_task);
                pthread_mutex_unlock(&need_new_task_mutex);
                pthread_cond_wait(&new_task, &new_task_mutex);
                result = !count;
            } else if (count <= 1 + full_count / 10) {
                pthread_mutex_lock(&need_new_task_mutex);
                pthread_cond_broadcast(&need_new_task);
                pthread_mutex_unlock(&need_new_task_mutex);
                pthread_cond_wait(&new_task, &new_task_mutex);
            }
            is_empty = result;
        }
        pthread_mutex_unlock(&empty_mutex);
        return result;
    }

    static MPI::Datatype getTaskInfo() {
        static MPI::Datatype task_info;
        static bool check = false;
        if (!check) {
            MPI::Datatype parts[] = {MPI::DOUBLE, MPI::LONG};
            int block_lengths[] = {1, 1};
            MPI::Aint displacements[] = {0, sizeof(double)};
            task_info = MPI::Datatype::Create_struct(2, block_lengths, displacements, parts);
            task_info.Commit();
        }
        return task_info;
    }

    static std::size_t getTasksCount(std::size_t shift) {
        std::size_t total = 160;
        std::size_t add_weight = total / 10;
        std::size_t size = (std::size_t)MPI::COMM_WORLD.Get_size();
        std::size_t rank = ((std::size_t)MPI::COMM_WORLD.Get_rank() + shift) % size;
        return (total / size) + (total % size == rank ? total % size: 0)
               + (total % size == rank ? add_weight : 0);
    }

    bool getTasks() {
        static std::size_t iteration = 0;
        static std::size_t total = 23;
//        std::cout << MPI::COMM_WORLD.Get_rank() << ":" << iteration << std::endl;
        if (iteration < total) {
            ++iteration;
            std::queue<Task> queue;
            std::size_t count =  getTasksCount(iteration);
            for (std::size_t i = 0; i < count; ++i) {
                Task task = {0.987654321 / (1 + iteration), 100000 * (1 + iteration % total)};
                queue.push(task);
            }
            pthread_mutex_lock(&main_mutex);
            this->count = count;
            this->full_count = count;
            tasks = queue;
            pthread_mutex_unlock(&main_mutex);
            return true;
        } else {
            return false;
        }
    }

    static void* receiver(void* tasks_p) {
        Tasks& tasks = *(Tasks*)tasks_p;
        int size = MPI::COMM_WORLD.Get_size();
        int rank = MPI::COMM_WORLD.Get_rank();
//        std::cout << MPI::COMM_WORLD.Get_rank() << ":"  << "receiver started" << std::endl;
        pthread_cond_wait(&tasks.need_new_task, &tasks.need_new_task_mutex);
        while(tasks.getTasks()) {
            pthread_mutex_lock(&tasks.new_task_mutex);
            pthread_cond_broadcast(&tasks.new_task);
            pthread_mutex_unlock(&tasks.new_task_mutex);
            pthread_cond_wait(&tasks.need_new_task, &tasks.need_new_task_mutex);
            int str = 0;
            for (int i = 1; i < size; ++i) {
//                pthread_mutex_lock(&tasks.need_new_task_mutex);
//                pthread_mutex_unlock(&tasks.need_new_task_mutex);
                int from = (rank + i) % size;
                int code = 1;
                MPI::COMM_WORLD.Send(&code, 1, MPI::INT, from, 1);
                MPI::COMM_WORLD.Recv(&code, 1, MPI::INT, from, 2);
                if (code == 0) {
                    continue;
                } else {
                    --i;
                }
                Task task;
                MPI::COMM_WORLD.Recv(&task, 1, getTaskInfo(), from, 3);
                tasks.push(task);
                pthread_mutex_lock(&tasks.new_task_mutex);
                pthread_cond_broadcast(&tasks.new_task);
                pthread_mutex_unlock(&tasks.new_task_mutex);
                pthread_cond_wait(&tasks.need_new_task, &tasks.need_new_task_mutex);
            }
            while (tasks.count) {
                pthread_mutex_lock(&tasks.new_task_mutex);
                pthread_cond_broadcast(&tasks.new_task);
                pthread_mutex_unlock(&tasks.new_task_mutex);
                pthread_cond_wait(&tasks.need_new_task, &tasks.need_new_task_mutex);
//                pthread_mutex_lock(&tasks.need_new_task_mutex);
//                pthread_mutex_unlock(&tasks.need_new_task_mutex);
            }
            MPI::COMM_WORLD.Barrier();
        }
        pthread_mutex_lock(&tasks.new_task_mutex);
        pthread_cond_broadcast(&tasks.new_task);
        pthread_mutex_unlock(&tasks.new_task_mutex);
        int code = 0;
        MPI::COMM_WORLD.Send(&code, 1, MPI::INT, MPI::COMM_WORLD.Get_rank(), 1);
//        pthread_mutex_lock(&tasks.need_new_task_mutex);
        while (!tasks.is_empty) {
            pthread_cond_wait(&tasks.need_new_task, &tasks.need_new_task_mutex);
            pthread_mutex_lock(&tasks.new_task_mutex);
            pthread_cond_broadcast(&tasks.new_task);
            pthread_mutex_unlock(&tasks.new_task_mutex);
        }
//        pthread_mutex_unlock(&tasks.need_new_task_mutex);
//        std::cout << MPI::COMM_WORLD.Get_rank() << ":"  << "receiver finalized" << std::endl;
        pthread_mutex_unlock(&tasks.need_new_task_mutex);
        return NULL;
    }
    static void* sender(void* tasks_p) {
        Tasks& tasks = *(Tasks*)tasks_p;
        int size = MPI::COMM_WORLD.Get_size();
        int rank = MPI::COMM_WORLD.Get_rank();
//        std::cout  << MPI::COMM_WORLD.Get_rank() << ":" << "sender started" << std::endl;
        while(true) {
            MPI::Status status;
            int code;
            int str = 0;
            MPI::COMM_WORLD.Probe(MPI::ANY_SOURCE, 1, status);
            int proc = status.Get_source();
            MPI::COMM_WORLD.Recv(&code, 1, MPI::INT, proc, 1, status);
            if (code == 0)
                break;

            if (!tasks.count) {
                code = 0;
                MPI::COMM_WORLD.Send(&code, 1, MPI::INT, proc, 2);
            } else {
                pthread_mutex_lock(&tasks.main_mutex);
                Task task = tasks.tasks.front();
                tasks.tasks.pop();
                --tasks.count;
                pthread_mutex_unlock(&tasks.main_mutex);

                MPI::COMM_WORLD.Send(&code, 1, MPI::INT, proc, 2);
                MPI::COMM_WORLD.Send(&task, 1, getTaskInfo(), proc, 3);
            }
        }
//        std::cout << MPI::COMM_WORLD.Get_rank() << ":"  << "sender finalized" << std::endl;
        return NULL;
    }
public:
    Tasks() {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        need_new_task_mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_lock(&need_new_task_mutex);
        need_new_task = PTHREAD_COND_INITIALIZER;
        pthread_mutex_lock(&new_task_mutex);
        new_task_mutex = PTHREAD_MUTEX_INITIALIZER;
        new_task = PTHREAD_COND_INITIALIZER;
        count = 0;
        full_count = 0;
        main_mutex = PTHREAD_MUTEX_INITIALIZER;
        empty_mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_attr_destroy(&attr);
        is_empty = false;
        pthread_create(&receiver_thread, &attr, Tasks::receiver, this);
        pthread_create(&sender_thread, &attr, Tasks::sender, this);
    }

    bool pop(Task& task) {
//        std::cout << "pop" << std::endl;
        if (empty_without_lock()) {
//            std::cout << "~pop" << std::endl;
            return false;
        } else {
            pthread_mutex_lock(&main_mutex);
            --count;
            task = tasks.front();
            tasks.pop();
//            std::cout << "~pop" << std::endl;
            pthread_mutex_unlock(&main_mutex);
            return true;
        }
    }
    void push(const Task& task) {
        pthread_mutex_lock(&main_mutex);
        ++count;
        tasks.push(task);
        pthread_mutex_unlock(&main_mutex);
    }
    ~Tasks() {
//        std::cout << "~Tasks" << std::endl;
        pthread_mutex_unlock(&new_task_mutex);
        pthread_join(receiver_thread, NULL);
        pthread_join(sender_thread, NULL);
        pthread_cond_destroy(&new_task);
        pthread_cond_destroy(&need_new_task);
        pthread_mutex_destroy(&main_mutex);
        pthread_mutex_destroy(&empty_mutex);
        pthread_mutex_destroy(&new_task_mutex);
        pthread_mutex_destroy(&need_new_task_mutex);
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
    Task current_task;
    double result = 0;
    while (tasks.pop(current_task))
        result += solveTask(current_task);
//    std::cout << "hello" << std::endl;
    return result;
}


int main(int argc, char *argv[]) {
    int provided = MPI::Init_thread(argc, argv, MPI::THREAD_MULTIPLE);
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
        std::cout << time_vals.max() << std::endl;
    }
    else {
        MPI::COMM_WORLD.Reduce(&sub_result, NULL, 1, MPI::DOUBLE, MPI::SUM, 0);
        MPI::COMM_WORLD.Gather(&sub_time, 1, MPI::DOUBLE, NULL, 1, MPI::DOUBLE, 0);
    }

    MPI::Finalize();
}

#include <stdio.h>
#include <mpi.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>

typedef struct Task {
    double start_value;
    long iterations;
} Task;

typedef struct Context {
    pthread_mutex_t mutex;
    pthread_mutex_t send_mut;
    pthread_cond_t send_cond;
    pthread_mutex_t recv_mut;
    pthread_cond_t recv_cond;
    Task* tasks;
    size_t current_task;
    size_t total;
} Context;

static MPI_Datatype* getTaskInfo() {
    static MPI_Datatype task_info[1];
    static int check = 0;
    if (!check) {
        MPI_Datatype parts[] = {MPI_DOUBLE, MPI_LONG};
        int block_lengths[] = {1, 1};
        MPI_Aint displacements[] = {offsetof(Task, start_value), offsetof(Task, iterations)};
        MPI_Type_create_struct(2, block_lengths, displacements, parts, task_info);
        MPI_Type_commit(task_info);
    }
    return task_info;
}

size_t getTasksCount(size_t shift) {
    size_t total = 160;
    size_t add_weight = total / 10;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    return (total / size) + (total % size == rank ? total % size: 0)
           + (total % size == rank ? add_weight : 0);
}

int getTasks(Context* context) {
    static size_t iteration = 0;
    static size_t total = 23;
    if (iteration < total) {
        ++iteration;
        size_t count =  getTasksCount(iteration);
        size_t i;
        for (i = 0; i < count; ++i) {
            context->tasks[i].start_value = 0.987654321 / (1 + iteration);
            context->tasks[i].iterations = 100000 * (1 + iteration % total);
        }
        context->current_task = 0;
        context->total = count;
        return 1;
    } else {
        return 0;
    }
}

void* receiver(void* context_p) {
    Context* context = (Context*)context_p;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//        std::cout << MPI::COMM_WORLD.Get_rank() << ":"  << "receiver started" << std::endl;
    pthread_mutex_lock(&context->mutex);
    int check = 1;
    while (getTasks(context)) {
        pthread_mutex_unlock(&context->mutex);
        if (size == 1) {
            pthread_mutex_lock(&context->send_mut);
            pthread_cond_signal(&context->send_cond);
            pthread_mutex_unlock(&context->send_mut);
        }
        int i;
        int code = 1;
        for (i = 1; i < size; ++i) {
            // int str = 0;
//            printf("%d:%d\n", rank, str++);
            // fflush(stdout);
            if (code == 1) {
                pthread_mutex_lock(&context->send_mut);
                pthread_cond_signal(&context->send_cond);
                pthread_mutex_unlock(&context->send_mut);
                pthread_cond_wait(&context->recv_cond, &context->recv_mut);
            }
           int from = (rank + i) % size;
            code = 1;
            MPI_Send(&code, 1, MPI_INT, from, 1, MPI_COMM_WORLD);
            MPI_Status st;
            MPI_Recv(&code, 1, MPI_INT, from, 2, MPI_COMM_WORLD, &st);
            if (code == 0) {
                continue;
            } else {
                --i;
            }
            Task task;
            MPI_Recv(&task, 1, *getTaskInfo(), from, 3, MPI_COMM_WORLD, &st);
            pthread_mutex_lock(&context->mutex);
            context->tasks[--context->current_task] = task;
            pthread_mutex_unlock(&context->mutex);
        }
        if (size == 1) {
            pthread_cond_wait(&context->recv_cond, &context->recv_mut);
            check = 0;
        }
        pthread_mutex_unlock(&context->mutex);
        while (context->total > context->current_task) {
            pthread_mutex_lock(&context->send_mut);
            pthread_cond_signal(&context->send_cond);
            pthread_mutex_unlock(&context->send_mut);
            pthread_cond_wait(&context->recv_cond, &context->recv_mut);
        }
        MPI_Barrier(MPI_COMM_WORLD);
        pthread_mutex_lock(&context->mutex);
    }
    pthread_mutex_unlock(&context->mutex);
//    pthread_mutex_lock(&tasks.new_task_mutex);
//    pthread_cond_broadcast(&tasks.new_task);
//    pthread_mutex_unlock(&tasks.new_task_mutex);
    int code = 0;
    MPI_Send(&code, 1, MPI_INT, rank, 1, MPI_COMM_WORLD);
//        pthread_mutex_lock(&tasks.need_new_task_mutex);
//    while () {
    pthread_mutex_lock(&context->send_mut);
    pthread_cond_signal(&context->send_cond);
    pthread_mutex_unlock(&context->send_mut);
//    if (check) {
//        pthread_cond_wait(&context->recv_cond, &context->recv_mut);
//        pthread_mutex_lock(&context->send_mut);
//        pthread_cond_signal(&context->send_cond);
//        pthread_mutex_unlock(&context->send_mut);
//    }
//    }
//    pthread_mutex_unlock(&tasks.need_new_task_mutex);
//    printf("%d: receiver finalized", rank);
    return NULL;
}
static void* sender(void* context_p) {
    Context* context = (Context*)context_p;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//        std::cout  << MPI::COMM_WORLD.Get_rank() << ":" << "sender started" << std::endl;
    while(1) {
        MPI_Status status;
        int code;
        int str = 0;
//        printf("%d::%d\n", rank, str++);
        MPI_Recv(&code, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
//        printf("%d::%d\n", rank, str++);
        if (code == 0)
            break;
        int proc = status.MPI_SOURCE;
//        printf("%d::%d\n", rank, str++);
        pthread_mutex_lock(&context->mutex);
//        printf("%d::%d\n", rank, str++);
        if (context->current_task >= context->total) {
            pthread_mutex_unlock(&context->mutex);
            code = 0;
            MPI_Send(&code, 1, MPI_INT, proc, 2, MPI_COMM_WORLD);
        } else {
            Task *task = &context->tasks[context->current_task++];
            pthread_mutex_unlock(&context->mutex);
            MPI_Send(&code, 1, MPI_INT, proc, 2, MPI_COMM_WORLD);
            MPI_Send(&task, 1, *getTaskInfo(), proc, 3, MPI_COMM_WORLD);
        }
    }
    return NULL;
}

double solveTask(const Task *task) {
    double result = task->start_value;
    size_t i;
    for (i = 0; i < task->iterations; ++i)
        result = sqrt(result * result);
    return result;
}

double worker(Context* context) {
    double result = 0;
    pthread_cond_wait(&context->send_cond, &context->send_mut);
    pthread_mutex_lock(&context->mutex);
    size_t counter = 0;
    for (; context->current_task < context->total;) {
        counter++;
        Task task = context->tasks[context->current_task++];
        pthread_mutex_unlock(&context->mutex);
        result += solveTask(&task);
        if ((context->total <= context->current_task) ||
                context->total / (context->total - context->current_task) >= 10) {
            pthread_mutex_lock(&context->recv_mut);
            pthread_cond_signal(&context->recv_cond);
            pthread_mutex_unlock(&context->recv_mut);
            pthread_cond_wait(&context->send_cond, &context->send_mut);
        }
        pthread_mutex_lock(&context->mutex);
    }
    printf("%lu", counter);
    return result;
}

int main(int argc, char *argv[]) {
    int provided;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
    if (provided < MPI_THREAD_MULTIPLE) {
        printf("wrong level provided\n");
        return 1;
    }
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double start = MPI_Wtime();
    Context context = {PTHREAD_MUTEX_INITIALIZER,
                       PTHREAD_MUTEX_INITIALIZER,
                       PTHREAD_COND_INITIALIZER,
                       PTHREAD_MUTEX_INITIALIZER,
                       PTHREAD_COND_INITIALIZER};
    context.tasks = (Task*)calloc((size_t)160 / size + 160 / 10 + 160 % size, sizeof(Task));
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_t sndr, rcvr;
    pthread_mutex_lock(&context.send_mut);
    pthread_mutex_lock(&context.recv_mut);
    pthread_create(&sndr, &attr, sender, &context);
    pthread_create(&rcvr, &attr, receiver, &context);
    pthread_attr_destroy(&attr);
    double sub_result = worker(&context);
    pthread_join(sndr, NULL);
    pthread_join(rcvr, NULL);
    pthread_mutex_unlock(&context.recv_mut);
    pthread_mutex_unlock(&context.send_mut);
    pthread_mutex_destroy(&context.mutex);
    pthread_mutex_destroy(&context.recv_mut);
    pthread_cond_destroy(&context.recv_cond);
    pthread_mutex_destroy(&context.send_mut);
    pthread_cond_destroy(&context.send_cond);

    double end = MPI_Wtime();
    double sub_time = end - start;
    if (rank == 0) {
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

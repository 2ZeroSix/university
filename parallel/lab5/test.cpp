#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>
#include <pthread.h>
#include <assert.h>
#include <signal.h>
#include <sys/types.h>
#include <syscall.h>

#define ITERS 15
#define TAG_FINISHED 0x01
#define TAG_NOT_FINISHED 0x02
#define TAG_TASK_REQUEST 0x03
#define TAG_INTERRUPT_RECV 0x04

struct task
{
    unsigned int time_ms;
};

int processes_rank;
int processes_count;

int total_task_time = 0;

struct task * tasks;
int tasks_count;

char * processes_finished;
pthread_mutex_t process_finished_iteration_mutex = PTHREAD_MUTEX_INITIALIZER;

int stop_threads = 0;
int current_task_performing = -1;
pthread_mutex_t tasks_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t cond_main_loop_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_main_loop = PTHREAD_COND_INITIALIZER;

pthread_mutex_t cond_send_loop_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_send_loop = PTHREAD_COND_INITIALIZER;

void generate_tasks(int iteration)
{
    tasks_count = 1 + abs(processes_rank - (iteration % processes_count));

    unsigned int max = 0;
    unsigned int total = 0;
    int i;
    for (i = 0; i < tasks_count; ++i)
    {
        tasks[i].time_ms = 500 + (unsigned int) rand() % 500;
        total += tasks[i].time_ms;
        total_task_time += tasks[i].time_ms;
        if (tasks[i].time_ms > max)max = tasks[i].time_ms;
    }

    printf("#%d max: %d, total: %d\n", processes_rank, max, total);

}

void perform_task(struct task task)
{
    unsigned int usecs = task.time_ms * 1000;
    usleep(usecs);
}


void set_process_finished_iteration(int process, char finished)
{
    int i;
    if (process == processes_rank)
    {
        unsigned int data;
        if (finished && !processes_finished[process])
        {
            MPI_Request req;
            // We've just finished
            for (i = 0; i < processes_count; ++i)
            {
                MPI_Isend(&data, 1, MPI_UNSIGNED, i, TAG_FINISHED, MPI_COMM_WORLD, &req);
            }
        }
        else if (!finished && processes_finished[process])
        {
            MPI_Request req;
            // We've just stopped being finished
            for (i = 0; i < processes_count; ++i)
            {
                MPI_Isend(&data, 1, MPI_UNSIGNED, i, TAG_NOT_FINISHED, MPI_COMM_WORLD, &req);
            }
        }
    }
    pthread_mutex_lock(&process_finished_iteration_mutex);
    processes_finished[process] = finished;
    pthread_mutex_unlock(&process_finished_iteration_mutex);
}

char is_all_processes_finished()
{
    int i;
    pthread_mutex_lock(&process_finished_iteration_mutex);
    for (i = 0; i < processes_count; ++i)
    {
        if (!processes_finished[i])
        {
            pthread_mutex_unlock(&process_finished_iteration_mutex);
            return 0;
        }
    }
    pthread_mutex_unlock(&process_finished_iteration_mutex);
    return 1;
}

char is_any_processes_finished()
{
    int i;
    pthread_mutex_lock(&process_finished_iteration_mutex);
    for (i = 0; i < processes_count; ++i)
    {
        if (processes_finished[i])
        {
            pthread_mutex_unlock(&process_finished_iteration_mutex);
            return 1;
        }
    }
    pthread_mutex_unlock(&process_finished_iteration_mutex);
    return 0;
}

void * receive_thread(void * ignored)
{
    while (!stop_threads)
    {
        MPI_Status status;
        unsigned int data;
        MPI_Recv(&data, 1, MPI_UNSIGNED, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        if (status.MPI_TAG == TAG_FINISHED)
        {

            set_process_finished_iteration(status.MPI_SOURCE, 1);

            pthread_mutex_lock(&cond_main_loop_lock);
            pthread_cond_signal(&cond_main_loop);
            pthread_mutex_unlock(&cond_main_loop_lock);

            pthread_mutex_lock(&cond_send_loop_lock);
            pthread_cond_signal(&cond_send_loop);
            pthread_mutex_unlock(&cond_send_loop_lock);

        }
        else if (status.MPI_TAG == TAG_NOT_FINISHED)
        {
            set_process_finished_iteration(status.MPI_SOURCE, 0);
        }
        else if (status.MPI_TAG == TAG_TASK_REQUEST)
        {
            pthread_mutex_lock(&tasks_mutex);
            tasks[tasks_count++].time_ms = data;
            pthread_mutex_unlock(&tasks_mutex);

            pthread_mutex_lock(&cond_main_loop_lock);
            pthread_cond_signal(&cond_main_loop);
            pthread_mutex_unlock(&cond_main_loop_lock);

            pthread_mutex_lock(&cond_send_loop_lock);
            pthread_cond_signal(&cond_send_loop);
            pthread_mutex_unlock(&cond_send_loop_lock);

            printf("#%d got task (%d) from #%d\n", processes_rank, data, status.MPI_SOURCE);
        }
    }
    return NULL;
}

void * send_thread(void * ignored)
{
    while (!stop_threads)
    {
        if (!is_any_processes_finished())
        {
            pthread_mutex_lock(&cond_send_loop_lock);
            pthread_cond_wait(&cond_send_loop, &cond_send_loop_lock);
            pthread_mutex_unlock(&cond_send_loop_lock);

            continue;
        }
        pthread_mutex_lock(&tasks_mutex);
        if (current_task_performing >= tasks_count - 1)
        {
            pthread_mutex_unlock(&tasks_mutex);

            pthread_mutex_lock(&cond_send_loop_lock);
            pthread_cond_wait(&cond_send_loop, &cond_send_loop_lock);
            pthread_mutex_unlock(&cond_send_loop_lock);

            continue;
        }
        int i;
        int target = -1;
        pthread_mutex_lock(&process_finished_iteration_mutex);
        for ( i = 0; i < processes_count; ++i)
        {
            if (processes_finished[i] && i != processes_rank)
            {
                target = i;
                break;
            }
        }
        pthread_mutex_unlock(&process_finished_iteration_mutex);
        if (target == -1)
        {
            pthread_mutex_unlock(&tasks_mutex);

            pthread_mutex_lock(&cond_send_loop_lock);
            pthread_cond_wait(&cond_send_loop, &cond_send_loop_lock);
            pthread_mutex_unlock(&cond_send_loop_lock);

            continue;
        }

        MPI_Request req;
        MPI_Isend(&tasks[tasks_count - 1].time_ms, 1, MPI_UNSIGNED, target, TAG_TASK_REQUEST,
                  MPI_COMM_WORLD, &req);
        MPI_Wait(&req, MPI_STATUS_IGNORE);
        set_process_finished_iteration(target, 0);

        tasks_count--;
        pthread_mutex_unlock(&tasks_mutex);
    }
    return NULL;
}

int main(int argc, char * argv[])
{
    srand((unsigned int) time(NULL));

    tasks = (task*)malloc(1000 * sizeof(struct task));
    processes_finished = (char*)malloc(processes_count * sizeof(char));

    int a;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &a);
    assert(a==MPI_THREAD_MULTIPLE);
    MPI_Comm_rank(MPI_COMM_WORLD, &processes_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &processes_count);

    //Start control thread:
    pthread_t thread1, thread2;
    pthread_attr_t attrs;
    pthread_attr_init(&attrs);
    pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_JOINABLE);
    pthread_create(&thread1, &attrs, receive_thread, NULL);
    pthread_create(&thread2, &attrs, send_thread, NULL);
    pthread_attr_destroy(&attrs);
    int i,j;
    double time_start = MPI_Wtime();

    for (i = 0; i < ITERS; i++)
    {
        printf("Process #%d started iteration %d\n", processes_rank, i);
        generate_tasks(i);

        pthread_mutex_lock(&process_finished_iteration_mutex);
        for (j = 0; j < processes_count; ++j)
        {
            processes_finished[j] = 0;
        }
        pthread_mutex_unlock(&process_finished_iteration_mutex);

        current_task_performing = 0;

        while (1)
        {
            pthread_mutex_lock(&tasks_mutex);
            if (current_task_performing < tasks_count)
            {
                set_process_finished_iteration(processes_rank, 0);
                struct task task = tasks[current_task_performing++];
                pthread_mutex_unlock(&tasks_mutex);

                perform_task(task);
            }
            else
            {
                pthread_mutex_unlock(&tasks_mutex);
                set_process_finished_iteration(processes_rank, 1);

                pthread_mutex_lock(&cond_main_loop_lock);
                pthread_cond_wait(&cond_main_loop, &cond_main_loop_lock);
                pthread_mutex_unlock(&cond_main_loop_lock);
            }
            if (is_all_processes_finished())
            {
                break;
            }
        }
    }


    stop_threads = 1;

    unsigned int data;
    MPI_Request req;
    MPI_Isend(&data, 1, MPI_UNSIGNED, processes_rank, TAG_INTERRUPT_RECV, MPI_COMM_WORLD, &req);
    MPI_Request_free(&req);
    pthread_join(thread1, NULL);

    pthread_mutex_lock(&cond_send_loop_lock);
    pthread_cond_signal(&cond_send_loop);
    pthread_mutex_unlock(&cond_send_loop_lock);
    pthread_join(thread2, NULL);

    int res;
    MPI_Reduce(&total_task_time, &res, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(processes_rank==0) printf("total = %lf\n", res/1000.0);

    MPI_Reduce(&total_task_time, &res, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    if(processes_rank==0)
    {
        printf("max = %lf\n", res / 1000.0);
        double time_end = MPI_Wtime();
        printf("time = %lf\n", time_end - time_start);
    }

    MPI_Finalize();
    return 0;
}

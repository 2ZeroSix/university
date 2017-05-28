#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <mpi.h>
#include <unistd.h>

#define COUNT 20
#define ITERTASKS 700

struct task {
    useconds_t sleep;
};

double countDone;

int ranksNum;
int rank;
int curIter;
int curTask;
std::vector<task> quests;

MPI::Datatype taskInf;

pthread_mutex_t taskMutex;
pthread_t sender;

//выполнение задачи
void doTask(task quest) {
    usleep(quest.sleep);
}

void createNewTasks(int tasksNum) {
    int weight = abs(rank - (curIter % ranksNum));
    quests.clear();
    for (int i = 0; i < tasksNum; i++) {
        task newOne;
        double range = (i + 10.) / tasksNum;
        newOne.sleep = (useconds_t)(100000 * range);
        quests.push_back(newOne);
    }
}

void* workForPerformer(void* args) {
    for (;curIter < COUNT; curIter++) {
//        printf("%d\n", curIter);
        pthread_mutex_lock(&taskMutex);
        int count = (ITERTASKS / ranksNum) + ((rank < ITERTASKS % ranksNum)? 1 : 0);
        createNewTasks(count);
        pthread_mutex_unlock(&taskMutex);

        curTask = 0;
        int i = 0;
        while (i < ranksNum) {
            pthread_mutex_lock(&taskMutex);
            //выполняем все имеющиеся задания
            while(curTask < quests.size()) {
                curTask++;
                pthread_mutex_unlock(&taskMutex);

                doTask(quests[curTask - 1]);
                countDone += quests[curTask - 1].sleep;

                pthread_mutex_lock(&taskMutex);
            }
            pthread_mutex_unlock(&taskMutex);


            //пытаемся получить еще задачи на выполнение
            if (i == 0) {
                i++;
                continue;
            }

            int fromWhom = (rank + i) % ranksNum;
            int code = 1;
            MPI::COMM_WORLD.Send(&code, 1, MPI::INT, fromWhom, 1);
            MPI::COMM_WORLD.Recv(&code, 1, MPI::INT, fromWhom, 2);

            //уходим с получения задач от данного процесса лишь когда у него нет задач для нас
            if (code == 0) {
                i++;
                continue;
            }

            //принимаем новую задачу
            task newQuest;
            MPI::COMM_WORLD.Recv(&newQuest, 1, taskInf, fromWhom, 3);
            pthread_mutex_lock(&taskMutex);
            quests.push_back(newQuest);
            pthread_mutex_unlock(&taskMutex);
        }

        MPI::COMM_WORLD.Barrier();
    }

    int code = 0;
    MPI::COMM_WORLD.Send(&code, 1, MPI::INT, rank, 1);
    return NULL;
}


void* workForSender(void* args)
{
    while(curIter < COUNT) {
        MPI::Status status;
        int code;
        //принимаем запрос о получении задачи от некоего процесса
        MPI::COMM_WORLD.Probe(MPI::ANY_SOURCE, 1, status);
        int proc = status.Get_source();
        MPI::COMM_WORLD.Recv(&code, 1, MPI::INT, proc, 1, status);
        if (code == 0)
            break;

        //смотрим, есть ли свободная задача
        pthread_mutex_lock(&taskMutex);
        if (curTask >= quests.size()) {
            code = 0;
            MPI::COMM_WORLD.Send(&code, 1, MPI::INT, proc, 2);
            pthread_mutex_unlock(&taskMutex);
            continue;
        }

        //если есть задача - отправляем ее
        MPI::COMM_WORLD.Send(&code, 1, MPI::INT, proc, 2);
        MPI::COMM_WORLD.Send(&quests.back(), 1, taskInf, proc, 3);
        quests.pop_back();
        pthread_mutex_unlock(&taskMutex);
    }
    return NULL;
}

int main(int argc, char** argv)  {
    int provided = MPI::Init_thread(argc, argv, MPI::THREAD_MULTIPLE);
//    if (provided != MPI::THREAD_MULTIPLE) return 1;
//    std::cout << provided << std::endl;
    rank = MPI::COMM_WORLD.Get_rank();
    ranksNum = MPI::COMM_WORLD.Get_size();

    pthread_mutex_init(&taskMutex, NULL);
    countDone = 0;
    double start, end;
    start = MPI_Wtime();
    curIter = 0;
    srand((unsigned)time(NULL));

    //создание типа данных для пересылки заданий между процессами
    MPI::Datatype parts[] = {MPI::DOUBLE, MPI::INT, MPI::INT};
    int block_lengths[3] = {1, 1, 1};
    MPI::Aint displacements[3] = {0, sizeof(double), sizeof(double) + sizeof(int)};
    taskInf = MPI::Datatype::Create_struct(3, block_lengths, displacements, parts);
    taskInf.Commit();

    //инициализация потока отсылки
    pthread_attr_t attrs;
    pthread_attr_init(&attrs);
    pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_JOINABLE);

    pthread_create(&sender, &attrs, workForSender, NULL);
    workForPerformer(NULL);

    //завершение работы
    pthread_attr_destroy(&attrs);

    end = MPI_Wtime() - start;

//    double* iters;
    if (rank == 0) {
//        iters = new double[ranksNum];
        double* workTime = new double[ranksNum];

        MPI::COMM_WORLD.Gather(&end, 1, MPI::DOUBLE, workTime, 1, MPI::DOUBLE, 0);
//        MPI::COMM_WORLD.Gather(&countDone, 1, MPI::DOUBLE, iters, 1, MPI::DOUBLE, 0);

        for (int i = 0; i < ranksNum; i++)
            std::cout << workTime[i] << std::endl;
            /*std::cout << "Iterations of process " << i << " = " << iters[i] << " working time = " << */
    }
    else {
        MPI::COMM_WORLD.Gather(&end, 1, MPI::DOUBLE, NULL, 1, MPI::DOUBLE, 0);
//        MPI::COMM_WORLD.Gather(&countDone, 1, MPI::DOUBLE, NULL, 1, MPI::DOUBLE, 0);
    }
    pthread_join(sender, NULL);
    pthread_mutex_destroy(&taskMutex);

    MPI::Finalize();
    return 0;
}

//
// Created by dzs on 23.05.17.
//

#include <mpi.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <vector>

#define COUNT 20
#define ITERTASKS 700

struct task {
    double den;
    int count;
    int startData;
};

double countDone;

int ranksNum;
int rank;
int curIter;
int curTask;
std::vector<task> quests;

//выполнение задачи
double doTask(task quest) {
        double result = 0;
        double subj = quest.startData;

        for (int i = 0; i < quest.count; i++) {
                result += sqrt(sqrt(subj * subj * subj));
                subj *= quest.den;
        }

        return result;
}

//создание новых задач
void createNewTasks(int tasksNum) {
        int weight = abs(rank - (curIter % ranksNum));

        quests.clear();

        for (int i = 0; i < tasksNum; i++) {
                task newOne;
                double range = (i + 10.) / tasksNum;
                newOne.startData = 7000 * range + 700;
                newOne.den = 1.0 / 50 * range;
                newOne.count = 100000 * range * weight + 50000;
                quests.push_back(newOne);
        }
}

void workForPerformer(void* args) {
    for (;curIter < COUNT; curIter++) {
//        printf("%d\n", curIter);
        int count = (ITERTASKS / ranksNum) + ((rank < ITERTASKS % ranksNum)? 1 : 0);
        createNewTasks(count);

        curTask = 0;

        while(curTask < quests.size()) {
                curTask++;

                double result = doTask(quests[curTask - 1]);
                countDone += quests[curTask - 1].count;
        }
    }
}


int main(int argc, char** argv) {
    MPI::Init_thread(argc, argv, MPI::THREAD_SERIALIZED);

    rank = MPI::COMM_WORLD.Get_rank();
    ranksNum = MPI::COMM_WORLD.Get_size();

    countDone = 0;
    double start, end;
    start = MPI::Wtime();
    curIter = 0;
    srand(time(NULL));

    workForPerformer(NULL);

    end = MPI::Wtime() - start;

    if (rank == 0) {
        double *workTime = new double[ranksNum];
        MPI::COMM_WORLD.Gather(&end, 1, MPI::DOUBLE, workTime, 1, MPI_DOUBLE, 0);
        for (int i = 0; i < ranksNum; i++)
            std::cout << workTime[i] << std::endl;
    }
    else {
        MPI::COMM_WORLD.Gather(&end, 1, MPI::DOUBLE, NULL, 1, MPI_DOUBLE, 0);
//        MPI_Gather(&countDone, 1, MPI_DOUBLE, NULL, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    }

    MPI::Finalize();

    return 0;
}

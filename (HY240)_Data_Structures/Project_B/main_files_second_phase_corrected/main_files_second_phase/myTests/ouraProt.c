#include <stdio.h>
#include <stdlib.h>

typedef struct HT_Task{
    int tid;
    int difficulty;
}HT_Task;

typedef struct Completed_Tasks_PQ {
    int size;
    struct HT_Task tasks[];
}Completed_Tasks;

Completed_Tasks *completed_TasksP;

void insertCompletedTasks(HT_Task *task) {
    int m;
if(completed_TasksP->size == 504) {
    printf("Error\n");
    exit(-1);
}
m = completed_TasksP->size;
while(m>0 && task->difficulty < completed_TasksP->tasks[(m-1)/2].difficulty) {
    completed_TasksP->tasks[m].difficulty = completed_TasksP->tasks[(m-1)/2].difficulty;
    completed_TasksP->tasks[m].tid = completed_TasksP->tasks[(m-1)/2].tid;
    m = (m-1)/2;
}
completed_TasksP->tasks[m].difficulty = task->difficulty;
completed_TasksP->tasks[m].tid = task->tid;
completed_TasksP->size++;

}
void deleteMin() {
    if(completed_TasksP->size==0) {
        printf("I dont have something to delete\n");
        exit(-1);
    }
    int I = completed_TasksP->tasks[0].tid;
    int K = completed_TasksP->tasks[completed_TasksP->size - 1].difficulty;
    int p;
    completed_TasksP->size--;
    if(completed_TasksP->size==1) {
        return;
    }
    int m = 0;
    while((2*m+1 < completed_TasksP->size && K>completed_TasksP->tasks[2*m+1].difficulty)||(2*m+2 < completed_TasksP->size && K>completed_TasksP->tasks[2*m+2].difficulty)) {
        if(2*m+2 <completed_TasksP->size) {
            if(completed_TasksP->tasks[2*m+1].difficulty < completed_TasksP->tasks[2*m+2].difficulty) {
                 p = 2*m+1;
            }else {
                 p = 2*m+2;
            }
            } else {
                p = completed_TasksP->size -1;
            }
            completed_TasksP->tasks[m].difficulty = completed_TasksP->tasks[p].difficulty;

            completed_TasksP->tasks[m].tid = completed_TasksP->tasks[p].tid;
            m=p;
        }
        completed_TasksP->tasks[m].difficulty = K;
        completed_TasksP->tasks[m].tid = completed_TasksP->tasks[completed_TasksP->size].tid;
        
    }


int main() {
HT_Task *kappa;
kappa = (HT_Task*)malloc(sizeof(HT_Task));
completed_TasksP = (Completed_Tasks*)malloc(sizeof(Completed_Tasks) + 504*sizeof(HT_Task));
int counter = 1;
for(int i = 1;i<4;i++) {
    for(int j = 1;j<4;j++) {
        kappa->difficulty = j;
        kappa->tid = counter + 5*i*j;
        insertCompletedTasks(kappa);
    }
}
for(int k = 0;k<9;k++) {
    printf("%d",completed_TasksP->tasks[k].difficulty);
}
deleteMin();
deleteMin();
printf("\n");
for(int k = 0;k<10;k++) {
    printf("%d",completed_TasksP->tasks[k].difficulty);
}
}
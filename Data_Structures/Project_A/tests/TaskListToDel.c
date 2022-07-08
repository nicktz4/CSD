#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
struct Head_GL
{
    int tasks_count[3];           /*Count of tasks*/
    struct Tasks *head;           /*Pointer to the head of general list*/
};
typedef struct Tasks

{
    int tid;                      /*Task's identifier*/
    int difficulty;               /*Task's difficulty*/
    struct Tasks *next;           /*Pointer to the next node*/  
}Tasks;

struct Head_GL *tasks_head;

int printTasks();
int insertTask(int tid,int difficulty);
int  main() {
    tasks_head = (struct Head_GL*)malloc(sizeof(struct Head_GL));
    tasks_head->tasks_count[0] = 0;

    tasks_head->tasks_count[1] = 0;
    tasks_head->tasks_count[2] = 0;
    int success=-1;


    success = insertTask(4,3);
    success = insertTask(6,3);

    success = insertTask(12,2);
    success = insertTask(7,2);
    success = insertTask(8,3);
    success = insertTask(9,3);
    success = insertTask(5,1);
    success = insertTask(10,3);
    success = insertTask(11,2);
    for(int i = 0;i<3;i++) {
        printf("%d",tasks_head->tasks_count[i]);
    }
    success = printTasks();
}
int printTasks() {
    Tasks *tmpP1;
    tmpP1 = tasks_head->head;
    while(tmpP1!=NULL) {
        printf("tid: %d\n",tmpP1->tid);
        printf("Dif: %d\n",tmpP1->difficulty);
        printf("--------------\n");
        tmpP1 = tmpP1->next;
    }
    return 1;


}
int insertTask(int tid,int difficulty) {

    Tasks *newTask;
    newTask =(Tasks*)malloc(sizeof(Tasks));
    newTask->tid = tid;
    newTask->difficulty = difficulty;
    tasks_head->tasks_count[difficulty-1]++;

    if(tasks_head->head == NULL) {
        tasks_head->head = newTask;
        return 1;
    }
    Tasks *tmpP1 = tasks_head->head;

    Tasks *tmpP2 = NULL;
    while(tmpP1!=NULL) {
        if(tmpP1->difficulty >= difficulty) {
            if(tmpP2==NULL) {
            newTask->next = tmpP1;
            tasks_head->head = newTask;
            } else {
                newTask->next = tmpP1;
                tmpP2->next = newTask;
            }
            return 1;
        }
            if(tmpP1->next == NULL ) {
                tmpP1->next = newTask;
                return 1;
            }
            tmpP2 = tmpP1;
            tmpP1 = tmpP1->next;

        }
        return 0;
}

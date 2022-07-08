#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
struct Players *players_head;

struct Players
{
    int pid;                      /*Player's identifier*/
    int is_alien;                 /*Alien flag*/
    int evidence;                 /*Amount of evidence*/
    struct Players *prev;         /*Pointer to the previous node*/
    struct Players *next;         /*Pointer to the next node*/
    struct Tasks *tasks_head;     /*Pointer to the head of player's task list*/
    struct Tasks *tasks_sentinel; /*Pointer to the sentinel of player's task list*/
};
/**
 * Structure defining a node of the tasks sorted linked list
 */
typedef struct Tasks
{
    int tid;                      /*Task's identifier*/
    int difficulty;               /*Task's difficulty*/
    struct Tasks *next;           /*Pointer to the next node*/  
}Tasks;

int insertTask(int tid,int difficulty) {

    Tasks *newTask;
    newTask =(Tasks*)malloc(sizeof(Tasks));
    newTask->tid = tid;
    newTask->difficulty = difficulty;

    
    Tasks *tmpP1 = players_head->tasks_head;

    Tasks *tmpP2 = NULL;
    if(tmpP1==NULL) {
        newTask->next = players_head->tasks_sentinel;
        players_head->tasks_head = newTask;
        return 1;
    }
    while(tmpP1->difficulty!=0) {
        if(tmpP1->difficulty >= difficulty ) {
            if(tmpP2==NULL) {
            newTask->next = tmpP1;
            players_head->tasks_head = newTask;
            } else {
                newTask->next = tmpP1;
                tmpP2->next = newTask;
            }
            return 1;
        }
            if(tmpP1->next->difficulty == 0 ) {
                newTask->next = tmpP1->next;
               tmpP1->next = newTask;
                return 1;
            }
            tmpP2 = tmpP1;
            tmpP1 = tmpP1->next;

        }
        


        return 0;
}

int printTasks() {
    Tasks *tmpP1;
    tmpP1 = players_head->tasks_head;
    while(tmpP1->difficulty!=0) {
        printf("tid: %d\n",tmpP1->tid);
        printf("Dif: %d\n",tmpP1->difficulty);
        printf("--------------\n");
        tmpP1 = tmpP1->next;
    }
    return 1;


}
int main() {

    players_head=(struct Players*)malloc(sizeof(struct Players));
    Tasks *sentinelNode;

    sentinelNode = (Tasks*)malloc(sizeof(Tasks));

    sentinelNode->tid = -1;

    sentinelNode->difficulty = 0;

    sentinelNode->next = NULL;

    players_head->tasks_sentinel = sentinelNode;
    
    int success;

    for(int i = 0 ; i < 5;i++) {
    success = insertTask(4+i,2);
    success = insertTask(4+i,3);
    success = insertTask(4+i,1);
}
success = printTasks();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Global variable, pointer to the top of the completed task's stack */
struct Head_Completed_Task_Stack *tasks_stack;

typedef struct Tasks

{
    int tid;                      /*Task's identifier*/
    int difficulty;               /*Task's difficulty*/
    struct Tasks *next;           /*Pointer to the next node*/  
}Tasks;

struct Head_Completed_Task_Stack
{
    int count;                    /*Count of completed tasks*/
    struct Tasks *head;           /*Pointer to the top element of the stack*/
};

int Push(Tasks *S) {

tasks_stack->count++;    
//Tasks *p ;
//p = (Tasks*)malloc(sizeof(Tasks));

//p->tid = S->tid;
//p->difficulty = S->difficulty;
//p->next = tasks_stack->head;
S->next = tasks_stack->head;
tasks_stack->head = S;

return 1;
}
void printStack() {
if(isEmptyStack(tasks_stack->head)) {
printf("Completed Task Stack is empty\n");
} else {
Tasks *tmp = tasks_stack->head;

while(tmp !=NULL) {
printf("%d\n",tmp->tid);
tmp = tmp->next;
}
}
}
int isEmptyStack(Tasks *stack) {
    if(stack==NULL) {return 1;}
    return 0;


}
int main() {

    tasks_stack = (struct Head_Completed_Task_Stack*)malloc(sizeof(struct Head_Completed_Task_Stack));
    tasks_stack->count = 0;

    int success;
    for(int i = 0 ;i<10;i++) {
    Tasks *p ;
    p = (Tasks*)malloc(sizeof(Tasks));
    p->tid = 4+i;
    p->difficulty = 1;
    success = Push(p);
    }
    printStack();

    return 0;
}
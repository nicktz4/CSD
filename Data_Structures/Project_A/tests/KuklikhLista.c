#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Players *players_head;
/**
 * Structure defining a node of the players double linked list
 * tree
 */
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

/**
 * @brief Register player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien) {
    struct Players *player;
    player = (struct Players*)malloc(sizeof(struct Players));
    if(player==NULL) {
        return 0;
    }
    player->pid = pid;
    player->is_alien = is_alien;
    player->evidence = 0;
    
    Tasks *sentinelNode;

    sentinelNode = (Tasks*)malloc(sizeof(Tasks));

    sentinelNode->tid = -1;

    sentinelNode->difficulty = 0;

    sentinelNode->next = player;
    
    player->tasks_sentinel = sentinelNode;

    if(players_head->next!=NULL) {
    players_head->next->prev=player;

    player->next = players_head->next;
    }else {
        players_head->next = player;
        player->next = players_head;
    }

    players_head->next = player;
    

    player->prev = players_head;

    return 1;

}
int printDoubleList() {
struct Players *tmp = players_head->next;
while(tmp->pid != players_head->pid) {
printf("pid: %d",tmp->pid);
printf(" is_alien: %d",tmp->is_alien);
printf(" evidence: %d\n",tmp->evidence);
tmp = tmp->next;
}
return 1;

}

int main() {
    players_head = (struct Players*)malloc(sizeof(struct Players));
    players_head->pid = -1;
    players_head->is_alien = -1;
    players_head->evidence= -1;
    players_head->next = NULL;
    players_head->prev = NULL;
    players_head->tasks_head= NULL;
    players_head->tasks_sentinel = NULL;

    int success;
    for(int i = 0 ; i < 10 ; i++) {
    success = register_player(i,1);
    }
    success = printDoubleList();
    return 0;
}
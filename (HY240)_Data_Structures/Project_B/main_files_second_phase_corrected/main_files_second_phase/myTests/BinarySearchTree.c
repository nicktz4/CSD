#include <stdio.h>
#include <stdlib.h>
//duadiko dendro anazhthshs
typedef struct player_Tasks {
// to tid toy task
int tid;
// to difficulty to task
int dif;
// enas counter gia posa paidia exei sto aristero upodendro
int lcnt;
// to aristero paidi
struct player_Tasks *lc;
//to de3i paidi
struct player_Tasks *rc;


}player_Tasks;

player_Tasks* deleteTask(int tid,player_Tasks *T) {
player_Tasks* tmp = T;
player_Tasks* Prev = NULL;
while(tmp!=NULL) {
    Prev = tmp;
    if(tmp->tid == tid) {
        if(tmp->rc==NULL && tmp->lc==NULL) {
            if(Prev->tid < tmp->tid) {
                Prev->rc = NULL;
            } else {
                Prev->lc = NULL;
            }
            free(tmp);
            break;
        }
        if(tmp->rc==NULL) {
            player_Tasks *new = tmp->lc;
            Prev->lc = new;
            free(tmp);
            break;
            
        } else if(tmp->lc==NULL) {
            player_Tasks *new = tmp->rc;
            Prev->rc = new;
            free(tmp);
            break;
        } else {
            player_Tasks *successorParent = tmp;
            player_Tasks *successor = tmp->rc;
            while(successor->lc!=NULL) {
                successorParent=successor;
                successor = successor->lc;
            }
            if(successorParent!=tmp) {
                successorParent->lc = successor->rc;
            }else {
                successorParent->rc = successor->rc;
            }
                tmp->tid = successor->tid;
                free(successor);

        }



    }else if(tmp->tid < tid ) {

        Prev = tmp;
        tmp = tmp->rc;
    } else {

        Prev = tmp;
        tmp->lcnt--;
        tmp = tmp->lc;
    }



}
return T;


}
player_Tasks* insertTask(int tid,int dif,player_Tasks *T) {
    player_Tasks *temp,*Prev;
    temp = T;
    Prev = NULL;
    while(temp!=NULL) {
        Prev = temp;
        if(temp->tid < tid) {
            temp = temp->rc;
        } else {
            temp->lcnt++;
            temp = temp->lc;
        }
    }
    player_Tasks *newCell;
    newCell = (player_Tasks*)malloc(sizeof(player_Tasks));
    newCell->dif = dif;
    newCell->tid = tid;
    newCell->lcnt = 0;
    newCell->rc = NULL;
    newCell->lc = NULL;
    if(Prev == NULL) {
        return newCell;
    } else if(Prev->tid > newCell->tid) {
        Prev->lc = newCell;
    } else {
        Prev->rc = newCell;
    }
    return T;

}
void printTasksInOrder(player_Tasks* T) {
player_Tasks* tmp = T;
if(tmp==NULL) {
    return;
}
printTasksInOrder(tmp->lc);
printf("tid: %d , ",tmp->tid);

printf("lcnt: %d\n",tmp->lcnt);
printTasksInOrder(tmp->rc);

}

int main() {
 player_Tasks *player;   
player = insertTask(15,2,player);

player = insertTask(5,3,player);
player = insertTask(3,2,player);
player = insertTask(4,1,player);
player = insertTask(7,2,player);
player = insertTask(13,2,player);
player = insertTask(9,2,player);


player = insertTask(2,3,player);

player = insertTask(18,3,player);
player = insertTask(17,2,player);
player = insertTask(20,1,player);
printf("Before delete:\n");
printTasksInOrder(player);
player = deleteTask(15,player);
printf("After delete: \n");
printTasksInOrder(player);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct playerTree {
int pid;
int is_alien;
int evidence;
struct playerTree  *parent;
struct playerTree  *lc;
struct playerTree *rc;
//struct playerTasks *tasks;
}playerTree;

playerTree *sentinelNode;

playerTree* Tree;

void printTree(playerTree*T) {
    playerTree *tmp = T;

    if(tmp->pid ==sentinelNode->pid) {
        return;
    }
    printTree(tmp->lc);
    printf("pid: %d\n",tmp->pid);
    printTree(tmp->rc);

}
playerTree *deletePlayer(int pid,playerTree*T) {
playerTree* tmp = T;
playerTree* Prev = NULL;
while(tmp->pid!=sentinelNode->pid) {
    //Prev = tmp;
    if(tmp->pid == pid) {
        if(tmp->rc==sentinelNode && tmp->lc==sentinelNode) {
            if(Prev->pid < tmp->pid) {
                Prev->rc = sentinelNode;
            } else {
                Prev->lc = sentinelNode;
            }
            free(tmp);
            break;
        }
        if(tmp->rc==sentinelNode) {
            playerTree *new = tmp->lc;
            Prev->lc = new;
            free(tmp);
            break;
            
        } else if(tmp->lc==sentinelNode) {
            playerTree *new = tmp->rc;
            Prev->rc = new;
            free(tmp);
            break;
        } else {
            playerTree *successorParent = tmp;
            playerTree *successor = tmp->rc;
            while(successor->lc!=sentinelNode) {
                successorParent=successor;
                successor = successor->lc;
            }
            if(successorParent!=tmp) {
                successorParent->lc = successor->rc;
            }else {
                successorParent->rc = successor->rc;
            }
                tmp->pid = successor->pid;
                free(successor);

        }



    }else if(tmp->pid < pid ) {

        Prev = tmp;
        tmp = tmp->rc;
    } else {

        Prev = tmp;
        tmp = tmp->lc;
    }



}
return T;



}
 playerTree *findPlayerWith(playerTree* T,int pid) {
        playerTree *tmp = T;
        //printf("pid: %d",tmp->pid);
        while(tmp!=sentinelNode) {
        if(pid < tmp->pid) {
            tmp = tmp->lc;

        } else if(pid > tmp->pid) {
            tmp=tmp->rc;
        }else {
            return tmp;
        }

 }

    return NULL;
 }

playerTree *insertPlayer(int pid,int is_alien,int evidence,playerTree *T) {
playerTree *temp = T;
playerTree *Prev= NULL;
int sentinelPid = sentinelNode->pid;
while(temp->pid != sentinelPid) {
if(temp->pid < pid) {
    Prev = temp;
    temp = temp->rc;
} else if(temp->pid > pid) {
    Prev = temp;
    temp = temp->lc;
} else {
    temp->is_alien = is_alien;
    temp->evidence = evidence;
}

}
playerTree *new;
new = (playerTree*)malloc(sizeof(playerTree));
new->pid = pid;
new->is_alien = is_alien;
new->evidence = evidence;
new->rc = sentinelNode;
new->lc = sentinelNode;
if(Prev!=NULL) {
    if(Prev->pid < pid) {
        Prev->rc = new;
    } else {
        Prev->lc = new;
    }
new->parent = Prev;
}else {
    new->parent = sentinelNode;
    //T = new;
    return new;
}

return T;
}
playerTree *findPlayerWithEv(playerTree *T,int evidence) {
    playerTree *P = T;
while (P !=sentinelNode && evidence != P->evidence) {
if (evidence < P->evidence) P = P->lc;
else P = P->rc;
}
if (P != NULL)
return P;
else return NULL;
}
playerTree *findPlayerWithMoreEvidence(playerTree *T,int evidence) {
    playerTree *tmp = T;
    if( (tmp == Tree )&& ( evidence != -1 ) ) {
        //return findPlayerWithEv(Tree,evidence);
        return ;
    }
    findPlayerWithMoreEvidence(tmp->lc,evidence);
        if(evidence < tmp->evidence) {
            evidence  = tmp->evidence;
            
        }
    findPlayerWithMoreEvidence(tmp->rc,evidence);
}
playerTree* MoreEvidence(playerTree *T) {
    playerTree *tmp = T;
    static playerTree *playerWithMoreEvidence = NULL;
    static int evidence = 0;
    if (tmp == sentinelNode ) {
        return playerWithMoreEvidence;
    }
    MoreEvidence(tmp->lc);
        if(evidence < tmp->evidence) {
            evidence  = tmp->evidence;
            playerWithMoreEvidence = tmp;
            
        }
    MoreEvidence(tmp->rc);
}

int main() {
playerTree *sentinelNode1;
sentinelNode1 = (playerTree*)malloc(sizeof(playerTree));
sentinelNode1->pid = -1;
sentinelNode1->is_alien = 0;
sentinelNode1->evidence = 0;
sentinelNode1->rc =NULL;
sentinelNode1->lc = NULL;
sentinelNode1->parent = NULL;
sentinelNode = sentinelNode1;
 Tree = sentinelNode;

Tree = insertPlayer(50,1,1,Tree);
Tree = insertPlayer(70,0,2,Tree);
Tree = insertPlayer(35,0,330,Tree);
Tree = insertPlayer(60,0,4,Tree);
Tree = insertPlayer(80,0,35,Tree);

Tree = insertPlayer(90,1,6,Tree);
Tree = insertPlayer(75,1,107,Tree);
playerTree *player = findPlayerWith(Tree,35);
if(player==NULL) {
    printf("den vrethike\n");
} else {
printf("%d\n",player->pid);
}

printTree(Tree);
playerTree *playerEvidence = MoreEvidence(Tree);
printf("evidence: %d\n",playerEvidence->evidence);





}
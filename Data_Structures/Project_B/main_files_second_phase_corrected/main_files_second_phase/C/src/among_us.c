/***************************************************
 *                                                 *
 * file: among_us.c                                *
 *                                                 *
 * @Author  Skerdi Basha                           *
 * @Version 1-12-2020                              *
 * @email   sbash@csd.uoc.gr                       *
 *                                                 *
 * @brief   Implementation of among_us.h           *
 *                                                 *
 ***************************************************
 */

 /*
/***************************************************
 *                                                 *
 *                                                 *
 *   file: among_us.c                              *
 *   Nikos Tzanakis                                *
 * @Version 23-12-2020                             *
 * @email   csd4349@csd.uoc.gr                     *
 *                                                 *
 * @brief  fill in the functions to create         *
 *          among_us Project for cs240 Phase B     *
 *                                                 *
 *                                                 *
 ***************************************************
 */

#include "among_us.h"

unsigned int primes_g[650] = { 
                                 179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
                                 233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
                                 283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
                                 353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
                                 419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
                                 467,    479,    487,    491,    499,    503,    509,    521,    523,    541, 
                                 547,    557,    563,    569,    571,    577,    587,    593,    599,    601, 
                                 607,    613,    617,    619,    631,    641,    643,    647,    653,    659, 
                                 661,    673,    677,    683,    691,    701,    709,    719,    727,    733, 
                                 739,    743,    751,    757,    761,    769,    773,    787,    797,    809, 
                                 811,    821,    823,    827,    829,    839,    853,    857,    859,    863, 
                                 877,    881,    883,    887,    907,    911,    919,    929,    937,    941, 
                                 947,    953,    967,    971,    977,    983,    991,    997,   1009,   1013, 
                                1019,   1021,   1031,   1033,   1039,   1049,   1051,   1061,   1063,   1069, 
                                1087,   1091,   1093,   1097,   1103,   1109,   1117,   1123,   1129,   1151, 
                                1153,   1163,   1171,   1181,   1187,   1193,   1201,   1213,   1217,   1223, 
                                1229,   1231,   1237,   1249,   1259,   1277,   1279,   1283,   1289,   1291, 
                                1297,   1301,   1303,   1307,   1319,   1321,   1327,   1361,   1367,   1373, 
                                1381,   1399,   1409,   1423,   1427,   1429,   1433,   1439,   1447,   1451, 
                                1453,   1459,   1471,   1481,   1483,   1487,   1489,   1493,   1499,   1511, 
                                1523,   1531,   1543,   1549,   1553,   1559,   1567,   1571,   1579,   1583, 
                                1597,   1601,   1607,   1609,   1613,   1619,   1621,   1627,   1637,   1657, 
                                1663,   1667,   1669,   1693,   1697,   1699,   1709,   1721,   1723,   1733, 
                                1741,   1747,   1753,   1759,   1777,   1783,   1787,   1789,   1801,   1811, 
                                1823,   1831,   1847,   1861,   1867,   1871,   1873,   1877,   1879,   1889, 
                                1901,   1907,   1913,   1931,   1933,   1949,   1951,   1973,   1979,   1987, 
                                1993,   1997,   1999,   2003,   2011,   2017,   2027,   2029,   2039,   2053, 
                                2063,   2069,   2081,   2083,   2087,   2089,   2099,   2111,   2113,   2129, 
                                2131,   2137,   2141,   2143,   2153,   2161,   2179,   2203,   2207,   2213, 
                                2221,   2237,   2239,   2243,   2251,   2267,   2269,   2273,   2281,   2287, 
                                2293,   2297,   2309,   2311,   2333,   2339,   2341,   2347,   2351,   2357, 
                                2371,   2377,   2381,   2383,   2389,   2393,   2399,   2411,   2417,   2423, 
                                2437,   2441,   2447,   2459,   2467,   2473,   2477,   2503,   2521,   2531, 
                                2539,   2543,   2549,   2551,   2557,   2579,   2591,   2593,   2609,   2617, 
                                2621,   2633,   2647,   2657,   2659,   2663,   2671,   2677,   2683,   2687, 
                                2689,   2693,   2699,   2707,   2711,   2713,   2719,   2729,   2731,   2741, 
                                2749,   2753,   2767,   2777,   2789,   2791,   2797,   2801,   2803,   2819, 
                                2833,   2837,   2843,   2851,   2857,   2861,   2879,   2887,   2897,   2903, 
                                2909,   2917,   2927,   2939,   2953,   2957,   2963,   2969,   2971,   2999, 
                                3001,   3011,   3019,   3023,   3037,   3041,   3049,   3061,   3067,   3079, 
                                3083,   3089,   3109,   3119,   3121,   3137,   3163,   3167,   3169,   3181, 
                                3187,   3191,   3203,   3209,   3217,   3221,   3229,   3251,   3253,   3257, 
                                3259,   3271,   3299,   3301,   3307,   3313,   3319,   3323,   3329,   3331, 
                                3343,   3347,   3359,   3361,   3371,   3373,   3389,   3391,   3407,   3413, 
                                3433,   3449,   3457,   3461,   3463,   3467,   3469,   3491,   3499,   3511, 
                                3517,   3527,   3529,   3533,   3539,   3541,   3547,   3557,   3559,   3571, 
                                3581,   3583,   3593,   3607,   3613,   3617,   3623,   3631,   3637,   3643, 
                                3659,   3671,   3673,   3677,   3691,   3697,   3701,   3709,   3719,   3727, 
                                3733,   3739,   3761,   3767,   3769,   3779,   3793,   3797,   3803,   3821, 
                                3823,   3833,   3847,   3851,   3853,   3863,   3877,   3881,   3889,   3907, 
                                3911,   3917,   3919,   3923,   3929,   3931,   3943,   3947,   3967,   3989, 
                                4001,   4003,   4007,   4013,   4019,   4021,   4027,   4049,   4051,   4057, 
                                4073,   4079,   4091,   4093,   4099,   4111,   4127,   4129,   4133,   4139, 
                                4153,   4157,   4159,   4177,   4201,   4211,   4217,   4219,   4229,   4231, 
                                4241,   4243,   4253,   4259,   4261,   4271,   4273,   4283,   4289,   4297, 
                                4327,   4337,   4339,   4349,   4357,   4363,   4373,   4391,   4397,   4409, 
                                4421,   4423,   4441,   4447,   4451,   4457,   4463,   4481,   4483,   4493, 
                                4507,   4513,   4517,   4519,   4523,   4547,   4549,   4561,   4567,   4583, 
                                4591,   4597,   4603,   4621,   4637,   4639,   4643,   4649,   4651,   4657, 
                                4663,   4673,   4679,   4691,   4703,   4721,   4723,   4729,   4733,   4751, 
                                4759,   4783,   4787,   4789,   4793,   4799,   4801,   4813,   4817,   4831, 
                                4861,   4871,   4877,   4889,   4903,   4909,   4919,   4931,   4933,   4937, 
                                4943,   4951,   4957,   4967,   4969,   4973,   4987,   4993,   4999,   5003, 
                                5009,   5011,   5021,   5023,   5039,   5051,   5059,   5077,   5081,   5087, 
                                5099,   5101,   5107,   5113,   5119,   5147,   5153,   5167,   5171,   5179, 
                            };

int a,b,p;

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize() {
////////////////// DHMIOURGIA tou sentinelNode gia to playersTree///////////////////
sentinelNode = (playerTree*)malloc(sizeof(playerTree));
sentinelNode->pid = -1;
sentinelNode->is_alien = 0;
sentinelNode->evidence = 0;
sentinelNode->rc =NULL;
sentinelNode->lc = NULL;
sentinelNode->parrent = NULL;
players_tree = sentinelNode;
////////////END Dhmiourgia toy sentinelNode gia to playersTree////////////////////////////

//////////// PRAgmata gia ton katakermatismo kai thn hash function///////////////////
// desmevw mnhmh gia to task,analoga me to max_tasks_g
general_tasks_ht.tasks = (struct HT_Task**)malloc(max_tasks_g*sizeof(struct HT_Task *));
//vazw 11 dioti tha einai to m,dhladh h hash function tha bgazei 11 diaforetikes times gia thn thesi ston pinaka task
for(int k = 0; k<11;k++) {
    general_tasks_ht.tasks[k] = (struct HT_Task*)malloc(max_tasks_g*sizeof(struct HT_Task));
}

general_tasks_ht.count = 0;
//vriskw to p
 p = findPrime_g(max_tid_g);
// tuxaios arithmos a sto {1,...,p-1}
a = (rand() % ((p-1)-1+1))+1;
// tuxaios arithmos b sto {0,...,p-1}
b = (rand() % ((p-1)-0+1)) + 0;
///////////END Pragmata gia ton katakermatismo aki thn hash function/////////////////

////////// OURA PROTEREOTITAS////////////////
//completed_tasks_pq.tasks = (struct HT_Task*)malloc(max_tasks_g*sizeof(struct HT_Task));



///////// END OURA PROTEREOTITAS///////////////
    return 1;
}

/**
 * @brief Register Player
 * diatrexw to dentro twn Players kai vriskw thn katallhlh thesh gia ton player me pid
 * O(h) opou h to u4os toy dentroy -> O(logn)
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien) {
    playerTree *temp = players_tree;
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
    temp->evidence = 0;
    return 1;
}

}
playerTree *new;
new = (playerTree*)malloc(sizeof(playerTree));
new->pid = pid;
new->is_alien = is_alien;
new->evidence = 0;
new->rc = sentinelNode;
new->lc = sentinelNode;
if(Prev!=NULL) {
    if(Prev->pid < pid) {
        Prev->rc = new;
    } else {
        Prev->lc = new;
    }
new->parrent = Prev;
}else {
    new->parrent = sentinelNode;
    players_tree = new;
    printTree(players_tree);
    return 1;
}

printTree(players_tree);
return 1;
}

/**
 * @brief Insert Task in the general task hash table
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid, int difficulty) {
    struct HT_Task *task;
    task = (struct HT_Task*)malloc(sizeof(struct HT_Task));
    task->difficulty = difficulty;
    task->tid = tid;
    task->next  = NULL;
    int thesi = hashFunction(a,b,p,11,task->tid);
    if(general_tasks_ht.tasks[thesi] !=NULL) {
        struct HT_Task *temp = general_tasks_ht.tasks[thesi];

        struct HT_Task *prev =NULL;
        while(temp!=NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = task;
    } else {
        general_tasks_ht.tasks[thesi] = task;
    }
    general_tasks_ht.count++;
    for(int k = 0 ; k < 11 ; k++) {
        struct HT_Task *tmp = general_tasks_ht.tasks[k];
        tmp = tmp->next;
        printf("Chain %d: ",k);
        while(tmp!=NULL) {
            printf("<%d,%d>,",tmp->tid,tmp->difficulty);
            tmp = tmp->next;
        }
        printf("\n");
    }
    return 1;
}

/**
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */

int distribute_tasks() {
    distributeTasks(players_tree);

    

    return 1;
}

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param tid The task's tid
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int tid) {
    playerTree *player = findPlayerWith(players_tree,pid);
    if(player==NULL) {
        printf("Den vrethike paikths me pid: %d\n",pid);
        return 1;
    }
    player = deleteTask(tid,player);
    printPlayersForTasks(players_tree);

    return 1;
}
/**
 * @brief finds player in playerTree with his pid
 * O(h) -> O(logn)
 * */
    playerTree *findPlayerWith(playerTree* T,int pid) {
       playerTree *tmp = T;
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
/**
 * delete the task with tid from player T
 * */
playerTree* deleteTask(int tid,playerTree *T) {
struct Task* tmp = T->tasks;
struct Task* Prev = NULL;
int isTaskValid = 0;
while(tmp!=NULL) {
   // Prev = tmp;
    if(tmp->tid == tid) {
        isTaskValid = 1;
        
        struct HT_Task* copyTemp;
        copyTemp = (struct HT_Task*)malloc(sizeof(struct HT_Task));
        copyTemp->difficulty = tmp->difficulty;
        copyTemp->tid = tmp->tid;
        copyTemp->next = NULL;
        insertCompletedTasks(copyTemp);


        if(tmp->rc==NULL && tmp->lc==NULL) {
            if(Prev == NULL) {
                T->tasks = NULL;
                break;
            }
            if(Prev->tid < tmp->tid) {
                Prev->rc = NULL;
            } else {
                Prev->lc = NULL;
            }
            free(tmp);
            break;
        }
        if(tmp->rc==NULL) {
            struct Task *new = tmp->lc;
            if(Prev == NULL) {
                T->tasks = new;
            } else {
            Prev->lc = new;
            free(tmp);
            }
            break;
            
        } else if(tmp->lc==NULL) {
            struct Task *new = tmp->rc;
            if(Prev==NULL) {
                T->tasks=new;
            }else {
            Prev->rc = new;
            free(tmp);
            }
            break;
        } else {
            struct Task *successorParent = tmp;
            struct Task *successor = tmp->rc;
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
if(isTaskValid == 0) {
    tmp = T->tasks;
    
    while(tmp!=NULL) {
        if(tmp->tid < tid) {
            tmp = tmp->rc;
        } else if(tmp->tid > tid) {
            tmp->lcnt++;
            tmp=tmp->lc;
        }
    }
}
return T;


}

/**
 * @brief inserts a task in Completed Queue
 * Θ(1) h O(logn)
 * */
void insertCompletedTasks(struct HT_Task *task) {
    int m;
if(completed_tasks_pq.size == max_tasks_g) {
    printf("Error\n");
    exit(-1);
}
m = completed_tasks_pq.size;
while(m>0 && task->difficulty > completed_tasks_pq.tasks[(m-1)/2].difficulty) {
    completed_tasks_pq.tasks[m].difficulty = completed_tasks_pq.tasks[(m-1)/2].difficulty;
    completed_tasks_pq.tasks[m].tid = completed_tasks_pq.tasks[(m-1)/2].tid;
    m = (m-1)/2;
}
completed_tasks_pq.tasks[m].difficulty = task->difficulty;
completed_tasks_pq.tasks[m].tid = task->tid;
completed_tasks_pq.size++;

}

/**
 * give Tasks T1 in player T2
 * */
void giveTask(struct Task *T1,playerTree *T2) {
    struct Task*tmp = T1;

if(tmp==NULL) {
    return; 
}
giveTask(tmp->lc,T2);
insertTask(tmp->tid,tmp->difficulty,T2->tasks);
giveTask(tmp->rc,T2);
}
/**
 * @brief Eject Player
 * 
 * @param pid_1 The ejected player's id
 *
 * @param pid_2 The crewmates id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid_1, int pid_2) {
    playerTree *tmp = players_tree;
    playerTree *playerToGiveTasks = findPlayerWith(players_tree,pid_2);
        while(tmp!=sentinelNode) {
        if(pid_1 < tmp->pid) {
            tmp = tmp->lc;

        } else if(pid_1 > tmp->pid) {
            tmp=tmp->rc;
        }else {
            // dinw ta task tou paikth me pid_1 ston paikth  me pid_2
            giveTask(tmp->tasks,playerToGiveTasks);
            
        if(tmp->rc== sentinelNode && tmp->lc== sentinelNode) {
               if(tmp->parrent->pid < tmp->pid) {
                tmp->parrent->rc = sentinelNode;
            } else {
                tmp->parrent->lc = sentinelNode;
            }
            free(tmp);
            break;
        }
        if(tmp->rc==sentinelNode) {
            playerTree *new = tmp->lc;
            //Prev->lc = new;
            tmp->parrent->lc = new;
            free(tmp);
            break;
            
        } else if(tmp->lc==sentinelNode) {
            playerTree *new = tmp->rc;
            //Prev->rc = new;
            tmp->parrent->rc = new;
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
        }


}
 printPlayersForTasks(players_tree);
    return 1;
}
/**
 * @brief diagrafw ton paikth me pid apo to dentro paiktwn
 * 
 * O(h) opou h to u4os toy dentroy -> O(logn)
 * */
playerTree *deletePlayer(int pid,playerTree*T) {
playerTree* tmp = T;
while(tmp!=sentinelNode) {
    if(tmp->pid == pid) {
        if(tmp->rc== sentinelNode && tmp->lc== sentinelNode) {
               if(tmp->parrent->pid < tmp->pid) {
                tmp->parrent->rc = sentinelNode;
            } else {
                tmp->parrent->lc = sentinelNode;
            }
            free(tmp);
            break;
        }
        if(tmp->rc==sentinelNode) {
            playerTree *new = tmp->lc;
            tmp->parrent->lc = new;
            free(tmp);
            break;
            
        } else if(tmp->lc==sentinelNode) {
            playerTree *new = tmp->rc;
            tmp->parrent->rc = new;
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

        tmp = tmp->rc;
    } else {

        tmp = tmp->lc;
    }



}
return T;



}

/**
 * @brief Witness Eject Player
 *
 * @param pid_1 The ejected player's id
 * 
 * @param pid_2 The crewmate's pid
 *
 * @param pid_a The alien's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses){
    findPlayerWith(players_tree,pid_a)->evidence +=number_of_witnesses; 

  playerTree *tmp = players_tree;
    playerTree *playerToGiveTasks = findPlayerWith(players_tree,pid_2);
    giveTask(findPlayerWith(players_tree,pid_1)->tasks,playerToGiveTasks);
    deletePlayer(pid_1,players_tree);
        
printEvidenceAndTasks(players_tree);
    return 1;
}

/**
 * @brief Sabotage
 *
 * @param number_of_tasks The number of tasks to be sabotaged
 *
 * @param pid The player's id
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabotage(int number_of_tasks, int pid) {
    return 1;
}

/**
 * @brief Vote
 *
 * @param pid_1 The suspicious player's id
 *
 * @param pid_2 The crewmate's pid
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid_1, int pid_2, int vote_evidence) {
    playerTree *player;
    //vriskw ton paikth me pid_1
    player = findPlayerWith(players_tree,pid_1);

    player->evidence = player->evidence + vote_evidence;
    // briskw ton paikth me to perissotero evidence
    playerTree *playerWithMoreEvidence =  MoreEvidence(players_tree);    
    // dinw ta task tou paikth me to perissotero evidence ston paikth me pid_1 
    giveTask(playerWithMoreEvidence->tasks,player);
    deletePlayer(playerWithMoreEvidence->pid,players_tree);

    


        printEvidenceAndTasks(players_tree);


    return 1;
}
void printEvidenceAndTasks(playerTree* T) {
    playerTree* tmp = T;
    if(tmp==sentinelNode) {
        return;
    }
    printEvidenceAndTasks(tmp->lc);
    printf("Player:<%d,%d> =",tmp->pid,tmp->evidence); 
    printTasks(tmp->tasks);
    printf("\n");

    printEvidenceAndTasks(tmp->rc);
}
/**
 * @brief vriskw ton paikth me to perissotero evidence
 * */
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
/**
 * @brief Give Away Work
 *
 * @param pid_1 The existing crewmate's id
 *
 * @param pid_2 The new crewmate's pid
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work(int pid_1, int pid_2) {
    return 1;
}

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate() {
int impostors = checkHowManyImpostors(players_tree);
int people = checkHowManyPeople(players_tree);
if(impostors > people) {
    printf("Aliens win\n");
    return 1;
}
if(general_tasks_ht.count == completed_tasks_pq.size) {

   printf("Crewmates win\n");
   return 1;
}
if(impostors==0 ) {
   printf("Crewmates win\n");
}
    return 1;
}
int checkHowManyImpostors(playerTree *T) {
    playerTree * tmp = T;
    static int impostors=0;
    if(tmp == sentinelNode) {
        return impostors ;
    }
    checkHowManyImpostors(tmp->lc);
    if(tmp->is_alien==1) {
        impostors++;
    }
    checkHowManyImpostors(tmp->rc);

}

int checkHowManyPeople(playerTree *T) {
    playerTree * tmp = T;
    static int people=0;
    if(tmp == sentinelNode) {
        return people ;
    }
    checkHowManyPeople(tmp->lc);
    if(tmp->is_alien==0) {
       people++;
    }
    checkHowManyPeople(tmp->rc);

}
/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players() {
    
    printf("Players = ");
       printTree(players_tree);
    return 1;
}

/**
 * @brief Prints Players with recursion
 * */
void printTree(playerTree *T) {
       playerTree *tmp = T;

    if(tmp->pid == sentinelNode->pid) {
        return ;
    }
    printTree(tmp->lc);
    
    printf(" <%d : %d>",tmp->pid,tmp->is_alien);
    printTree(tmp->rc);
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks() {
     for(int k = 0 ; k < 11 ; k++) {
        struct HT_Task *tmp = general_tasks_ht.tasks[k];
        tmp = tmp->next;
        printf("Index %d: ",k);
        while(tmp!=NULL) {
            printf("<%d,%d>,",tmp->tid,tmp->difficulty);
            tmp = tmp->next;
        }
        printf("\n");
    }
    return 1;
}
/**
 * @brief sunartisi gia na tupwnw tous players otan theloume na typwsoyme kai ta tasks mazi
 * */

void printPlayersForTasks(playerTree *T) {

    playerTree *tmp = T;
    if(tmp->pid == sentinelNode->pid) {
        return ;
    }
    printPlayersForTasks(tmp->lc);
    printf("Player %d = ",tmp->pid);
    printTasks(tmp->tasks);
    printf("\n");

    printPlayersForTasks(tmp->rc);
    return ;
}
/**
 * @brief prints ta task enos paikth
 * */

void printTasks(struct Task *T) {
    struct Task* tmp = T;
if(tmp==NULL) {
    return;
}
printTasks(tmp->lc);
printf("<%d,%d> ",tmp->tid,tmp->difficulty);

printTasks(tmp->rc);

}


/**
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq() {
    printf("Completed Tasks = ");
    for(int k = 0 ; k < completed_tasks_pq.size;k++) {
        printf("<%d,%d> ",completed_tasks_pq.tasks[k].tid,completed_tasks_pq.tasks[k].difficulty);
    }
    printf("\n");
    return 1;
}

/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree() {
printPlayersForTasks(players_tree);
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void) {
    return 1;
}
// h synarthsh epistrefei enan akeraio poy anhkei {0,...,m-1}
// to p  einai enas arithmos apo ton pinaka,opoy prepei na einai o epomenos megaluteros  apo to max_tid_g
// to a kai to b tha einai tuxaioi arithmoi opoy aE{1,...,p-1} kai bE{0,....,p-1}
// to m einai poses theseis thelw na exei o pinakas katakermatismou.
//x tha einai to tid.
int hashFunction(int a,int b,int p , int m,int x) {
    
    return ((a*x+b) % p) % m;

}


/**
 * @brief finds the prime number for p for hash function from primes_g
 * */
int findPrime_g(int number) {
    int median;
int high = 650;
int low = 0;
int counter = 0;
int prevMedian;
while(high!=low) {
    prevMedian = median;
    median = (high+low)/2;
    if(prevMedian == median) {
        counter = 1;

    }
    if(counter==1) {
        return primes_g[median+1];
    }
if(number>primes_g[median]) {
low = median ;
 

} else if (number<primes_g[median]) {
high = median;    
} else {
    return number;
}
}
return -1;
}
/**
 * @brief distribute tasks to players 
 * */
playerTree *distributeTasks(playerTree *player) {
static int counterToStopTasks=2;
  if(player == sentinelNode || (player->is_alien==1 && player->rc==sentinelNode && player->lc == sentinelNode) || (counterToStopTasks > general_tasks_ht.count-1)) {
      return NULL;
  }
static int indexForHashTable=0;
static int indexForChain=0;
distributeTasks(player->lc);
if(player->is_alien!=1) {

    struct HT_Task *temp = findTaskFromGeneralList(&indexForHashTable,&indexForChain);
    player->tasks = insertTask(temp->tid,temp->difficulty,player->tasks);
    counterToStopTasks++;


}
distributeTasks(player->rc);
if(player == players_tree) {
distribute_tasks(players_tree);
}
return NULL;
} 

/**
 * @brief finds the next task to distribute to player
 * */
struct HT_Task* findTaskFromGeneralList(int *indexForHashTable,int *indexForChain) {
    struct HT_Task* temp=general_tasks_ht.tasks[*indexForHashTable]->next;
       

    int k = 0;
    while(k < *indexForChain) {
        temp = temp->next;
        k++;
    }
    if(temp==NULL) {
        *indexForHashTable = *indexForHashTable + 1;
         *indexForChain = 0;
        return findTaskFromGeneralList(indexForHashTable,indexForChain);
    }
    *indexForChain = *indexForChain + 1;
    return temp;
}
/**
 * @brief inserts a task to a struct Task 
 * */
struct Task *insertTask(int tid,int dif,struct Task *T) {
    struct Task *temp,*Prev;
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
    struct Task *newCell;
    newCell = (struct Task*)malloc(sizeof(struct Task));
    newCell->difficulty = dif;
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
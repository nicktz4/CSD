/***************************************************
 *                                                 *
 * file: among_us.c                                *
 *                                                 *
 * @Author  Antonios Peris                         *
 * @Version 20-10-2020                             *
 * @email   csdp1196@csd.uoc.gr                    *
 *                                                 *
 * @brief   Implementation of among_us.h           *
 *                                                 *
 ***************************************************
 */
/***************************************************
 *                                                 *
 *                                                 *
 *   file: among_us.c                              *
 *   Nikos Tzanakis                                *
 * @Version 17-11-2020                             *
 * @email   csd4349@csd.uoc.gr                     *
 *                                                 *
 * @brief  fill in the functions to create         *
 *          among_us Project for cs240 Phase A     *
 *                                                 *
 *                                                 *
 ***************************************************
 */
#include "among_us.h"

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize() {
    numberOfPlayers = 0;
   //-------------------DoubleList---------------------- 

    players_head = (struct Players*)malloc(sizeof(struct Players));
    if(players_head==NULL) {
        return 0;
    }
    players_head->pid = -1;
    players_head->is_alien = -1;
    players_head->evidence= -1;
    players_head->next = NULL;
    players_head->prev = NULL;
    players_head->tasks_head= NULL;
    players_head->tasks_sentinel = NULL;

   //----------------END DoubleList---------------------

   //----------------TasksWithSentinel------------------

    
   //----------------END TasksWithSentinel--------------

   //----------------TASK LIST--------------------------
    tasks_head = (struct Head_GL*)malloc(sizeof(struct Head_GL));
    if(tasks_head==NULL) {
        return 0;
    }
    tasks_head->tasks_count[0] = 0;

    tasks_head->tasks_count[1] = 0;
    tasks_head->tasks_count[2] = 0;
   //---------------- END TASK LIST---------------------

   //---------------- StackList-------------------------
    tasks_stack = (struct Head_Completed_Task_Stack*)malloc(sizeof(struct Head_Completed_Task_Stack));
    if(tasks_stack==NULL) {
        return 0;
    }
    tasks_stack->count = 0;
   //---------------- END StackList---------------------
    return 1;
}

/**
 * @brief Register player
 *  ftiaxnw enan node struct Players me pid kai is alien kai ta alla default
 * sundew thn dipla kuklikh lista 
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid,int is_alien) {
    
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
    if(sentinelNode==NULL) {
        print_players();
        return 0;
    }

    sentinelNode->tid = -1;

    sentinelNode->difficulty = 0;

    sentinelNode->next = NULL;
    
    player->tasks_sentinel = sentinelNode;
    player->tasks_head = sentinelNode;

    if(players_head->next!=NULL) {
    players_head->prev->next=player;
    player->prev = players_head->prev;
    player->next = players_head;
    }else {
        
        players_head->next = player;
        player->next = players_head;
        player->prev = players_head;
    }

    players_head->prev = player;
    

    print_players();

    numberOfPlayers++;
    return 1;
}

/**
 * @brief Insert task in the general task list
 * vazw to task me tid kai difficulty sthn genikh lista,ta3inomhmena
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid,int difficulty) {
    Tasks *newTask;
    newTask =(Tasks*)malloc(sizeof(Tasks));
    if(newTask ==NULL) {
        print_tasks();
        return 0;
    }
    newTask->tid = tid;
    newTask->difficulty = difficulty;
    tasks_head->tasks_count[difficulty-1]++;

    if(tasks_head->head == NULL) {
        tasks_head->head = newTask;
        print_tasks();
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
            print_tasks();
            return 1;
        }
            if(tmpP1->next == NULL ) {
                tmpP1->next = newTask;
                print_tasks();
                return 1;
            }
            tmpP2 = tmpP1;
            tmpP1 = tmpP1->next;

        }
        print_tasks();
        return 0;
}

/**
 * @brief Distribute tasks to the players
 * arxika ftiaxnw mia while mexri na moirasw ola ta task.
 * sth sunexeia diatrexw thn lista kai ftiaxnw kainourgia nodes idia me afta sthn genikh lista gia  ta task
 * epeidh einai ta3inomhmena hdh sthn genikh lista den xreiazetai na ftia3w kapoion eidiko algorithmo apla ta vazw ola sto telos
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks() {
    struct Players *tmp = players_head->next;//deixnei sto 1o paikth
    int tasksToAssign=tasks_head->tasks_count[0]+tasks_head->tasks_count[1]+tasks_head->tasks_count[2];
    int counterToTasksToAssign = 0;
    
    Tasks *tmpGeneralList = tasks_head->head; //deixnei sto 1o stoixeio ths general task list

    
    while(counterToTasksToAssign < tasksToAssign) {
            if(tmp->is_alien==0) {
        Tasks *newTask;
        newTask = (Tasks*)malloc(sizeof(Tasks));
        if(newTask==NULL) {
            return 0;
        }

        newTask->difficulty = tmpGeneralList->difficulty;
        newTask->tid = tmpGeneralList->tid;
        if(tmp->tasks_sentinel->next == NULL) {
            tmp->tasks_sentinel->next = newTask;
            tmp->tasks_head = newTask;
            newTask->next = tmp->tasks_sentinel;
        } else {
        tmp->tasks_sentinel->next->next = newTask;
        tmp->tasks_sentinel->next = newTask;
        newTask->next = tmp->tasks_sentinel;
            }
        tmp = tmp->next;
        tmpGeneralList = tmpGeneralList->next;
        
        counterToTasksToAssign++;

        } else {
            tmp = tmp->next;
        }

    }
    print_double_list(); 
    return 1;
}

/**
 * @brief Implement Task
 *Psaxnw ton paikth me pid kai otan vre8ei diasxizw thn list me ta task tou mexri na vrw ena me duskolia difficulty
 To kanw Push sthn stoiva,kai to diagrafw apo to task list tou paikth.An den vrw task me tetoia duskolia,diagrafw afto poy deixnei o task_sentinel
 * @param pid The player's id
 *
 * @param difficulty The task's difficuly
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int difficulty) {
 struct Players *tmp = players_head->next;
    while(tmp!=players_head) {
       
        if(tmp->pid==pid) {
        Tasks *tmpTasks = tmp->tasks_head;
        Tasks *tmpTasks2 = NULL;
        while(tmpTasks != tmp->tasks_sentinel) {
            if(tmpTasks->difficulty == difficulty) {
                //an to 1o task einai duskolias difficulty
                if(tmpTasks2 == NULL)  {
                    Push(tmpTasks);
                    tmp->tasks_head = tmpTasks->next;
                    // an to task sentinel deixnei sto tmpTasks shmainei oti einai o teleutaios komvos kai meta to task_sentinel deixnei se NULL
                    if(tmp->tasks_sentinel->next == tmpTasks) {
                        tmp->tasks_sentinel->next=NULL;
                    }

                    tmpTasks->next = NULL;
                    print_double_list();
                    return 1;
                } else {
                Push(tmpTasks);
                tmpTasks2->next = tmpTasks->next;
                if(tmp->tasks_sentinel->next == tmpTasks) {// ta evala meta
                        tmp->tasks_sentinel->next=tmpTasks2;//
                    }//
                tmpTasks->next = NULL;
                print_double_list();
                return 1;

            }
            tmpTasks2 = tmpTasks;
            tmpTasks = tmpTasks->next;
        }
        // sth periptwsh poy ftasoume sto teleutaio task diagrafoume auto
        if(tmpTasks->next==tmp->tasks_sentinel) {
            
               Push(tmpTasks);
               if(tmp->tasks_head!=tmp->tasks_sentinel) {
                   if(tmpTasks2!=NULL) {
                   tmpTasks2->next = tmpTasks->next;
                   tmp->tasks_sentinel->next = tmpTasks2;//twra to evala
                   }else {
                       tmp->tasks_head = tmp->tasks_sentinel;
                       tmp->tasks_sentinel->next = NULL;//twra to evala

                   }
                   tmpTasks->next = NULL;
                   print_double_list();
                   return 1;
               }

               }
        tmpTasks2 = tmpTasks;
        tmpTasks = tmpTasks->next;


        }
        if(tmpTasks==tmp->tasks_sentinel) {
            print_double_list();
            return 1;
        }
        }
         if(tmp->next== players_head) {
            printf("Player not found\n");
            print_double_list();
            return 0;
        }
             tmp = tmp->next;
        
    }
    return 0;
}

/**
 * @brief Eject Player
 * Arxika diasxizw thn lista,vriskontas ton paikth me pid.Ton diagrafw apo thn lista alla krataw enan pointer poy deixnei sto komvo toy
 * Epishs,vriskw ton paikth me ta ligotera task tautoxrona
 * Meta me ton  algorithmo poy xrisimopoiw gia na dwsw tasks stous players,dinw ta task ston paikth me ta ligotera task
 * @param pid The ejected player's id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid) {
    
    struct Players *tmpPlayers = players_head->next; //deixnei ston prwto paikth
    
    struct Players *minTasksPlayer;
    int minimumTasks = tasks_head->tasks_count[0]+tasks_head->tasks_count[1]+tasks_head->tasks_count[2];
    struct Players *playerToDelete=NULL;;
    while(tmpPlayers!=players_head)  {

        if(tmpPlayers->pid==pid){
            tmpPlayers->prev->next=tmpPlayers->next;
            tmpPlayers->next->prev=tmpPlayers->prev;
            if(tmpPlayers->tasks_head==tmpPlayers->tasks_sentinel) {
                printf("Player does not have any Tasks\n");
                print_double_list();
            return 1;

            }
            playerToDelete = tmpPlayers;
            //diagrafoume to node apo thn lista.
        
    
    
        } else {
    Tasks *tmpTasks = tmpPlayers->tasks_head;
    int taskCounter=0;
    
    while(tmpTasks!=tmpPlayers->tasks_sentinel) {

        taskCounter++;
        tmpTasks = tmpTasks->next;

    }
    if(taskCounter < minimumTasks && tmpPlayers->is_alien!=1) {
        minTasksPlayer = tmpPlayers;
        minimumTasks = taskCounter;
    }
        }

    tmpPlayers = tmpPlayers->next;
    }
    if(playerToDelete==NULL) {
        printf("Player not found\n");
        print_double_list();
        return 0;
    }
    //-----------------END FINDING Minimum----------------------

    Tasks *tmpPlayerToDeleteTasks = playerToDelete->tasks_head ; // pointer sta task tou player poy diagrafoume
    Tasks *tmpMinimumPlayerTasks = minTasksPlayer->tasks_head;    //pointer sta task  toy player poy tha ta dwsoume
    
    while(tmpPlayerToDeleteTasks!=playerToDelete->tasks_sentinel) { //mexri na ftasoume sto sentinel toy playertoDelete
        

        Tasks *newCell;
        newCell = (Tasks*)malloc(sizeof(Tasks));
    
        
        if(newCell==NULL) {
            print_double_list();
            return 0;
        }
    
        newCell->difficulty = tmpPlayerToDeleteTasks->difficulty;
        newCell->tid = tmpPlayerToDeleteTasks->tid;
    
      
    //an to dif tou einai 1 , tote to vazw sthn arxh(sto task head)
        if(newCell->difficulty==1) {
            newCell->next = minTasksPlayer->tasks_head;
            minTasksPlayer->tasks_head = newCell;

        }
        //an to dif toy einai 3 , tote to vazw sto telos(prin to sentinel)
        if(newCell->difficulty==3) {
            newCell->next = minTasksPlayer->tasks_sentinel;
            if(minTasksPlayer->tasks_sentinel->next!=NULL) {
            minTasksPlayer->tasks_sentinel->next->next=newCell;
            } else {

                minTasksPlayer->tasks_head=newCell;
            }

            minTasksPlayer->tasks_sentinel->next = newCell;
        }
 

       if(newCell->difficulty==2) {
           if(tmpMinimumPlayerTasks==minTasksPlayer->tasks_sentinel) {
               newCell->next = minTasksPlayer->tasks_sentinel;
               minTasksPlayer->tasks_head = newCell;
               minTasksPlayer->tasks_sentinel->next=newCell;

           } else {
            while(tmpMinimumPlayerTasks!=minTasksPlayer->tasks_sentinel) {//oso einai diaforetiko apo to task sentinel
                if(tmpMinimumPlayerTasks->next==minTasksPlayer->tasks_sentinel) {
                    newCell->next = minTasksPlayer->tasks_sentinel;
                    tmpMinimumPlayerTasks->next = newCell;
                    minTasksPlayer->tasks_sentinel->next = newCell;
                    break;
                } 
                if(tmpMinimumPlayerTasks->difficulty == 2 ) {
                    newCell->next = tmpMinimumPlayerTasks->next;
                    tmpMinimumPlayerTasks->next = newCell;
                    break;
                }
                if(tmpMinimumPlayerTasks->next->difficulty == 3) {
                newCell->next = tmpMinimumPlayerTasks->next;
                tmpMinimumPlayerTasks->next = newCell;
                break;

            }
            tmpMinimumPlayerTasks = tmpMinimumPlayerTasks->next;

           }
           }
            tmpMinimumPlayerTasks = minTasksPlayer->tasks_head; // otan vazw enan komvo sto min Tasks player,3anaarxizw apo thn arxh toy minPlayer tasks
        } 
        
     tmpPlayerToDeleteTasks = tmpPlayerToDeleteTasks->next;   //pame sto epomeno task toy Deleted paikth
    }
    print_double_list();
    return 1;
}

/**
 * @brief Witness Eject Player
 * opws to eject_player alla prosthetw kai number_of_witnesses ston impostor sto evidence, me pid_a
 * @see eject_player()
 * @param pid_a The alien's pid
 * 
 * @param pid The crewmate's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid, int pid_a, int number_of_witnesses){
     struct Players *tmpPlayers = players_head->next; //deixnei ston prwto paikth
    
    struct Players *minTasksPlayer;
    int minimumTasks = tasks_head->tasks_count[0]+tasks_head->tasks_count[1]+tasks_head->tasks_count[2];
    struct Players *playerToDelete=NULL;;
    while(tmpPlayers!=players_head)  {
        if(tmpPlayers->pid ==pid_a) {
            // elegxw an o player me pid_a einai alien
                if(tmpPlayers->is_alien!=1) {
                    printf("Player with pid: %d is not an alien",tmpPlayers->pid);
                    print_double_listForW();
                    return 0;
                }
            tmpPlayers->evidence = tmpPlayers->evidence + number_of_witnesses;
        }
        if(tmpPlayers->pid==pid){
            tmpPlayers->prev->next=tmpPlayers->next;
            tmpPlayers->next->prev=tmpPlayers->prev;
            if(tmpPlayers->tasks_head==tmpPlayers->tasks_sentinel) {
                printf("Player does not have any Tasks\n");
                print_double_listForW();
            return 1;

            }
            playerToDelete = tmpPlayers;
            //diagrafoume to node apo thn lista.
        
    
    
        } else {
    Tasks *tmpTasks = tmpPlayers->tasks_head;
    int taskCounter=0;
    
    while(tmpTasks!=tmpPlayers->tasks_sentinel) {

        taskCounter++;
        tmpTasks = tmpTasks->next;

    }
    if(taskCounter < minimumTasks && tmpPlayers->is_alien!=1) {
        minTasksPlayer = tmpPlayers;
        minimumTasks = taskCounter;
    }
        }

    tmpPlayers = tmpPlayers->next;
    }
    if(playerToDelete==NULL) {
        printf("Player not found\n");
        return 0;
    }
    //-----------------END FINDING Minimum----------------------

    Tasks *tmpPlayerToDeleteTasks = playerToDelete->tasks_head;
    Tasks *tmpMinimumPlayerTasks = minTasksPlayer->tasks_head;    
    
    while(tmpPlayerToDeleteTasks!=playerToDelete->tasks_sentinel) {
        

        Tasks *newCell;
        newCell = (Tasks*)malloc(sizeof(Tasks));
    
        
        if(newCell==NULL) {
            print_double_listForW();
            return 0;
        }
    
        newCell->difficulty = tmpPlayerToDeleteTasks->difficulty;
        newCell->tid = tmpPlayerToDeleteTasks->tid;
    
      
    
        if(newCell->difficulty==1) {
            newCell->next = minTasksPlayer->tasks_head;
            minTasksPlayer->tasks_head = newCell;

        }
        if(newCell->difficulty==3) {
            newCell->next = minTasksPlayer->tasks_sentinel;
            if(minTasksPlayer->tasks_sentinel->next!=NULL) {

            minTasksPlayer->tasks_sentinel->next->next=newCell;
            } else {
                minTasksPlayer->tasks_head=newCell;
            }

            minTasksPlayer->tasks_sentinel->next = newCell;
        }
        if(newCell->difficulty==2) {
            // an to minTasksPlayer den exei katholoy tasks
            if(tmpMinimumPlayerTasks==minTasksPlayer->tasks_sentinel) {
                newCell->next = minTasksPlayer->tasks_sentinel;
                minTasksPlayer->tasks_head = newCell;
                minTasksPlayer->tasks_sentinel->next = newCell;

            } else {
            while(tmpMinimumPlayerTasks!=minTasksPlayer->tasks_sentinel) {
                if(tmpMinimumPlayerTasks->next==minTasksPlayer->tasks_sentinel) {
                    newCell->next = minTasksPlayer->tasks_sentinel;
                    tmpMinimumPlayerTasks->next = newCell;
                    minTasksPlayer->tasks_sentinel->next = newCell;
                    break;
                }
                if(tmpMinimumPlayerTasks->difficulty == 2 ) {
                    newCell->next = tmpMinimumPlayerTasks->next;
                    tmpMinimumPlayerTasks->next = newCell;
                    break;
                }
                if(tmpMinimumPlayerTasks->next->difficulty == 3) {
                        newCell->next = tmpMinimumPlayerTasks->next;
                        tmpMinimumPlayerTasks->next = newCell;
                        break;
                }
                //shmainei oti o minTasksPlayer exei ena node me dif 3
                if(tmpMinimumPlayerTasks->difficulty==3) {
                    newCell->next = tmpMinimumPlayerTasks;
                    minTasksPlayer->tasks_head = newCell;
                    break;
                }
                tmpMinimumPlayerTasks = tmpMinimumPlayerTasks->next;

            }
            }
            tmpMinimumPlayerTasks = minTasksPlayer->tasks_head;
        }
        
     tmpPlayerToDeleteTasks = tmpPlayerToDeleteTasks->next;   
    }
    print_double_listForW();
    return 1;
}


/**
 * @brief Sabbotage
 *Arxika vriskw ton paikth poy einai number_of_tasks/2 8eseis aristera.
 Diatrexw mia fora thn lista mexri na vrw ton pid,kai meta vriskw ton paikth p (targetPlayer)
 Kai sth sunexeia moirazw ta task

 * @param pid The player's id
 *
 * @param number_of_tasks The number of tasks to be popped
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabbotage(int pid, int number_of_tasks) {
    int numberofTasks_2 = number_of_tasks/2; //gia na vrw ton paikth number_of_tasks/2 theseis aristera
    struct Players *targetPlayer=NULL; // o player p
    
        
    struct Players *tmpPlayer;
    tmpPlayer = players_head->next;
    //diatrexw thn lista me tous players
    while(tmpPlayer != players_head) {
//an vrw ton player me pid tote kanw mia while gia na vrw ton targetPlayer.
//an 3anagurisei o pointer ston sentinel tote paei next 
        if(tmpPlayer->pid == pid) {
                int i = 0;
                while(i < numberofTasks_2) {
                if(tmpPlayer == players_head) {
                    i--;
                }
                tmpPlayer=tmpPlayer->prev;
             i++;   
            }
            //o paikths apo ekei pou tha arxisoume na dinoyme tasks
            // an tuxei na einai o sentinel,pame ston epomeno apo aristera
            if(tmpPlayer == players_head) {
                tmpPlayer = tmpPlayer->prev;
            }
            targetPlayer = tmpPlayer;
            break;
        
        }
        tmpPlayer = tmpPlayer->next;
    }
    if(targetPlayer==NULL) {

        printf("Player not found\n");
        print_double_list();
        return 0;
    }
    printf("pid_>>>%d",targetPlayer->pid);

    int taskCounter = 0;
    // mexri na dwsoume ola ta  tasks apo thn stoiva
    while(taskCounter < number_of_tasks) {
        printf("task Counter:::%d\n",taskCounter);
            //prepei o paikths poy tha parei task na mhn einai alien h o sentinel tou players_head
        if(targetPlayer->is_alien==0) {
            Tasks *tmpStack;
            //check an h stoiva einai adia
            if(!isEmptyStack(tasks_stack->head)) {
                   tmpStack = pop();
            }else {
                printf("Stack is empty\n");
                print_double_list();
                return 1;
            }
            

            Tasks *tmpTask; //to task poy tha dwsoume ston targetPlayer
            tmpTask = (Tasks*)malloc(sizeof(Tasks));
            tmpTask->difficulty = tmpStack->difficulty;
            tmpTask->tid = tmpStack->tid;
    
            //an to task einai dif 1 tote to vazw sthn arxh ths listas me ta task
          if(tmpTask->difficulty==1) {
            tmpTask->next = targetPlayer->tasks_head;
            targetPlayer->tasks_head = tmpTask;
           }
            // an to task einai dif 3 tote to vazw sto telos ths listas twn task(prin ton sentinel)
        if(tmpTask->difficulty==3) {
           tmpTask->next = targetPlayer->tasks_sentinel;
            if(targetPlayer->tasks_sentinel->next != NULL) {
            targetPlayer->tasks_sentinel->next->next=tmpTask;


            } else {
                targetPlayer->tasks_head=tmpTask;
            }

            targetPlayer->tasks_sentinel->next = tmpTask;
        }



        //an to dif einai 2 tote diatrexw olh th lista tou paikth poy tha dwsoume to task mexri na vrw thn katallhlh thesh
        if(tmpTask->difficulty==2) {

        Tasks *tmpPlayerTasks = targetPlayer->tasks_head;
        //an den exei kanena task to vazoume sth lista
            if(tmpPlayerTasks == targetPlayer->tasks_sentinel) {
                tmpTask->next = targetPlayer->tasks_sentinel;
                targetPlayer->tasks_sentinel->next = tmpTask;
                targetPlayer->tasks_head = tmpTask;

            } else {
            while(tmpPlayerTasks!=targetPlayer->tasks_sentinel) {

                if(tmpPlayerTasks->next==targetPlayer->tasks_sentinel && tmpPlayerTasks->difficulty!=3) {
                    tmpTask->next = targetPlayer->tasks_sentinel;
                    tmpPlayerTasks->next = tmpTask;
                    targetPlayer->tasks_sentinel->next = tmpTask;
                    break;
                }

                if(tmpPlayerTasks->difficulty == 2 ) {
                    tmpTask->next = tmpPlayerTasks->next;
                    tmpPlayerTasks->next = tmpTask;
                    break;

                }
                if(tmpPlayerTasks->next->difficulty == 3) {
                    tmpTask->next = tmpPlayerTasks->next;
                    tmpPlayerTasks->next = tmpTask;
                    break;
                }
                //shmainei oti o player exei ena node me dif 3
                if(tmpPlayerTasks->difficulty == 3) {
                    tmpTask->next = tmpPlayerTasks;
                    targetPlayer->tasks_head=tmpTask;
                    break;

                }
                tmpPlayerTasks = tmpPlayerTasks->next;

            }
            //tmpPlayerTasks = targetPlayer->tasks_head;
        }
        }
            
            taskCounter++;
        } 
        targetPlayer = targetPlayer->next;
    }
        print_double_list();
    return 1;
}


/**
 * @brief Vote
 *diatrexw thn lista gia na vrw ton paikth me pid,tou prosthetw to evidence kai tautoxrona vriskw to maxevidence.
 Sth sunexeia kalw thn eject_player gia ton player me to max Evidence.
 * @param pid The player's id
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid, int vote_evidence) {
    struct Players *tmpPlayer = players_head->next;
    struct Players *MaxEvidencePlayer = tmpPlayer;
    while(tmpPlayer!=players_head) {
        if(tmpPlayer->pid == pid) {
            tmpPlayer->evidence = tmpPlayer->evidence + vote_evidence;

        }
        if(MaxEvidencePlayer->evidence < tmpPlayer->evidence) {
            MaxEvidencePlayer = tmpPlayer;
        }

tmpPlayer = tmpPlayer->next;

    }
    print_double_listForW();
    return eject_player(MaxEvidencePlayer->pid);
}


/**
 * @brief Give Away Work
 * diatrexw thn diplh lista mia fora kai vriskw ton minPlayer kai ton Maxplayer me vash twn task
 * dinw ta misa task toy MaxPlayer ston minPlayer.
 * Diladi diagrafo ta prwta misa task toy MaxPlayer kai ta dinw ston minPlayer
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work() {
struct Players *tmpMaxTasks; // o paikths me ta perissotera task
int maxCounter = -1; 
struct Players *tmpMinTasks; // o paikths me ta ligotera tasks
int minCounter = tasks_head->tasks_count[0]+tasks_head->tasks_count[1]+tasks_head->tasks_count[2];

struct Players *tmpTraversePlayers=players_head->next; // pointer gia na diasxisw thn players_head (diplh lista)
int taskCounter = 0;
int checkForOnlyAliens=1;

while(tmpTraversePlayers != players_head) { 
    // an o paikths einai alien na paei ston epomeno
if(tmpTraversePlayers->is_alien!=0) {
    //check an oloi oi pektes einai alien
    //an nai tote return 0;
 if(checkForOnlyAliens == 1 && tmpTraversePlayers->next == players_head) {
print_double_list();
return 0;
 }   
    tmpTraversePlayers = tmpTraversePlayers->next;
    continue;
}
checkForOnlyAliens = 0;

Tasks *tmpTasks = tmpTraversePlayers->tasks_head;
// gia na vrw ta task toy paikth poy koitazoume me to tmpTraversePlayers
while(tmpTasks!=tmpTraversePlayers->tasks_sentinel) {
taskCounter++;
tmpTasks = tmpTasks->next;
}

// apothikeuw ton player me ta Maxtasks 
if(taskCounter > maxCounter) {
maxCounter = taskCounter;
tmpMaxTasks = tmpTraversePlayers;
}

// apothikeuw ton player me ta Mintasks 
if(taskCounter < minCounter) {
minCounter = taskCounter;
tmpMinTasks = tmpTraversePlayers;
}

taskCounter = 0;
tmpTraversePlayers = tmpTraversePlayers->next;
}

//-----------------------END FINDING MAX AND MIN ---------------------------
// ton arithmo twn  task poy tha dwthoun
int tasksToGive = maxCounter/2;
int counterToStop = 0;
//pointer gia na diasxisw ta task toy max player
Tasks *tmpMax = tmpMaxTasks->tasks_head;

//pointer gia na diasxisw ta task toy max player
Tasks *tmpMin = tmpMinTasks->tasks_head;
//while mexri na dwsoume ta misa task(tasksToGive)
while(counterToStop < tasksToGive) {
    //ftiaxnw ton komvo gia to task tou minPlayer
Tasks *newCell;
newCell = (Tasks*)malloc(sizeof(newCell));
if(newCell==NULL) {
    print_double_list();
    return 0;
}
newCell->difficulty = tmpMax->difficulty;
newCell->tid = tmpMax->tid;

tmpMaxTasks->tasks_head = tmpMaxTasks->tasks_head->next; //afairw to node apo to tmpMax
//an to dif ==1 tote mpainei sthn arxh toy task list
if(newCell->difficulty==1) {
    newCell->next = tmpMinTasks->tasks_head;
    tmpMinTasks->tasks_head = newCell;
    counterToStop++;
}
//an to dif==3 tote mpainei sto telos tou task list(prin to sentinel)
if(newCell->difficulty==3) {
newCell->next = tmpMinTasks->tasks_sentinel;
if(tmpMinTasks->tasks_sentinel->next!=NULL) {
tmpMinTasks->tasks_sentinel->next->next=newCell;
} else {
tmpMinTasks->tasks_head = newCell;

}

tmpMinTasks->tasks_sentinel->next = newCell;

counterToStop++;
}

if(newCell->difficulty==2) {
    //an den exei katholoy tasks
    if(tmpMin == tmpMinTasks->tasks_sentinel ) {
        newCell->next = tmpMinTasks->tasks_sentinel;
        tmpMinTasks->tasks_head = newCell;
        tmpMinTasks->tasks_sentinel->next = newCell;

    } else {
    //diasxizw olh thn task list tou minPlayer
while(tmpMin!=tmpMinTasks->tasks_sentinel) {
    // an exw ftasei sto task sentinel tote mpainei sto telos
    if(tmpMin->next==tmpMinTasks->tasks_sentinel) {
        newCell->next = tmpMinTasks->tasks_sentinel;
        tmpMin->next = newCell;
        tmpMinTasks->tasks_sentinel->next=newCell;
        break;
    }
//an to dif tou task poy vlepw einai 2 tote to vazw sta de3ia 
    if(tmpMin->next->difficulty==2) {
        newCell->next = tmpMin->next;
        tmpMin->next=newCell;
        break;
    }
    //an to dif toy epomenou task einai 3 tote to vazw sta aristera toy task me dif 3
    if(tmpMin->next->difficulty==3) {
        newCell->next = tmpMin->next;
        tmpMin->next = newCell;
        break;
    }
    //shmainei oti o player exei enan mono node me dif 3
    if(tmpMin->difficulty == 3) {
        newCell->next = tmpMin;
        tmpMinTasks->tasks_head = newCell;
        break;
    }
    tmpMin = tmpMin->next;




}
    }
tmpMin = tmpMinTasks->tasks_head;
counterToStop ++;
    }
    tmpMax = tmpMax->next;
}


print_double_list();
    return 1;
}

/**
 * @brief Terminate
 *diasxizw thn diplh lista, vriskw ton arithmo ton aliens kai crewmates, kai sth sunexeia vriskw ton nikhth
 * @return 1 on success
 *         0 on failure
 */
int terminate() {
    struct Players *tmpPlayers = players_head->next;
    int aliensCounter = 0;
    int crewmatesCounter = 0;

    while(tmpPlayers!=players_head) {
        if(tmpPlayers->is_alien==1) {
            aliensCounter++;
        }else {
            crewmatesCounter++;
        }
    tmpPlayers = tmpPlayers->next;
    }
    if(aliensCounter > crewmatesCounter) {
        printf("Aliens win.\n");
        return 1;
    }
    if(tasks_head->tasks_count[0]+tasks_head->tasks_count[1]+tasks_head->tasks_count[2] == tasks_stack->count || aliensCounter==0) {
        printf("Crewmates win.\n");
        return 1;

    }
    return 1;
}

/**
 * @brief Print Players
 * print tous players me ta pid tous kai an einai alien h oxi
 * @return 1 on success
 *         0 on failure
 */
int print_players() {
    struct Players *tmp = players_head->next;
    printf("Players = ");
while(tmp->pid != players_head->pid) {
printf("<%d:%d>",tmp->pid,tmp->is_alien);
tmp = tmp->next;
}
printf("\n");
    return 1;
}

/**
 * @brief Print Tasks
 *print ta tasks apo thn genikh lista
 * @return 1 on success
 *         0 on failure
 */
int print_tasks() {
    Tasks *tmpP1;
    tmpP1 = tasks_head->head;
    printf("List Tasks = ");
    while(tmpP1!=NULL) {
        printf("<%d,%d>",tmpP1->tid,tmpP1->difficulty);
        tmpP1 = tmpP1->next;
    }
    printf("\n");
    return 1;
}

/**
 * @brief Print Stack
 *print thn stack
 * @return 1 on success
 *         0 on failure
 */
int print_stack() {
if(isEmptyStack(tasks_stack->head)) {
printf("Completed Task Stack is empty\n");
} else {
Tasks *tmp = tasks_stack->head;
printf("Stack_Tasks = ");
while(tmp != NULL) {
printf("<%d,%d>",tmp->tid,tmp->difficulty);
tmp = tmp->next;
}
printf("\n");
}
    return 1;
}

/**
 * This is U.Typo in Project pdf
 * @brief Print Players & Task List
 *print thn diplh lista me players number kai  ola ta tasks kathe pekth me to tid kai difficulty
 * @return 1 on success
 *         0 on failure
 */
int print_double_list() {
     struct Players *tmp = players_head->next;
     int counter=1;
    while(tmp->pid != players_head->pid) {
     Tasks *tmpTasks = tmp->tasks_head;
        printf("Player_%d = ",counter);  
        counter++;
        while(tmpTasks->difficulty!=0) {
            printf("<%d,%d>,",tmpTasks->tid,tmpTasks->difficulty);
            tmpTasks = tmpTasks->next;
        }

    printf("\n");
    tmp = tmp->next;
    }
    printf("\n");
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

//----------------HELPER FUNCTIONS-----------------
int isEmptyStack(Tasks *stack) {
    if(stack==NULL) {return 1;}
    return 0;


}
/**
 * @brief push sthn stoiva to task S 
 * 
 * 
 */
int Push(Tasks *S) {

tasks_stack->count++;    
Tasks *p ;
p = (Tasks*)malloc(sizeof(Tasks));
if(p==NULL) {
    return 0;
}

p->tid = S->tid;
p->difficulty = S->difficulty;
p->next = tasks_stack->head;
tasks_stack->head = p;

return 1;
}
/**
 * @brief print thn double list alla me ton arithmo kathe paikth kai to evidence tou,kai ta task me ta tid kai difficulty
 */
int print_double_listForW() {
     struct Players *tmp = players_head->next;
     int counter=1;
    while(tmp->pid != players_head->pid) {
     Tasks *tmpTasks = tmp->tasks_head;

        printf("<Player_%d,%d> = ",counter,tmp->evidence);  
        counter++;
        while(tmpTasks->difficulty!=0) {
            printf("<%d,%d>,",tmpTasks->tid,tmpTasks->difficulty);
            tmpTasks = tmpTasks->next;
        }

    printf("\n");
    tmp = tmp->next;
    }
    printf("\n");
    return 1;
}
/**
 * pop the first element of the stack
 */
Tasks* pop() {
    Tasks *tmp = tasks_stack->head;


if(isEmptyStack(tasks_stack->head)) {
printf("Empty Stack\n");
return NULL;
}else {
    tasks_stack->count--;
tasks_stack->head = tmp->next;

}


return tmp;
}
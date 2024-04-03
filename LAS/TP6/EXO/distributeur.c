#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "utils_v2.h"

#define SHM_KEY 248
#define SEM_KEY 369
#define PERM 0666
#define NBR_TICKETS 100

//******************************************************************************
//CHILD HANDLER
//******************************************************************************
void child_handler () {
  // GET SEMAPHORE
  int sem_id = sem_get(SEM_KEY, 1);
  // GET SHARED MEMORY
  int shm_id = sshmget(SHM_KEY, sizeof(int), 0);
  int* z = sshmat(shm_id);
  
  for (int i = 0; i != NBR_TICKETS; i++) {
    sem_down0(sem_id);
    // START OF CRITICAL SECTION
    (*z)++;
    printf("Ticket number: %d\n", *z);
    // END OF CRITICAL SECTION
    sem_up0(sem_id);
  }
  sshmdt(z);
}

//******************************************************************************
//MAIN FUNCTION
//******************************************************************************
int main (int argc, char *argv[]) {
  // CREATE SEMAPHORE 
  int sem_id = sem_create(SEM_KEY, 1, PERM, 1); // init semaphores before fork to avoid
    // CREATE SHARED MEMORY
    int shm_id = sshmget(SHM_KEY, sizeof(int), IPC_CREAT | PERM);
    int* z = sshmat(shm_id);
    *z = 0;

    pid_t cpid = fork_and_run0(&child_handler);

     swaitpid(cpid, NULL, 0);  // make sure child finishes before removing semaphore
    sshmdt(z);
    shmctl(shm_id, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID);
    return 0;
}


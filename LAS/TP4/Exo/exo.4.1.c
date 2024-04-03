#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v1.h"

static const char *const MSG = "signal SIGUSR1 reçu !\n";
volatile sig_atomic_t end = 0;

void sigusr1_handler(int sig){
    write(1, MSG, strlen(MSG));
    end = 1;
}

void child_handler(){
    while(end == 0){
        sleep(1);
    }
}

int main(){
    static const char *const PERE = "Fin du père\n";
    for(int i= 0; i < 7; i++){
    ssigaction(SIGUSR1, sigusr1_handler);
    pid_t childId = fork_and_run0(child_handler);
    kill(childId, SIGUSR1);
    int statut;
    swaitpid(childId, &statut, 0);
    }
    write(1, PERE, strlen(PERE));
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "utils_v1.h"

void childProcess()
{
  /* Dans le processus fils */
  char *msg = "4 5 6\n";
  int len = strlen(msg);
  swrite(1, msg, len);
  exit(0);
}

int main(int argc, char **argv)
{
  /* Création d'un processus fils */
  int childId = fork_and_run0(childProcess);

  /* Dans le processus parent */
  printf("Processus parent (pid=%i) en attente de la fin de son enfant (pid fils=%i).\n", getpid(), childId);
    
  /* Attente de la terminaison du processus fils */
  int status;
  swaitpid(childId, &status, 0);
  printf("Code de sortie du fils : %i\n", status);
  char *msg = "1 2 3\n";
  int len = strlen(msg);
  swrite(1, msg, len);
  printf("Processus parent se termine après son enfant (pid fils=%i).\n", childId);
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "utils_v1.h"

int main(int argc, char const *argv[]){
   int a = 5;
   int childId = sfork();

   if(childId != 0){
      printf("Processus parent (pid=%i) en attente de la fin de son enfant (pid fils=%i).\n", getpid(), childId);

      int b = a*5;
      printf("b = %i\n", b);
      printf("a = %i\n", a);

      int status;
      swaitpid(childId, &status, 0);

      printf("Processus parent se termine après son enfant (pid fils=%i).\n", childId);
   }else{
        printf("Je suis le fils '%s': pid=%i - ppid=%i\n", argv[0], getpid(), getppid());
       int b = a*2;
        printf("b = %i\n", b);
        printf("a = %i\n", a);
   }
}

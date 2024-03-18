#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "utils_v1.h"

int main(int argc, char const *argv[]){
    
    int childId = sfork();

    if(childId != 0){
            //char *msg = "trois .. deux .. un .. \n";
            //int lent = strlen(msg);
            //swrite(1, msg, lent);
             printf("Trois .. deux .. un ..");

            int status;
            swaitpid(childId, &status, 0);
    }else{
        //char *msg = "Partez ! \n";
        //int len = strlen(msg);
        //swrite(1, msg, len);}
        printf("Partez !");
}
}

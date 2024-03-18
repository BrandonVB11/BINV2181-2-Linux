#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "utils_v1.h"

#define FILENAME "test"

void readFile (char* file);

int main(int argc, char const *argv[]){
    readFile(FILENAME);
}

void readFile(char* file){
    char bufRD[10];
    int fd = open(file,O_RDONLY| O_CREAT |O_TRUNC, 0644);
    
    

}
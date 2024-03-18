#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "utils_v1.h"

#define BUFFERSIZE 20

int main(int argc, char const *argv[]){

    char filename[20];
    int fd;

    read(0, filename, 20);
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int childId = fork();
    

    
}
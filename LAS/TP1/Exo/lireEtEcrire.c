#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "utils_v1.h"

#define BUFFERSIZE 80
#define FILENAME "maj"
#define FILENAME2 "min"

void writeFile (char* file,char* file2);

int main(int argc, char const *argv[]){
    writeFile(FILENAME,FILENAME2);
}

void writeFile(char* file,char* file2){
    char bufRd[BUFFERSIZE];

    int fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    checkNeg(fd, "Error opening file");

    int fd2 = open(file2, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    checkNeg(fd2, "Error opening file");

    char* msg = "Enter text lines (Ctrl-D to terminate):\n";
    int len = strlen(msg);
    int nbCharWr = write(1, msg, len);
    checkCond(nbCharWr != len,"Error writing on stdout");

    int nbCharRd = read(0, bufRd, BUFFERSIZE);
    while (nbCharRd > 0) {
        if (bufRd[0] >= 'A' && bufRd[0] <= 'Z'){
            int nbCharWr = write(fd, bufRd, nbCharRd);
            checkCond(nbCharWr != nbCharRd,"Error writing file");
        }
        else if (bufRd[0] >= 'a' && bufRd[0] <= 'z'){
            int nbCharWr = write(fd2, bufRd, nbCharRd);
            checkCond(nbCharWr != nbCharRd,"Error writing file");
        }
        nbCharRd = read(0, bufRd, BUFFERSIZE);
    }
    
    checkNeg(nbCharRd,"Error reading stdin");
    int res = close(fd);
    checkNeg(res,"Error closing fd");
    int res2 = close(fd2);
    checkNeg(res2,"Error closing fd");
}


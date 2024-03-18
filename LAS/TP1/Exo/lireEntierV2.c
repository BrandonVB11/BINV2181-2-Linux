#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "utils_v1.h"



int main(){
  int fd = open("entiers.bin", O_RDONLY| O_CREAT |O_TRUNC, 0644);
  checkNeg(fd, "Error opening file");

  for(int i = 0; i <= 10000000; i++){
    write(fd, &i, sizeof(int));
  }

    close(fd);
    return 0;
}

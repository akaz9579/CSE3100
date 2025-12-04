#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char** argv){
    int fdIn = open("in.txt", O_RDONLY | O_CREAT);
    int fdOut = open("out.txt", O_WRONLY | O_CREAT);

    dup2(fdIn,0);
    close(fdIn);
    dup2(fdOut,1);
    close(fdOut);

    execvp("tr", argv);


    return 0;
}
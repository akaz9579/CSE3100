
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int status; 

    int fdIn  = open("newIn.txt",  O_RDONLY);
    int fdOut = open("newOut.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    pid_t id = fork();

    if (id == 0) { // child
        dup2(fdIn,  STDIN_FILENO);
        dup2(fdOut, STDOUT_FILENO);
        close(fdIn);
        close(fdOut);

        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(EXIT_FAILURE);

    } else if (id > 0) { // parent
        close(fdIn);
        close(fdOut);
        waitpid(id, &status, 0);
        if (WIFEXITED(status))
            printf("Child exited with status %d\n", WEXITSTATUS(status));
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    
    return 0; 
}
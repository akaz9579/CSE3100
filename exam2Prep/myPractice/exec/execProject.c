// runner.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*
Write a C program that:
	1.	Accepts a command (and optional arguments) from the command line.
	2.	Creates a child process with fork().
	3.	In the child, uses one of the exec family functions (your choice of 
    execl, execlp, execv, or execvp) to run that command.
	4.	The parent waits for the child to finish, prints the child’s exit status, and then exits.

*/

int main(int argc, char *argv[]) {
    int status;
    
    pid_t pid = fork();

    if(pid >0){
        waitpid(pid, &status, 0 );
        if(WIFEXITED(status)){
            printf("Child exited normally with status %d\n", WEXITSTATUS(status));
        }else{
            perror("Child had error in exiting");
            exit(1);
        }


    }if(pid ==0){
        execvp(argv[1], &argv[1]);
        perror("Exec Error");
        exit(EXIT_FAILURE);

    }if(pid<0){
        perror("Fork falilue");
        exit(2);
    }

    return 0;
}
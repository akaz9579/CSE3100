#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    /*FD 
    0, in 
    1, out 
    2, err
    3 pip1 write
    4 pip1 read
    5 pip2 wrie
    6 pip2 read
    */ 

    int pd[2];
    int pd2[2];
    pipe(pd); // hello
    pipe(pd2); //hi 

    pid_t pid = fork();


    if(pid>0){ //parent
        //pipe 1 operation: parent to child
        close(pd[0]);
        write(pd[1], "Hello", 6);
        

        //pipe 2 operation, child to parent
        close(pd2[1]);
        char recive[10];
        read(pd2[0],recive,sizeof(recive));
        printf("Im parent, child told me %s\n",recive);

    }if (pid==0){ //child

        //pipe 1 operation: parent to child
        close(pd[1]);
        char recive[10];
        read(pd[0],recive,sizeof(recive));
        printf("Im child, parent told me %s\n",recive);

        //pipe 2 operation, child to parent
        close(pd2[0]);
        write(pd2[1], "hi", 3);


    }if (pid<0){
        perror("Process failed");
        exit(0);
        return -1;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //api header for threading


void *routine(){
    printf("Test fron threads\n");
    sleep(3);
    printf("Ending Threadn\n");

}

int main(int argc, char*argv[]){
    pthread_t t1, t2; //used to ID the thread 
    pthread_create(&t1,NULL, &routine, NULL); 
    pthread_create(&t2,NULL, &routine, NULL); 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);



    return 0;
}

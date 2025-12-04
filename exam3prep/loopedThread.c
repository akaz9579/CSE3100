#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //api header for threading

int mails = 0;
int NUMTHREADS = 4;
pthread_mutex_t mutex; // init the mutex 

void *routine(void *arg) {

    for(int i= 0; i<1000000; i++){
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}


int main(int argc, char*argv[]){

    pthread_t th[NUMTHREADS];


    pthread_mutex_init(&mutex,NULL); // initalize mutex 

    for(int i=0;i<NUMTHREADS; i++){
        pthread_create(&th[i],NULL, &routine, NULL); 
    }



    for(int i=0;i<NUMTHREADS; i++){
        pthread_join(th[i], NULL); 
    }



    pthread_mutex_destroy(&mutex);


    printf("Number of mails: %d\n", mails);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //api header for threading

int mails = 0;
pthread_mutex_t mutex; // init the mutex 

void *routine(void *arg) {
    for(int i= 0; i<1000000; i++){
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
        //what thread does:
        // read, increment, write
        //race condtion fucks up the order of the thread's independent actions 
    }
    return NULL;
}


int main(int argc, char*argv[]){
    pthread_t t1, t2; //used to ID the thread 

    pthread_mutex_init(&mutex,NULL); // initalize mutex 


    pthread_create(&t1,NULL, &routine, NULL); 
    pthread_create(&t2,NULL, &routine, NULL); 


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);


    printf("Number of mails: %d\n", mails);

    return 0;
}

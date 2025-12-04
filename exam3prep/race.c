#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //api header for threading

int mails = 0;

void *routine(void *arg) {
    for(int i= 0; i<1000000; i++){
        mails++;
        //what thread does:
        // read, increment, write
        //race condtion fucks up the order of the thread's independent actions 
    }
    return NULL;
}


int main(int argc, char*argv[]){
    pthread_t t1, t2; //used to ID the thread 
    pthread_create(&t1,NULL, &routine, NULL); 
    pthread_create(&t2,NULL, &routine, NULL); 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Number of mails: %d\n", mails);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "matrix.h"

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

/* the main function of threads */

/*

typedef struct Matrix {
    unsigned int nrows;
    unsigned int ncols;
    TElement **data;
} TMatrix;


If the allocation is successful, the data field of the matrix should
 * point to an array of pointers (representing the rows) and each pointer
 * in that array should point to an array of TElement representing the values
 * in that row.

*/
static void * thread_main(void * p_arg)
{
    // TODO
    thread_arg_t *myArg = (thread_arg_t *)p_arg;
    int id = myArg->id;
    //printf("Thread %d \n",id);

    //do a check for the thread for the loop conditon
    int start, end;
    if(id==0){
        start = 0;
        end = (myArg->m->nrows)/2;
    }else{
        start = (myArg->m->nrows)/2;
        end = (myArg->m->nrows); 
    }

    for(int i=start; i< end; i++){
        for(int j=0; j < myArg->m->ncols; j++){
            myArg->t->data[i][j] = myArg->m->data[i][j] + myArg->n->data[i][j];  
        }
    }

    pthread_exit(NULL);
}

/* Return the sum of two matrices. The result is in a newly creaed matrix. 
 *
 * If a pthread function fails, report error and exit. 
 * Return NULL if something else is wrong.
 *
 * Similar to addMatrix, but this function uses 2 threads.
 */
TMatrix * addMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (m == NULL || n == NULL || m->nrows != n->nrows || m->ncols != n->ncols )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, m->ncols);
    if (t == NULL)
        return t;

    // TODO
    pthread_t threads[NUM_THREADS];
    thread_arg_t args[NUM_THREADS];
    
    for (int i = 0; i < 2; i++) {
    args[i].id = i;
    args[i].m = m;
    args[i].n = n;
    args[i].t = t;
    pthread_create(&threads[i], NULL, thread_main, &args[i]);
}

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }


    return t;
}

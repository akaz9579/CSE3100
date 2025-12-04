#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

/*


typedef struct Matrix {
    unsigned int nrows;
    unsigned int ncols;
    TElement **data;
} TMatrix;



*/

static void *thread_main(void *p_arg)
{
    thread_arg_t *arg = (thread_arg_t *)p_arg;
    unsigned int id = arg->id;

    for (unsigned int i = id; i < arg->m->nrows; i += NUM_THREADS) {
        for (unsigned int j = 0; j < arg->n->ncols; j++) {
            TElement sum = 0;
            for (unsigned int k = 0; k < arg->m->ncols; k++) {
                sum += arg->m->data[i][k] * arg->n->data[k][j];
            }
            arg->t->data[i][j] = sum;
        }
    }

    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix *mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (!m || !n || m->ncols != n->nrows)
        return NULL;

    TMatrix *t = newMatrix(m->nrows, n->ncols);
    if (!t)
        return NULL;

    pthread_t threads[NUM_THREADS];
    thread_arg_t args[NUM_THREADS];

    for (unsigned int i = 0; i < NUM_THREADS; i++) {
        args[i].id = i;
        args[i].m = m;
        args[i].n = n;
        args[i].t = t;
        if (pthread_create(&threads[i], NULL, thread_main, &args[i]) != 0) {
            perror("pthread_create");
            freeMatrix(t);
            exit(EXIT_FAILURE);
        }
    }

    for (unsigned int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            freeMatrix(t);
            exit(EXIT_FAILURE);
        }
    }

    return t;
}

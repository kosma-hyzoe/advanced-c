#include <pthread.h>
#include <stdio.h>

#define NTHREADS 32 /* should be even */

int c;
int even_arg_calls_done = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *cppprint(void *msg)
{
    pthread_mutex_lock(&lock);
    if(*(int *)msg % 2 != 0)
        while (!even_arg_calls_done)
            pthread_cond_wait(&cond, &lock);

    c++;
    printf("msg: %d\tthread id: %ld\tc: %d\n", *(int *)msg, pthread_self(), c);
    printf("msg: %d\tthread id: %ld\tc: %d\n", *(int *)msg, pthread_self(), c);
    if (*(int *)msg == NTHREADS) { /* last even msg */
        even_arg_calls_done = 1;
        pthread_cond_broadcast(&cond);
    }
    pthread_mutex_unlock(&lock);
}

int main()
{
    pthread_t thread_ids[NTHREADS];
    int msgs[NTHREADS];
    for (int i = 0; i < NTHREADS; i++) {
        msgs[i] = i + 1;
        pthread_create(&thread_ids[i], NULL, cppprint, (void *)&msgs[i]);
    }
    for (int i = 0; i < NTHREADS; i++)
        pthread_join(thread_ids[i], NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
}

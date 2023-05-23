#include <pthread.h>
#include <stdio.h>

#define NTHREADS 32

int c;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *cppprint(void *msg)
{
    pthread_mutex_lock(&lock);
    c++;
    printf("msg: %d\tthread id: %ld\tc: %d\n", *(int *)msg, pthread_self(), c);
    printf("msg: %d\tthread id: %ld\tc: %d\n", *(int *)msg, pthread_self(), c);
    pthread_mutex_unlock(&lock);
}

int main()
{
    pthread_t thread_ids[NTHREADS];
    int msgs[NTHREADS];
    for (int i = 0; i < NTHREADS; i++) {
        msgs[i] = i;
        pthread_create(&thread_ids[i], NULL, cppprint, (void *)&msgs[i]);
    }
    for (int i = 0; i < NTHREADS; i++)
        pthread_join(thread_ids[i], NULL);

    pthread_mutex_destroy(&lock);
}


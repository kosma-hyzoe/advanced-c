#include <pthread.h>
#include <stdio.h>

#define NTHREADS 32

int c = 0;

void *cppprint(void *msg)
{
    c++;
    printf("msg: %d\tthread id: %ld\tc: %d\n", *(int *)msg, pthread_self(), c);
    printf("msg: %d\tthread id: %ld\tc: %d\n", *(int *)msg, pthread_self(), c);
}

int main()
{
    pthread_t thread_ids[NTHREADS];
    /* i expected msg/i to break, but it doesn't (seem to)¯\_(ツ)_/¯ */
    for (int i = 0; i < NTHREADS; i++)
        pthread_create(&thread_ids[i], NULL, cppprint, (void *)&i);

    for (int i = 0; i < NTHREADS; i++)
        pthread_join(thread_ids[i], NULL);
}

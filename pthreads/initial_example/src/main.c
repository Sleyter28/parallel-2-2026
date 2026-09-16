#include <stdio.h>
#include <stdlib.h>
# include <pthread.h>

void *printThread(void *ptr);

int main(void)
{
    pthread_t thread1, thread2;
    char* message1 = " hello 1";
    char* message2 = " hello 2";

    int ipth1, ipth2;

    ipth1 = pthread_create(&thread1, NULL, printThread, (void*) message1);
    ipth2 = pthread_create(&thread2, NULL, printThread, (void*) message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Threads joined: %d\n", ipth1);
    printf("Threads joined: %d\n", ipth2);

    printf("Hello, World!\n");
    return 0;
}

void *printThread(void *ptr)
{
    char *message;
    message = (char *)ptr;
    printf("Pthread number: %s\n", message);

    return NULL;
}

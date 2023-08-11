#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *threadFunction(void *arg) {
    pthread_t tid = pthread_self();  ID
    printf("Thread ID: %ld\n", tid);
    return NULL;
}
int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, threadFunction, NULL) != 0) {
        printf("pthread_create...\n");
        return 1;
    }
    if (pthread_join(thread, NULL) != 0) {
        printf("pthread_join....\n");
        return 1;
    }
    printf("Main thread exiting.\n");
    return 0;
}

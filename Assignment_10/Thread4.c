#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
struct ThreadData {
    int inputValue;
    int result;
};
void *calculateValue(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    data->result = data->inputValue * 2;
    pthread_exit(NULL);
}
int main() {
    pthread_t thread;
    struct ThreadData data;
    printf("Enter a value: ");
    scanf("%d", &data.inputValue);
    pthread_create(&thread, NULL, calculateValue, &data);
    pthread_join(thread, NULL);
    printf("Result from thread: %d\n", data.result);
    return 0;
}

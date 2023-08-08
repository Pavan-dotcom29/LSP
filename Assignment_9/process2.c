#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>

int countCapitalChars(const char *filename) {
    int count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return -1;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isupper(ch)) {
            count++;
        }
    }

    fclose(file);
    return count;
}

void writeToCountFile(int count) {
    int fd = open("count.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Failed to open count.txt");
        exit(1);
    }

    char buffer[20];
    int length = snprintf(buffer, sizeof(buffer), "%d\n", count);
    write(fd, buffer, length);

    close(fd);
}

int main() {
    // Fork the first child (Process 1)
    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid1 == 0) {
        // This code runs in Process 1
        int count_demo = countCapitalChars("demo.txt");
        if (count_demo >= 0) {
            writeToCountFile(count_demo);
        }
        exit(0);
    }

    // Fork the second child (Process 2)
    pid_t pid2 = fork();

    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid2 == 0) {
        // This code runs in Process 2
        int count_hello = countCapitalChars("hello.txt");
        if (count_hello >= 0) {
            writeToCountFile(count_hello);
        }
        exit(0);
    }

    // This code runs in the parent process
    int status;
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);

    printf("Both processes have written their counts to count.txt\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *home_dir = getenv("HOME");
    if (home_dir != NULL) {
        printf("Home directory: %s\n", home_dir);
    } else {
        printf("Home directory not found.\n");
    }

    char *user_name = getenv("USER");
    if (user_name != NULL) {
        printf("Login user name: %s\n", user_name);
    } else {
        printf("Login user name not found.\n");
    }

    return 0;
}

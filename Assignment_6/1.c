#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
    char filename[100];
    FILE *file;
    long offset;
    printf("Enter the file name \n");
    scanf("%s", filename);
    printf("Enter the offset \n ");
    scanf("%ld", &offset);
    file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    fseek(file, offset, SEEK_SET);
    if (ftruncate(fileno(file), ftell(file)) != 0) {
        printf("Error truncating the file.\n");
    } else {
        printf("Data removed from offset %ld.\n", offset);
    }
    fclose(file);
    return 0;
}

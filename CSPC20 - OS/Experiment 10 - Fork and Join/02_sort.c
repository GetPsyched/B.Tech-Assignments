#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cmp_ascending(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int cmp_descending(const void *a, const void *b) {
    return *(int*)a < *(int*)b;
}

void sort_ascending(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmp_ascending);

    printf("\nArray sorted in ascending order --> ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void sort_descending(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmp_descending);

    printf("\nArray sorted in descending order --> ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void
main(char *argc, char *argv[]) {
    int arr[] = {3, 9, 1, 8, 5, 0, 2, 7, 4, 6};

    int p = fork();
    switch (p) {
        // Error block
        case -1:
            printf("Error while creating the child process!\n");
            break;

        // Child process
        case 0:
            sort_ascending(arr, 10);
            printf("Child process terminated...\n");
            break;

        // Parent process
        default:
            sort_descending(arr, 10);
            printf("Parent Process terminated...\n");
    }
}

#include <stdio.h>
#include <unistd.h>

void main(char *argc, char *argv[]) {
    printf(
        "\nProgram name --> %s\nSelf id --> %d\nParent process id --> %d\n",
        argv[0], getpid(), getppid()
    );

    printf("The arguments passed: ");
    int i = 1;
    while (argv[i])
        printf("%s ", argv[i++]);
    printf("\n");
}

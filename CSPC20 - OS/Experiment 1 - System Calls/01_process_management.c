// For clone()
#define _GNU_SOURCE  
#include <sched.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define STACK 8192

void fork_demo() {
    int p = fork();

    switch (p) {
        // -1 indicates that an error has occurred
        case -1:
            printf("Error while creating the child process!\n");
            break;
        // 0 indicates that this is the child process
        case 0:
            printf("\nExecution currently inside the child proccess");
            printf(
                "\nChild process id --> %d\nParent process id --> %d\n",
                getpid(), getppid()
            );

            printf("Calling hello.c\n");
            char *args[] = {"hello", "arg1", "arg2", NULL};
            execv("./hello", args);
            execvp("./hello", args);
            execl("./hello", "hello", "arg1", "arg2", NULL);

            printf("Child process ended\n");
            break;
        // > 0 indicates that this is the parent process
        default:
            printf("Execution currently inside the parent proccess");
            printf("\nParent process id --> %d\n", getpid());
    }
}

void vfork_demo() {
    int x = 0;
    int p = vfork();

    switch (p) {
        // -1 indicates that an error has occurred
        case -1:
            printf("Error while creating the child process!\n");
            break;
        // 0 indicates that this is the child process
        case 0:
            vfork();
            x++;
            printf("Child process id --> %d\n", getpid());
            printf("Parent process id --> %d\n", getppid());
            printf("x = %d\n", x);
            exit(0);
        // > 0 indicates that this is the parent process
        default:
            printf("This is parent process with id --> %d\n", getpid());
            printf("x = %d\n", ++x);
            wait(NULL);
    }
}

int print() {
    printf("Hello, World!");
    return 0;
}

void clone_demo() {
    void *stack = malloc(STACK);
    if (!stack) {
        perror("Malloc Failed");
        exit(1);
    }

    int p = clone(&print, (char *)stack + STACK, CLONE_VM, 0);
    if (p < 0) {
        perror("Clone Failed");
        exit(1);
    }

    printf("Parent pid --> %d\n", getpid());
    free(stack);
}

void main() {
    printf("fork:\n\n"); fork_demo();
    wait(NULL);
    printf("\n\nvfork:\n\n"); vfork_demo();
    wait(NULL);
    printf("\n\nclone:\n\n"); clone_demo();
}

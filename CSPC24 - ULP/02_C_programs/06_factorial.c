#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n != 0)
        return n * factorial(n - 1);
    else
        return 1;
}

void main(int argc, char *argv[]) {
    int num = atoi(argv[1]);
    printf("Factorial of the given number is %d\n", factorial(num));
}
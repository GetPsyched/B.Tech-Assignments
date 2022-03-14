#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int largest = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("The largest of the given three numbers is: %d\n", largest);
}
#include <stdio.h>
#include <stdlib.h>

int is_avogadro(int n) {
    int remainder, result = 0;
    int originalNum = n;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += remainder ^ 3;
        originalNum /= 10;
    }
    if (result == n)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);
    if (is_avogadro(num))
        printf("Given number is an Avogadro number.\n");
    else
        printf("Given number is not Avogadro number.\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

bool is_prime(int n) {
    int flag = true;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            flag = false;
            break;
        }
    return flag;
}
int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);
    if (is_prime(num))
        printf("Given number is prime.\n");
    else
        printf("Given number is not prime.\n");
    return 0;
}
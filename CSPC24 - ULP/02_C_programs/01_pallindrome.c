#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_pallindrome(char string[], int n) {
    for (int i = 0; i < n / 2; i++)
        if (string[i] != string[n - i - 1])
            return false;
    return true;
}

int main(int argc, char *argv[]) {
    if (is_pallindrome(argv[1], strlen(argv[1])))
        printf("Given string is a palindrome.\n");
    else
        printf("Given string is not a palindrome.\n");
    return 0;
}
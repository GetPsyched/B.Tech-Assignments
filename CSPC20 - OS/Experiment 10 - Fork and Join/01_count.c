#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int
is_vowel(char ch) {
    ch = tolower(ch);
    return (
        ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
    );
}

void
get_word_count(char line[], int n) {
    int i = 0, count = 0;
    while(line[i++] != '\0' && n != 0)
        if (line[i] == ' ' && line[i+1] != '\0')
            count++;

    if (n != 0)
        count++;

    printf("\nNumber of words = %d\n", count);
}

void
get_vowel_count(char line[], int n) {
    int i = 0, count=0;
    while(line[i++] != '\0' && n != 0)
        if (is_vowel(line[i]))
            count++;

    printf("\nNumber of vowels = %d\n", count);
}

void
main(char *argc, char *argv[]) {
    char line[50];
    for (int i = 1; argv[i] != NULL; i++) {
        strncat(line, argv[i], strlen(argv[i]));
        strncat(line, " ", 2);
    }
    int length = strlen(line) - 1;

    int p = fork();
    switch (p) {
        // Error block
        case -1:
            printf("Error while creating the child process!\n");
            break;

        // Child process
        case 0:
            get_word_count(line, length);

            printf("Child process terminated...\n");
            break;

        // Parent process
        default:
            get_vowel_count(line, length);
            printf("Parent Process terminated...\n");
    }
}

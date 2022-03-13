#include <stdio.h>
char pattern(int n, char ch)
{
    for (int i = 1; i <= n; i++)
    {
        for (int sp = n - i; sp > 0; sp--)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%c", ch);
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int sp = n - i; sp > 0; sp--)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%c", ch);
        printf("\n");
    }
}
void main()
{
    int n;
    char ch;
    printf("Enter number of lines and character to print the pattern with: ");
    scanf("%d %c", &n, &ch);
    pattern(n, ch);
}
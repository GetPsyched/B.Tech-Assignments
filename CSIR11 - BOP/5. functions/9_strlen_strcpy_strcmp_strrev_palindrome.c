#include <stdio.h>
int xstrlen(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
void xstrcpy(char str2[], char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        str2[i] = str[i];
        i++;
    }
    str2[i] = '\0';
}
int xstrcmp(char str[], char str1[])
{
    int i = 0;
    while (1)
    {
        char a = str[i], b = str1[i];
        if (a == b)
        {
            i++;
        }
        else if (a > b)
        {
            return 1;
        }
        else if (a < b)
        {
            return -1;
        }
        else if (a == '\0' && b == '\0')
        {
            return 0;
        }
    }
}
void xstrrev(char str[])
{
    int len = xstrlen(str);
    for (int i = (len - 1) / 2; i >= 0; i--)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}
void palindrome(char str[])
{
    char temp[50];
    xstrcpy(temp, str);
    xstrrev(temp);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != temp[i])
        {
            printf("It is not a palindrome\n");
            break;
        }
        i++;
    }
    if (str[i] == '\0')
    {
        printf("It is a palindrome\n");
    }
}
void main()
{
    char str[50], str2[50], str1[50];
    printf("Enter a string: ");
    gets(str);
    printf("Enter string 2: ");
    gets(str1);
    printf("Comparison between 2 strings: %d\n", xstrcmp(str, str1));
    printf("Length of string: %d\n", xstrlen(str));
    xstrcpy(str2, str);
    printf("Copied string: %s\n", str2);
    xstrrev(str);
    printf("Reversed string: %s\n", str);
    printf("Checking if string 1 is palindrome or not: ");
    palindrome(str);
}
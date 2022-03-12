#include <stdio.h>

int main()
{
  char ch;
  do
  {
    printf("Enter a character (Enter | to exit) --> ");
    scanf(" %c", &ch);
    if (ch != '|')
    printf("The ascii value of the ch variable is --> %d\n\n", ch);
  } while (ch != '|');
}

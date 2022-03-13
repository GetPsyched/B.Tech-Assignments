#include <stdio.h>

int main()
{
  int count = 0;
  char s[25];
  printf("Enter a string --> ");
  gets(s);
  for(int i=0; s[i] != '\0'; i++)
    if (s[i] == 'A')
      count++;
  printf("'A' appears %d times in the given string\n", count);
}

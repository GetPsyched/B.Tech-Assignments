#include <stdio.h>

int main()
{
  int count = 0;
  char s[25];
  printf("Enter a string --> ");
  gets(s);
  for(int i=0; s[i] != '\0'; i++)
    count++;
  printf("Length of given string --> %d\n", count);
}

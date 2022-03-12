#include <stdio.h>

int main()
{
  int i;
  char x[25], y[25];
  printf("Enter a string --> ");
  gets(x);
  for(i=0; x[i] != '\0'; i++)
    y[i] = x[i];
  y[i] = '\0';
  printf("Copied string --> %s\n", y);
}

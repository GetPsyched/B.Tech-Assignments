#include <stdio.h>
#include <string.h>

int main()
{
  char x[25], y[25];
  printf("Enter a string --> ");
  gets(x);
  int i, n = strlen(x);
  for(i=0; i < n; i++)
    y[n-i-1] = x[i];
  y[i] = '\0';
  printf("Reversed string --> %s\n", y);
}

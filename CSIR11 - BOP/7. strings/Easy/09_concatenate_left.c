#include <stdio.h>
#include <string.h>

int main()
{
  char x[25], y[25];
  printf("Enter first string --> ");
  gets(x);
  printf("Enter second string --> ");
  gets(y);
  int i, j, temp, n1 = strlen(x), n2 = strlen(y);
  for(i=n1+n2-1; i >= n2; i--)
    x[i] = x[i-n2];
  for(i=0; i < n2; i++)
    x[i] = y[i];
  x[n1+n2] = '\0';
  printf("\nConcatenated string --> %s\n", x);
}

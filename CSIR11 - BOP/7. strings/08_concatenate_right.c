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
  for(i=n1, j=0; i<n1+n2; i++) {
    x[i] = y[j];
    j++;
  }
  x[i] = '\0';
  printf("Concatenated string --> %s\n", x);
}

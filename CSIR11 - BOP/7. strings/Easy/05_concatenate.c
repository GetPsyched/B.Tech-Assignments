#include <stdio.h>

int main()
{
  int i;
  char x[25], y[25], z[50];
  printf("Enter first string --> ");
  gets(x);
  printf("Enter second string --> ");
  gets(y);
  for(i=0; x[i] != '\0'; i++)
    z[i] = x[i];
  for(int j=0; y[j] != '\0'; i++) {
    z[i] = y[j];
    j++;
  }
  z[i] = '\0';
  printf("Concatenated string --> %s\n", z);
}

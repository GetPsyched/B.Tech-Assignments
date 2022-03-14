#include<stdio.h>
#include <string.h>

int main()
{
  char x[25];
  printf("Enter a string --> ");
  gets(x);
  int i, temp, n = strlen(x);
  for(int i=0; i < n/2; i++)
  {
    temp = x[i];
    x[i] = x[n-i-1];
    x[n-i-1] = temp;
  }
  printf("Reversed string --> %s\n", x);
}

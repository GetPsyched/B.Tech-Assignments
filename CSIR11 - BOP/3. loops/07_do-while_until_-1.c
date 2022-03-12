#include <stdio.h>

int main()
{
  int n, sum = 0;
  do {
    printf("Enter number --> ");
    scanf("%d", &n);
    sum += n;
  } while(n != -1);
  printf("\nThe sum is --> %d\n", ++sum);
}

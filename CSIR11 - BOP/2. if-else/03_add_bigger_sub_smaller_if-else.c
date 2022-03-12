#include <stdio.h>

int main()
{
  int a, b;
  printf("Enter a number --> ");
  scanf("%d", &a);
  printf("Enter another number --> ");
  scanf("%d", &b);
  if (a > b)
    printf("\nThe sum is %d\n", a + b);
  else
    printf("\nThe difference is %d\n", a - b);
}

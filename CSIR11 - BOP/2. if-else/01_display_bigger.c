#include <stdio.h>

int main()
{
  int a, b;
  printf("Enter a number --> ");
  scanf("%d", &a);
  printf("Enter another number --> ");
  scanf("%d", &b);
  if (a > b)
    printf("\nThe bigger number is %d\n", a);
  if (a < b)
    printf("\nThe bigger number is %d\n", b);
}

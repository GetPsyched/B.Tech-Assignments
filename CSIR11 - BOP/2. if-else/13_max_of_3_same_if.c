#include <stdio.h>

int main()
{
  int a, b, c;
  printf("\nEnter first number --> ");
  scanf("%d", &a);
  printf("Enter second number --> ");
  scanf("%d", &b);
  printf("Enter third number --> ");
  scanf("%d", &c);
  int max = a, min = a;
  if (b > max)
    max = b;
  else min = b;
  if (c > max)
    max = c;
  else min = c;
  printf("\nMax number is %d\n", max);
  printf("\nMin number is %d\n", min);
}

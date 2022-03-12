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
  int max = a;
  if (b > max)
    max = b;
  if (c > max)
    max = c;
  printf("\nMax number is %d\n", max);
}

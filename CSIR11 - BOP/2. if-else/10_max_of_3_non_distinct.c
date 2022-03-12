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
  if (a >= b && a >= c)
    printf("\nMax number is %d\n", a);
  else if (b >= a && b >= c)
    printf("\nMax number is %d\n", b);
  else if (c >= a && c >= b)
    printf("\nMax number is %d\n", c);
}

#include <stdio.h>

int main()
{
  int a, b, c, d;
  printf("\nEnter first number --> ");
  scanf("%d", &a);
  printf("Enter second number --> ");
  scanf("%d", &b);
  printf("Enter third number --> ");
  scanf("%d", &c);
  printf("Enter fourth number --> ");
  scanf("%d", &d);
  int max = a;
  if (b > max)
    max = b;
  if (c > max)
    max = c;
  if (d > max)
    max = d;
  printf("\nMax number is %d\n", max);
}

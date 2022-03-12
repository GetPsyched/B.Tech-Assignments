#include <stdio.h>

int main()
{
  int n, sum = 0;
  printf("Enter n --> ");
  scanf("%d", &n);
  for (int i = 2; i <= n; i += 2)
    sum += i;
  printf("The sum is --> %d\n", sum);
}

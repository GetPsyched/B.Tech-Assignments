#include <stdio.h>

int main()
{
  int n, sum = 0;
  printf("Enter n --> ");
  scanf("%d", &n);
  for (int i = 1, j = 1; i <= n; i++, j += 2)
    sum += j;
  printf("The sum is --> %d\n", sum);
}

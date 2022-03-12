#include <stdio.h>

int main()
{
  int n, i = 1;
  printf("Enter n --> ");
  scanf("%d", &n);
  for ( ; i <= n; i++)
  {
    for (int j = n; j >= i; j--)
      printf(" ");
    for (int j = 1; j <= 2*i - 1; j++)
      printf("*");
    printf("\n");
  }
  for ( ; i > 0; i--)
  {
    for (int j = n; j >= i; j--)
      printf(" ");
    for (int j = 1; j <= 2*i - 1; j++)
      printf("*");
    printf("\n");
  }
}

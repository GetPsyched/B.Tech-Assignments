#include <stdio.h>

int main()
{
  int n;
  printf("Enter n --> ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    {
      for (int j = n; j > i; j--)
        printf(" ");
      int j = 1;
      for ( ; j < i; j++)
        printf("%d", j%10);
      for ( ; j > 0; j--)
        printf("%d", j%10);
      printf("\n");
    }
}

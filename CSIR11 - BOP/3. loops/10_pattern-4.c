#include <stdio.h>

int main()
{
  int n;
  char s = 'A';
  printf("Enter n --> ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    {
      for (int j = n; j > i; j--)
        printf(" ");
      s = 'A';
      for (int j = 1; j <= 2*i - 1; j++, s++)
        printf("%c", s);
      printf("\n");
    }
}

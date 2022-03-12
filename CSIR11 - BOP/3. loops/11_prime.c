#include <stdio.h>

int main()
{
  int n, flag = 0;
  printf("Enter a number --> ");
  scanf("%d", &n);

  for (int i = 2; i <= n/2; i++)
      if (n % i == 0)
      { flag = 1; break; }

  if (n == 1)
    printf("\n1 is neither prime nor composite\n");
  else
    if (flag == 0)
        printf("\n%d is a prime number\n", n);
    else
        printf("\n%d is not a prime number\n", n);
}

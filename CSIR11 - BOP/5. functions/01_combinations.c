#include <stdio.h>

int fac(int n)
{
  int fact = 1;
  while (n > 0)
  { fact *= n; n--; }
  return fact;
}

int main()
{
  int n, r;
  printf("Enter n and r --> ");
  scanf("%d %d", &n, &r);
  printf("Value = %d", fac(n)/fac(r)*fac(n-r));
}

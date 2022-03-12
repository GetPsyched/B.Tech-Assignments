#include <stdio.h>

int main()
{
  int n, fact = 1;
  printf("Enter number --> ");
  scanf("%d", &n);
  if (n < 0)
    printf("\nInvalid Input\n");
  else
  {
    while (n > 0)
    { fact *= n; n--; }
    printf("Factorial = %d\n", fact);
  }
}

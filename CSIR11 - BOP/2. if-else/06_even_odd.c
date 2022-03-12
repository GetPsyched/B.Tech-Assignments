#include <stdio.h>

int main()
{
  int a;
  printf("Enter a number --> ");
  scanf("%d", &a);
  if (a % 2 == 0)
    printf("\nEVEN!\n");
  else
    printf("\nODD!\n");
}

#include <stdio.h>

int main()
{
  int n, sum=0, temp;
  printf("Enter n --> ");
  scanf("%d", &n);
  temp=n;
  while (n > 0)
  {
    sum = sum*10 + n % 10;
    n = n/10;
  }
  if (temp==sum)
    printf("\n%d is a palindrome\n", temp);
  else
    printf("\n%d is not a palindrome\n", temp);
}

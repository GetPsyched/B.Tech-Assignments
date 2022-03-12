#include <stdio.h>

int main()
{
  int sum_odd = 0, sum_even = 0, n;
  printf("Enter the number of elements in the array --> ");
  scanf("%d", &n);
  int array[n];
  for(int i=0 ; i < n ; i++)
  {
    printf("Enter element #%d --> ", i + 1);
    scanf("%d", &array[i]);
  }
  for (int i=0 ; i < n ; i++)
    if (i%2 != 0)
      sum_odd += array[i];
    else
      sum_even += array[i];
  printf("\nSum of elements in odd positions --> %d", sum_odd);
  printf("\nSum of elements in even positions --> %d\n", sum_even);
}

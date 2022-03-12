#include <stdio.h>

int main()
{
  int avg = 0, n;
  printf("Enter the number of elements in the array --> ");
  scanf("%d", &n);
  int array[n];
  for(int i=0 ; i < n ; i++)
  {
    printf("Enter element #%d --> ", i + 1);
    scanf("%d", &array[i]);
  }
  for (int i=0 ; i < n ; i++)
    avg += array[i];
  avg /= n;
  printf("\nAverage of elements in the given array is --> %d\n", avg);
}

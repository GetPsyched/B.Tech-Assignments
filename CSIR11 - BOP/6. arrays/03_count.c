#include <stdio.h>

int main()
{
  int avg = 0, n;
  printf("Enter the number of elements in the array --> ");
  scanf("%d", &n);
  int array[n], count[3] = {0, 0 , 0};
  for(int i=0 ; i < n ; i++)
  {
    printf("Enter element #%d --> ", i + 1);
    scanf("%d", &array[i]);
  }
  for(int i=0 ; i < n ; i++)
  {
    if (array[i] < 0) count[0]++;
    if (array[i]%2 == 0) count[1]++;
    else count[2]++;
  }
  printf("\nNumber of negative numbers --> %d", count[0]);
  printf("\nNumber of even numbers --> %d", count[1]);
  printf("\nNumber of odd numbers --> %d\n", count[2]);
}

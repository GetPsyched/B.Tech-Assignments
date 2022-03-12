#include<stdio.h>
int main()
{
  int n, large, large_2;
  printf("Enter the number of elements in the array --> ");
  scanf("%d", &n);
  int array[n];
  for(int i=0 ; i < n ; i++)
  {
    printf("Enter element #%d --> ", i + 1);
    scanf("%d", &array[i]);
  }
  large = array[0];
  large_2 = array[0];
  for(int i=1 ; i < n ; i++)
  {
    if (array[i] > large)
    {
      large_2 = large;
      large = array[i];
    }
    if (array[i] > large_2 && array[i] < large)
      large_2 = array[i];
  }
  printf("\n%d is the second largest in the given array\n", large_2);
}

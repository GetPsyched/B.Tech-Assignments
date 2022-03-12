#include<stdio.h>
int main()
{
  int n;
  printf("Enter the number of elements in the array --> ");
  scanf("%d", &n);
  int array[n];
  for(int i=0 ; i < n ; i++)
  {
    printf("Enter element #%d --> ", i + 1);
    scanf("%d", &array[i]);
  }
  for(int i=0; i < n%2 + n/2; i++)
    printf("Sum of %d: %d\n", i+1, array[i] + array[n-1-i]);
}

#include <stdio.h>

int main()
{
  int avg = 0, num, temp, large, small;
  printf("Enter the number of elements in the array --> ");
  scanf("%d", &num);
  int array[num];
  for(int i=0 ; i < num ; i++)
  {
    printf("Enter element #%d --> ", i + 1);
    scanf("%d", &array[i]);
  }
  large = array[0];
  small = array[0];
  for(int i=1 ; i < num ; i++)
  {
    if (array[i] > large)
      large = array[i];
    if (array[i] < small)
      small = array[i];
  }
  printf("\nLarge number is --> %d", large);
  printf("\nSmall number is --> %d", small);
}

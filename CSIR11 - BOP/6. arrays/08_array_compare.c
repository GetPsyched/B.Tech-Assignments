#include <stdio.h>

int main()
{
  int flag = 0, n1, n2;
  printf("Enter the number of elements in the first array --> ");
  scanf("%d", &n1);
  int array_1[n1];
  for(int i=0 ; i < n1 ; i++)
  {
    printf("Enter element #%d --> ", i + 1);
    scanf("%d", &array_1[i]);
  }
  printf("\nEnter the number of elements in the second array --> ");
  scanf("%d", &n2);
  int array_2[n2];
  for(int i=0 ; i < n2 ; i++)
  {
    printf("Enter element #%d --> ", i + 1);
    scanf("%d", &array_2[i]);
  }
  if (n1 == n2)
  {
    for (int i=0 ; i < n1 ; i++)
      if (array_1[i] != array_2[i])
      { printf("\nThe 2 given arrays are not equal\n"); return 0; }
  }
  else
  {
    printf("\nThe 2 given arrays are not equal\n");
    return 0;
  }
  printf("\nThe 2 given arrays are equal\n");
}

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
	for(int i=0 ; i < n ; i+=2)
		if(i == n-1)
			printf("\nDouble of element %d is %d\n", n, 2*array[n-1]);
		else
			printf("\nSum of element %d and %d is %d", i+1, i+2, array[i] + array[i+1]);
}

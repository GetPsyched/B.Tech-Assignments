#include<stdio.h>

int main(){
    int n, pos, large;
    printf("Enter the number of elements in the array --> ");
    scanf("%d", &n);
    int array[n];
    for(int i=0 ; i < n ; i++)
    {
      printf("Enter element #%d --> ", i + 1);
      scanf("%d", &array[i]);
    }
    large = array[0];
    for(int i=1; i < n; i++)
      if(array[i] > large)
      { large = array[i]; pos = i; }

    printf("\nNumber of elements before max value --> %d", pos);
    printf("\nNumber of elements after max value --> %d\n", n - pos - 1);
}

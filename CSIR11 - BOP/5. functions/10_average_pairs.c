#include <stdio.h>
float average(float arr[], int n)
{
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        avg += arr[i] / n;
    }
    return avg;
}
int aboveavg(float arr[], int n)
{
    float avg = average(arr, n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            count++;
        }
    }
    return count;
}
void pairs(float arr[], int n)
{
    float avg = average(arr, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j != i && arr[i] + arr[j] < avg)
            {
                printf("\nElement no.: %d & %d\nSum: %f\n", j + 1, i + 1, arr[i] + arr[j]);
            }
        }
    }
}
void main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element no. %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    printf("Average: %f\n", average(arr, n));
    printf("Number of elements above average: %d\n", aboveavg(arr, n));
    printf("Pairs having sum less than average: ");
    pairs(arr, n);
}
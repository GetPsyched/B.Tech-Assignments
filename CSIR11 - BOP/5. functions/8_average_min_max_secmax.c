#include <stdio.h>
int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
    }
    return max;
}
int min(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= min)
        {
            min = arr[i];
        }
    }
    return min;
}
float average(int arr[], int n)
{
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        avg += (float)arr[i] / n;
    }
    return avg;
}
int max2(int arr[], int n)
{
    int max1 = max(arr, n), max2 = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < max1 && arr[i] >= max2)
        {
            max2 = arr[i];
        }
    }
    return max2;
}
void main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element no. %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Max: %d\n", max(arr, n));
    printf("Min: %d\n", min(arr, n));
    printf("Average: %f\n", average(arr, n));
    printf("Max2: %d", max2(arr, n));
}
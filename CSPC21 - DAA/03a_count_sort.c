#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <climits>

int getMin(int n, int arr[])
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

void countSort(int n, int arr[])
{
    int sortedArray[n], count[100], i;

    for (i = 0; i < 100; i++)
        count[i] = 0;

    int min;
    min = getMin(n, arr);

    for (i = 0; i < n; i++)
        count[arr[i] - min]++;

    for (i = 1; i <= 100; i++)
        count[i] += count[i-1];

    for (i = 0; i < n; i++) {
        sortedArray[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (i = 0; i < n; ++i)
        arr[i] = sortedArray[i];
}

int main() {
    int n;
    printf("Enter the size of array --> ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array --> ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countSort(n, arr);

    printf("Sorted array --> ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

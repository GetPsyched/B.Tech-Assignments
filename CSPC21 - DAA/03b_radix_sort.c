#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <climits>

int getMax(int n, int arr[]) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int n, int arr[], int digit) {
    int sortedArray[n], count[10], i;

    for (i = 0; i < 10; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[(arr[i]/digit)%10]++;

    for (i = 1; i <= 9; i++)
        count[i] += count[i-1];

    for (i = n-1; i >= 0; i--) {
        sortedArray[count[(arr[i]/digit)%10] - 1] = arr[i];
        count[(arr[i]/digit)%10]--;
    }

    for (i = 0; i < n; ++i)
        arr[i] = sortedArray[i];
}

void radixSort(int n, int arr[]) {
    for (int digit=1; getMax(n, arr)/digit > 0; digit *= 10)
        countSort(n, arr, digit);
}

void radix2(int n, int arr[]) {
    return
}

int main() {
    int n;
    printf("Enter the size of array --> ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array --> ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radixSort(n, arr);

    printf("Sorted array --> ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

#include <stdio.h>

void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for(int j=low; j < high; j++)
        if(arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    swap(&arr[i], &arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int index = partition(arr, low, high);

        quickSort(arr, low, index-1);
        quickSort(arr, index+1, high);
    }
}

int main() {
    int n;
    printf("Enter the size of array --> ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array --> ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array --> ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

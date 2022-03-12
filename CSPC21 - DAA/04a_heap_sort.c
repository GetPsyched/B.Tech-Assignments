#include <stdio.h>

void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

void maxHeapifyRecursive(int arr[], int n, int i) {
    int largest = i;
    int leftChild = 2*i + 1, rightChild = 2*i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    else if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapifyRecursive(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapifyRecursive(arr, n, i);
}

void heapSortRecursive(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapifyRecursive(arr, i, 0);
    }
}

void heapSortIterative(int arr[], int n) {
    buildMaxHeap(arr, n);
    for(int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        int parent = 0;
        int child = 2*parent + 1;
        while (child < i) {
            if (child < i-1 && arr[child] < arr[child+1])
                child++;
            if (child < i && arr[child] > arr[parent])
                swap(&arr[child], &arr[parent]);
            parent = child;
            child = 2*parent + 1;
        }
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

    heapSortIterative(arr, n);

    printf("Sorted array --> ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

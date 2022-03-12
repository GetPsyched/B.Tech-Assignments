#include <stdio.h>

void merge (int arr[], int lower, int mid, int upper) {
    int i, j, k;
    int n1 = mid - lower + 1;
    int n2 = upper - mid;

    int left[n1], right[n2];
    for(i = 0; i < n1; i++)
        left[i] = arr[lower+i];
    for(j = 0; j < n2; j++)
        right[j] = arr[mid+1+j];

    i=0; j=0; k=lower;

    while((i < n1) && (j < n2)) {
        arr[k] = left[i] <= right[j] ? left[i++] : right[j++];
        k++;
    }
    while(i < n1) {
        arr[k] = left[i];
        i++; k++;
    }
    while(j < n2) {
        arr[k] = right[j];
        j++; k++;
    }
}

void mergeSort(int arr[],int lower, int upper) {
    if(lower < upper) {
        int mid = (lower + upper) / 2;
        mergeSort(arr, lower, mid);
        mergeSort(arr, mid+1, upper);
        merge(arr, lower, mid, upper);
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array --> ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

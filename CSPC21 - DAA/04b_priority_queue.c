#include <stdio.h>

struct process {
    int pID;
    int priority;
};

void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

int heapMaximum(struct process p[], int arr[], int n) {
    int priority = arr[0], pID;
    for(int i = 0; i < n; i++)
        if (p[i].priority == priority)
            pID = p[i].pID;
    return pID;
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

int deleteMax(struct process p[], int arr[], int *n) {
    if (n < 0)
        printf("Underflow");
    else {
        int maxPriority = arr[0], pID;
        arr[0] = arr[*n-1];
        *n = *n - 1;
        maxHeapifyRecursive(arr, *n, 0);
        for(int i = 0; i < n; i++)
            if (p[i].priority == maxPriority)
                pID = p[i].pID;
       return pID;
    }
}

void heapIncreaseKey(int arr[], int n, int pID, int priority, struct process p[]) {
    int prevPriority, j;
    for(int i = 0; i < n; i++)
        if(p[i].pID == pID) {
            prevPriority = p[i].priority;
            p[i].priority = priority;
            break;
        }

    for(j = 0; j < n; j++)
        if(arr[j] == prevPriority) { arr[j] = priority; break; }

    while (j > 0 && arr[(j - 1)/2] < arr[j]) {
        swap(&arr[j], &arr[(j - 1)/2]);
        j = (j-1)/2;
    }
    printf("Key has been increased.");
}

int search(struct process p[], int n, int pID) {
    int priority;
    for(int i = 0; i < n; i++)
        if(p[i].pID == pID) { priority = p[i].priority; break; }
    return priority;
}

int main() {
    int n;
    printf("Enter number of processes --> ");
    scanf("%d", &n);

    struct process p[n];
    printf("Enter process ID along with its priority:\n");
    for(int i = 0; i < n; i++) {
        printf("%d --> ", i+1);
        scanf("%d %d", &p[i].pID, &p[i].priority);
    }

    int arr[n];
    for(int i = 0; i < n; i++)
        arr[i] = p[i].priority;

    buildMaxHeap(arr, n);

    int ch, priority, pID, elem;
    do {
        printf("\n1. Get process ID with highest priority");
        printf("\n2. Delete process ID with highest priority");
        printf("\n3. Increase priority of a process ID");
        printf("\n4. Get priority of a process ID");
        printf("\n5. Exit");
        printf("\nEnter choice --> ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Process ID with highest priority: %d", heapMaximum(p, arr, n));
                    break;
            case 2: printf("Element with highest priority: %d", deleteMax(p, arr, &n));
                    printf("\nElement has also been removed.");
                    break;
            case 3: printf("Enter process ID --> ");
                    scanf("%d", &pID);
                    printf("Enter new priority --> ");
                    scanf("%d", &priority);
                    heapIncreaseKey(arr, n, pID, priority, p);
                    break;
            case 4: printf("Enter process ID --> ");
                    scanf("%d", &pID);
                    printf("Priority of this process ID --> %d", search(p, n, pID));
            case 5: break;
            default:
                    printf("Invalid input");
        }
    } while (ch != 5);
}

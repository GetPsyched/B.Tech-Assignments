
#include <iostream>
using namespace std;

void swap(int *a , int *b){
    int *temp;
    temp=a;
    a=b;
    b=temp;
}

void selectionsort(int a[],int n){
    
    for(int i=0;i<n-1;i++){
       int  min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(&a[i],&a[min]);
    }
}

void bubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
            
    }
}

void insertionsort(int a[], int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

void dispay(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<< " ";
    }
    cout<<endl;
}

int main() {
    int a[50]={5,4,7,8,6,3,65,77,88,83 ,34,124,137,228,346,354,665,477,388,583,52,42,72,82,62,32,651,771,881,831,57,46,79,85,69,300,658,777,883,833,523,423,723,823,623,323,652,771,881,821};
    
    insertionsort(a, 50);
    dispay(a, 50);
    
    return 0;
}

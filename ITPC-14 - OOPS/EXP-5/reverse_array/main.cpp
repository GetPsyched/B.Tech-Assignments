#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
 

int main() {
    int size;
    cout<<"Enter size:"<<endl;
    cin>>size;
    int a[size];
    
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    int j=0;
    int k=size-1;
    while (j<k) {
        swap(&a[j],&a[k]);
        j++;
        k--;
    }
    for(int i=0;i<size;i++){
        cout<<a[i];
    }
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int a[10];
    
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    
    int *p[10];
    for(int i=0;i<10;i++){
        p[i]=&a[i];
    }
    
    //insertion sort to sort in ascending order
    
    for(int i=1;i<=10;i++){
        int * temp = p[i];
        int j=i-1;
        while(j>=0 && p[j]>temp){
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=temp;
    }
    
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //to print in descneding order
    for(int j=9;j>=0;j--){
        cout<<a[j]<<" ";
    }
 
    return 0;
}

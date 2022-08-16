//
//  main.cpp
//  q3
//
//  Created by Harshvardhan on 13/05/22.
//

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
    cin>>size;
    
    int num[size];
    
    for(int i=0;i<size;i++){
        cin>>num[i];
    }
    int j=0;
    int k=size-1;
    
    while(j<k){
        swap(&num[j],&num[k]);
        j++;
        k--;
    }
    for(int i=0;i<size;i++){
        cout<<num[i];
    }
    
    
    return 0;
}

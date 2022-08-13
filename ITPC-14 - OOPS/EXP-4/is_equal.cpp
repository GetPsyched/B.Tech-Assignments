

#include <iostream>
using namespace std;
int main() {
    int size=0;
    cin>>size;
    int a[size],b[size];
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<size;i++){
        cin>>b[i];
    }
    
    bool flag=0;
    
    for(int i=0;i<size;i++){
        if(a[i]!=b[i]){
            flag=1;
            break;
        }
    }
    
    if(flag==1){
        cout<<"not equal"<<endl;
    }
    else{
        cout<<" equal"<<endl;
    }
    return 0;
}

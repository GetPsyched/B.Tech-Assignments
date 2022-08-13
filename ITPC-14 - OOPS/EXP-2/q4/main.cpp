//
//  main.cpp
//  q4
//
//  Created by Harshvardhan on 13/05/22.
//

#include <iostream>
using namespace std;

int main() {
    int n; cin>>n;
        int a[n];
        int flag=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int j=0;
        int k=n-1;
        while(j<k){
            if(a[j]!=a[k]){
                flag=1;
                break;
            }
            j++;
            k--;
        }
        
        if(flag==1){
            cout<<"Not pallindrome"<<endl;
        }
        else{
            cout<<" pallindrome"<<endl;
        }

    return 0;
}

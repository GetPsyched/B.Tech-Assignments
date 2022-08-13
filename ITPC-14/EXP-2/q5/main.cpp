//
//  main.cpp
//  q5
//
//  Created by Harshvardhan on 13/05/22.
//

#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int num; cin >> num;
   int  original_num=num;
    int n=0,power,result=0,remainder;
    
    while(original_num !=0){
        original_num /=10;
        n++;
    }
    original_num=num;
    while (original_num!=0) {
        remainder=original_num % 10;
        power = round(pow(remainder,n));
        result+=power;
        original_num/=10;
        
    }
    if(result==num)
        cout<<" num is armstrong"<<endl;
    else
        cout<<"num is not armstrong"<<endl;
    return 0;
}

//
//  main.cpp
//  q1
//
//  Created by Harshvardhan on 13/05/22.
//

#include <iostream>
using namespace std;

int main() {
    float num; cin >> num;
    
    float value= (int)(num*100+0.5);
    
    cout<< (float)value/100<<"0000"<<endl;
    
    return 0;
}

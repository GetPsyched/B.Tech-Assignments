//
//  main.cpp
//  q3
//
//  Created by Harshvardhan on 13/05/22.
//

#include <iostream>
using namespace std;

int main() {
    double num;
    cin >> num;
    
    cout<<"floor value is "<<int(num)<<endl;
    cout<<"floor value is "<<int(num)+ 1<<endl;
    
    float value= (int)(num*100+0.5);
    
    cout<< (float)value/100<<endl;
    
    
    return 0;
}

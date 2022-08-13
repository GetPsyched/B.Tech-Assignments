//
//  main.cpp
//  q7
//
//  Created by Harshvardhan on 13/05/22.
//

#include <iostream>
using namespace std;

int main() {
    
    int a,b; cin >> a >> b;
    
    a = a^b;
    b = a^b;
    a = a^b;
    
    cout << "a is " << a << "b is" << b << endl;
    return 0;
}

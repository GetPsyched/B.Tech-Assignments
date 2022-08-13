//
//  main.cpp
//  q2
//
//  Created by Harshvardhan on 13/05/22.
//

#include <iostream>
using namespace std;

int fib(int n){
    if(n==0 || n==1)
        return n;
    else
        return fib(n-1)+fib(n-2);
}

int main() {
    cout<< fib(5) << endl;
    return 0;
}

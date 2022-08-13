
#include <iostream>
using namespace std;


int main() {
    
    int a,b,c; cin >> a >> b >> c;
    
    int x;
    x = (a>b)?((a>c)?a:c):((b>c)?b:c);
    
    cout << x << endl;
    
    return 0;
}

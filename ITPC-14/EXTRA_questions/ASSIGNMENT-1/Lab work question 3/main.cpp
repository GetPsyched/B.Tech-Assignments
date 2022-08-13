
#include <iostream>
#include <math.h>

using namespace std;

class Cylinder{
    int r;
    int h;
public:
    
    Cylinder(int x,int y)
    {
        r=x;
        h=y;
    }
    
    int volume(int r,int h);
    int base_area(int r,int h);
    int surface_area(int r,int h);
};

int Cylinder :: volume(int r, int h)
{
    return 3.14*r*r*h;
}

int Cylinder :: base_area(int r, int h)
{
    return 3.14*r*r;
    
}

int Cylinder :: surface_area(int r, int h)
{
    return 2*3.14*r*h;
}



int main() {
    Cylinder c = Cylinder(3, 4);
    cout<<c.volume(3, 4)<<endl;
    cout<<c.base_area(3, 4)<<endl;
    cout<<c.surface_area(3, 4)<<endl;
    return 0;
}





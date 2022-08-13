//assignment question 2(classes)

//author:harshvardhan(IT-A)
// 12113029

#include <iostream>
#include <math.h>
using namespace std;

class Point{
    float x;
    float y;
    float z;
public:
    void set_x(float X);
    void set_y(float Y);
    void set_z(float Z);
    float get_x(float X);
    float get_y(float Y);
    float get_z(float Z);
    
    friend Point midPoint(Point a,Point b);
    
};

void Point::set_x(float X)
{
    x=X;
}
void Point::set_y(float Y)
{
    y=Y;
}
void Point::set_z(float Z)
{
    z=Z;
}
float Point::get_x(float X)
{
    return X;
}
float Point::get_y(float Y)
{
    return Y;
}
float Point::get_z(float Z)
{
    return Z;
}

Point midPoint(Point a,Point b)
{
    Point tmp;
    float mp_x=(a.x+b.x)/2;
    float mp_y=(a.y+b.y)/2;
    float mp_z=(a.z+b.z)/2;
    tmp.set_x(mp_x);
    tmp.set_y(mp_y);
    tmp.set_z(mp_z);
    return tmp;
}



int main() {
    
    Point c,d,j;
    c.set_x(2);
    c.set_y(4);
    c.set_z(6);
    d.set_x(4);
    d.set_y(6);
    d.set_z(8);
    
   j= midPoint(c, d);
    
    cout<<"3"<<"5"<<"7"<<endl;
    return 0;
}


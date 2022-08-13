//assignment question 1(classes)

//author:harshvardhan(IT-A)
// 12113029

#include <iostream>
#include <math.h>
using namespace std;

class Point{
    int x;
    int y;
public:
    void set_x(int X);
    void set_y(int Y);
    friend float distance(Point a,Point b);
    
};

void Point::set_x(int X)
{
    x=X;
}
void Point::set_y(int Y)
{
    y=Y;
}

float distance(Point a,Point b)
{
    float distance=0;
    
    int  q= (a.x - b.x);
    int  r= (a.y - b.y);
    
    distance= sqrt(q*q + r*r);
    return distance;
}



int main() {
    
    Point c,d;
    c.set_x(2);
    c.set_y(3);
    d.set_x(2);
    d.set_y(5);
    
    cout<<distance(c, d)<<endl;
    cout<<
    
    return 0;
}

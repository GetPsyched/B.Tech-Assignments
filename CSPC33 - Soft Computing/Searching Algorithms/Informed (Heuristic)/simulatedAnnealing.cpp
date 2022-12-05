// implemented simulated annealing in C++ to
// minimize (x-2)^2+(y-1)^2 in range of -30 to 30.
#include <bits/stdc++.h>
using namespace std;

double func(double x, double y)
{
    return (pow(x-2, 2)+pow(y-1, 2));
}
double accept(double z, double minim, double T,double d)
{
    double p = -(z - minim) / (d * T);
    return pow(exp(1), p);
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main()
{
    srand (time(NULL));
    double x = fRand(-30,30);
    double y = fRand(-30,30);
    double xm = x, ym=y;
    double tI = 100000;
    double tF = 0.000001;
    double a = 0.99;
    double d=(1.6*(pow(10,-23)));
    double T = tI;
    double minim = func(x, y);
    double z;
    double counter=0;

    while (T>tF) {
        int i=1;
        while(i<=30) {
            x=x+fRand(-0.5,0.5);
            y=y+fRand(-0.5,0.5);
            z=func(x,y);
            if (z<minim || (accept(z,minim,T,d)>(fRand(0,1)))) {
                minim=z;
            }
            i=i+1;
        }
        counter=counter+1;
        T=T*a;
        xm=x;
        ym=y;
    }

    cout<<"min: "<<minim<<" x: "<<xm<<" y: "<<ym<<endl;
    return 0;
}
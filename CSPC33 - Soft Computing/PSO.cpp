#include<bits/stdc++.h>
#include<random>
using namespace std;

class PSO
{
  public:
  int n=50,d=3,minx=-10,maxx=10,mat_iter=100,w=0.729,c1=1.494,c2=1.494;
  vector<double> pos(n),velocity(n),fitness(n),bestPos(n),bestFitness(n);
  PSO()
  {
      for(int i=0;i<n;i++)
      {
        velocity[i]=fitness[i]=bestPos[i]=bestFitness[i]=0.0;
      }
      
      void evalFitness()
      {
        for(int itr=1;itr<=mat_iter;itr++)
        {
            int r1,r2;
            for(int i=0;i<N;i++)
            {
                r1=random.rand(d);
                r2=random.rand(d);
                velocity[i]=w*velocity[i]+r1*c1*(bestPos[i]-pos[i])+r2*c2*(best)
            }
        }
      }
  }
};

int main()
{
    int d,minx,maxx,n,mat_iter,w,c1,c2;
    
    return 0;
}
include<bits/stdc++.h>
using namespace std;

int NANTS,ngene;

class Data {
public:
    vector< vector<double> > cost;
    vector< vector<double> > vis;
    vector< vector<double> > T;
    int N;
    Data() {
        cout<<"Enter the number of Places: "<<endl;
        cin>>N;                                                     // N cities
        vector< double> L,M,U;
        cost.push_back(L);
        T.push_back(M);
        vis.push_back(U);
        cout<<"Enter the ajacency matrix: "<<endl;
        for(int i=0;i<N;i++) {
            vector<double> V(N+1);
            vector<double> t(N+1);
            vector<double> l(N+1);
            for(int j = 1; j<=N ; j++) {
                cin>>V[j];
                t[j] = 1.0;
                if(V[j] != 0) {
                    l[j] = 1/ V[j];
                }
            }
            cost.push_back(V);
            T.push_back(t);
            vis.push_back(l);
        }
    }

    double tourcost(vector<int> C) {
        int l = C.size();
        double tourcost = 0.0;
        l = l-1;
        for (int i=0;i <l; i++) {
            tourcost += cost[C[i]][C[i+1]];
        }
        tourcost += cost[C[l]][C[0]];
        return tourcost;
    }

    void print(vector<int> C) {
        for(int i=0;i<C.size();i++)
            printf("%d ",C[i]);
        printf("\n");
    }

};

Data d;                                             // global data construct

class Ant {
public:
    vector<int> trail;
    set<int> available;
    double alpha;                               // importance of the pheromone level
    double beta;                                // importance of the vis
    Ant(double a,double b) {
        alpha = a;
        beta = b;
        trail.push_back(1);                     // always start from the nest (1)
        for(int i=2;i<=d.N;i++) {
            available.insert(i);
        }
    }
    void reset() {
        vector<int> L;
        L.push_back(1);
        trail = L;                              // reset to nest.
        for(int i=2;i<=d.N;i++) {
            available.insert(i);
        }
    }
    void deposit() {
        double tourcost = d.tourcost(trail);
        int Q = 100;
        double depositAmount = Q / tourcost;
        int l = trail.size();
        l = l-1;
        for (int i=0;i <l; i++) {
            d.T[trail[i]][trail[i+1]] += depositAmount;
        }
        d.T[trail[l]][trail[0]] += depositAmount;
    }

    vector<int> stop() {
        deposit();
        vector<int> temp = trail;
        reset();
        return temp;
    }

    void step() {
        int currentCity = trail[trail.size()-1];
        double norm = probabilityNorm(currentCity);
        double p,gp;
        bool moved = false;
        double highestProb = 0;
        double cityHighest = 0;
        for(set<int>::iterator i=available.begin(); i != available.end() ; i++) {
            p = moveProbability(currentCity,*i,norm);
            if (p > highestProb) {
                cityHighest = *i;
                highestProb = p;
            }
            gp = getRand();
            if (gp <= p) { // move
                moved = true;
                trail.push_back(*i);
                available.erase(i);
                break;
            }
        }
        if(!moved) {
            // make a move to the highest available prob city
            // move to cityHighest
            trail.push_back(cityHighest);
            available.erase(cityHighest);
        }
    }

    double getRand() {
            double p = (rand() / (RAND_MAX + 1.0));
        return p;
    }

    double moveProbability(int i,int j,double norm) {
        double p = (pow(d.T[i][j],alpha))*(pow(d.vis[i][j],beta));
        p /= norm;
        return p;
    }

    double probabilityNorm(int currentCity) {
        int size = available.size();
        double norm = 0.0;
        for(set<int>::iterator i=available.begin(); i != available.end() ; i++) {
            norm += (pow(d.T[currentCity][*i],alpha))*(pow(d.vis[currentCity][*i],beta));
        }
        return norm;
    }

};

class acoe {
public:
    int N;                      // cities
    int M;                      // no.of ants
    vector<Ant> ant;            // ants
    double evaporation;         // evaporation rate
    double alpha;               // importance of the pheromone level
    double beta;                // importance of the vis

    acoe(double a,double b,double e) {
        alpha = a;
        beta = b;
        evaporation = e;
        N = d.N;
        M = NANTS;              // ants
        for(int i=0; i<M; i++) {
            Ant a(alpha,beta);
            ant.push_back(a);
        }
    }

    void run() {
        vector<int> PATH;
        double minTour,tourC;
        for(int n=0;n<ngene; n++) {
            for(int p=0; p<(N-1); p++){
                for(int i=0;i<M;i++) {
                    ant[i].step();
                }
            }
            for(int i=0;i<M;i++) {
                vector<int> p = ant[i].stop();
                if(!PATH.size()) {
                    PATH = p;
                    minTour = d.tourcost(p);
                    continue;
                }
                tourC = d.tourcost(p);
                if(tourC < minTour) {
                    minTour = tourC;
                    PATH = p;
                }
            }
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=N;j++) {
                    d.T[i][j] *= evaporation;
                }
            }
        }
        cout<<endl;
        cout<<"Minimum cost for the TSP is: "<<minTour<<endl;
        cout<<"Path for the minimum travel is :"<<endl;
        d.print(PATH);
    }
};

int main(void) {
    time_t t;
    srand(time(&t));
    double alpha;                               
    double beta;                                
    double evaporation;                         
    cout<<"Enter number of generations: "<<endl;
    cin>>ngene;
    cout<<"Enter number of ants: "<<endl;
    cin>>NANTS;
    cout<<"Enter the value of alpha: "<<endl;
    cin>>alpha;
    cout<<"Enter the value of beta: "<<endl;
    cin>>beta;
    cout<<"Enter the value of evaporation: "<<endl;
    cin>>evaporation;
    acoe colony(alpha,beta,evaporation);
    colony.run();
    return 0;
}
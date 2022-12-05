//C++ program to implement best first search in a graph where cost of visiting each node
//is provided
#include<bits/stdc++.h>
using namespace std;


void bestFirstSearch(vector<pair<int,int>> adj[],int n,int src,int goal) {
    //visited array for nodes
    vector<int> vis(n,0);
    //min-heap prioirty queue
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //insert source in pq
    pq.push({0,src});
    vis[src]=1;
    while(!pq.empty()) {
        int curr=pq.top().second;
        int cost=pq.top().first;
        pq.pop();
        cout<<curr<<" ";
        if(curr==goal) {
            cout<<"\nTarget value is found."<<endl;
            break;
        }
        for(int i=0;i<adj[curr].size();i++)
        {
            if(!vis[adj[curr][i].second]){
            vis[adj[curr][i].second]=1;
            pq.push({adj[curr][i].first,adj[curr][i].second});}

        }
    }
}

int main()
{
    int v;
    cout<<"Enter no. of vertices in graph:";
    cin>>v;
    vector<pair<int,int>> adj[v];//pair <cost,node>
    int e;
    cout<<"Enter no. of edges:";
    cin>>e;
    cout<<"Insert edges(src,dest,cost):"<<endl;
    while(e--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({cost,v});
        adj[v].push_back({cost,u});
    }
    int src,goal;
    cout<<"Enter source node:";
    cin>>src;
    cout<<"Enter goal node:";
    cin>>goal;
    bestFirstSearch(adj,v,src,goal);
    return 0;
}
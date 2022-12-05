#include<bits/stdc++.h>
using namespace std;


// function for dfs 
bool dfs(vector<pair<int,int>> adj[],int val,int depth,int src)
{
    if(depth<=-1) return false;
    if(src==val) return true;
    for(auto it:adj[src])
    {
        if(dfs(adj,val,depth-1,it.first)) return true;
    }
    return false;
}

// function to print graph
void printGraph(vector<pair<int,int>> adj[],int n)
{
    cout<<"Adjency list of graph is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"--";
        for(auto it:adj[i])
        {
            cout<<"--"<<it.first;
        }
        cout<<endl;
    }
}

int main()
{
    int n,e,u,v,wt;
    cout<<"Enter no. of vertices and edges in graph:";
    cin>>n>>e;
    vector<pair<int,int>> adj[n];
    cout<<"Enter edges and their weights:"<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    /*print graph*/
    printGraph(adj,n);
    int d,val;
    cout<<"Enter maximum depth till you want to search:";
    cin>>d;
    cout<<"Enter value you want to search:";
    cin>>val;
    int flag=0;
    for(int i=1;i<=d;i++)
    {
        if(dfs(adj,val,d,0)) {
            cout<<"Value is found at depth "<<i<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0) cout<<"Value is not found."<<endl;
    return 0;
}
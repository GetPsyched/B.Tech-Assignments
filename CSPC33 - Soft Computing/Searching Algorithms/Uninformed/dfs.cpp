//DFS Traversal of Graph
#include<bits/stdc++.h>
using namespace std;

//A recursive function to traverse a node and its adjcents using dfs
void dfs(vector<int> &storeDfs,vector<int> &visited,vector<int> adj[],int node)
{
   storeDfs.push_back(node);
   visited[node]=1;
   for(auto it:adj[node])
   {
    if(!visited[it])
       dfs(storeDfs,visited,adj,it);
   }
}

vector<int> dfsOfGraph(int vertices,vector<int> adj[])
{
    vector<int> storeDfs;
    vector<int> visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
          dfs(storeDfs,visited,adj,i);
    }
    return storeDfs;
}

int main()
{
    int edges,vertices;
    cout<<"Enter no. of edges and vertices:";
    cin>>edges>>vertices;
    //If Graph has 0-based indexing then we will create vector<int> adj[n]
    //If Graph has 1-based indexing then we will create vector<int> adj[n+1]
    //If Graph is a weighted graph, then we will create vector<pair<int,int>> adj[n]
    vector<int> adj[vertices+1];
    vector<int> dfsTraversal;
    for(int i=1;i<=edges;i++)
    {
        int src,dest;
        cin>>src>>dest;
        //Since an undirected graph
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    //Printing the graph in form of a adjency list
    cout<<"Graph Representation is:"<<endl;
    for(int i=0;i<vertices;i++)
    {
        cout<<i<<"--->";
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    dfsTraversal=dfsOfGraph(vertices,adj);
    cout<<"Dfs traversal is:"<<endl;
    for(auto it:dfsTraversal)
    {
        cout<<it<<" ";
    }
    return 0;
}

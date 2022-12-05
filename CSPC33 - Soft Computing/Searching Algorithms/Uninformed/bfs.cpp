#include<bits/stdc++.h>
using namespace std;

//A function for BFS traversal of graph, which takes a adjency list of nodes and
//no. of nodes as input
vector<int> bfs(int vertices,vector<int> adj[])
{
    vector<int> visited(vertices+1,0);
    vector<int> temp;
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            visited[i]=1;
            q.push(i);
            temp.push_back(i);
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(auto it:adj[node])
                {
                    if(!visited[it])
                    {
                        visited[it]=1;
                        q.push(it);
                        temp.push_back(it);
                    }
                }
            }
        }
    }
    return temp;
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
    vector<int> bfsVector;
    for(int i=1;i<=edges;i++)
    {
        int src,dest;
        cin>>src>>dest;
        //Since an undirected graph
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    //Printing the graph in form of a adjency matrix
    cout<<"Graph Representation is:"<<endl;
    for(int i=0;i<=vertices;i++)
    {
        cout<<i<<"--->";
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    //Calling function for BFS traversal
    bfsVector=bfs(vertices,adj);
    for(auto it:bfsVector)
    {
        cout<<it<<" ";
    }
    return 0;
}
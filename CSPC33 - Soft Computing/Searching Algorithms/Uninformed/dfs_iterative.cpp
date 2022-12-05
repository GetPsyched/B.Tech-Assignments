//Iterative dfs traversal
#include<bits/stdc++.h>
using namespace std;



void dfsOfGraph(int vertices,vector<int> adj[])
{
    vector<int> vis(vertices,0);
    stack<int> st;
    vector<int> dfs;
    for(int i=0;i<vertices;i++)
    {
        if(!vis[i])
        {
            st.push(i);
            vis[i]=1;
            while(!st.empty())
            {
                int top=st.top();
                st.pop();
                cout<<top<<" ";
                for(auto it:adj[top])
                {
                    if(!vis[it]){
                        vis[it]=1;
                        st.push(it);
                    }
                }
            }
        }
    }
    cout<<endl;
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
    dfsOfGraph(vertices,adj);
    return 0;
}

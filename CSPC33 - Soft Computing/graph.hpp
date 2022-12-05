#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<vector<int>> adj;

public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
    }

    void add_edge(int v, int w) {
        adj[v].push_back(w);
    }
};

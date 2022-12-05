#include <bits/stdc++.h>
using namespace std;

int breadth_first_search(Graph g, int source) {
    vector<bool> visited;
    visited.resize(g.v, false);

    list<int> queue;
    visited[source] = true;
    queue.push_back(s);

    while(!queue.empty()) {
        s = queue.front()
        cout << s << ' ';
        queue.pop_front();

        for (auto adjacent: g.adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

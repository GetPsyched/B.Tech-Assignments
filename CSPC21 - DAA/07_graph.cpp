#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void fillOrder(int s, bool visitedV[], stack<int> &Stack) {
        visitedV[s] = true;

        list<int>::iterator i;
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visitedV[*i])
        fillOrder(*i, visitedV, Stack);

        Stack.push(s);
    }
    void DFS(int s, bool visitedV[]) {
        visitedV[s] = true;
        cout << s << " ";

        list<int>::iterator i;
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visitedV[*i])
        DFS(*i, visitedV);
    }

    public:
        Graph(int V) {
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int s, int d) {
            adj[s].push_back(d);
        }

        void printSCC() {
            stack<int> Stack;

            bool *visitedV = new bool[V];
            for (int i = 0; i < V; i++)
                visitedV[i] = false;

            for (int i = 0; i < V; i++)
                if (visitedV[i] == false)
                    fillOrder(i, visitedV, Stack);

            Graph gr = transpose();

            for (int i = 0; i < V; i++)
                visitedV[i] = false;

            while (Stack.empty() == false) {
                int s = Stack.top();
                Stack.pop();

                if (visitedV[s] == false) {
                    gr.DFS(s, visitedV);
                    cout << endl;
                }
            }
        }
        Graph transpose() {
            Graph g(V);
            for (int s = 0; s < V; s++) {
                list<int>::iterator i;
                for (i = adj[s].begin(); i != adj[s].end(); ++i)
                    g.adj[*i].push_back(s);
            }
            return g;
        }
};

int main() {
    Graph graph(8);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 0);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    graph.addEdge(6, 4);
    graph.addEdge(6, 7);

    cout << "SCC of a directed graph:\n";
    graph.printSCC();
}

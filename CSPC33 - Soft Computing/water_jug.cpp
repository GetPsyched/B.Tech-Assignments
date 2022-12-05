#include <bits/stdc++.h>
using  namespace std;

class JugsGraph {
    set<pair<int, int>> jug_states;
    map<pair<int, int>, set<pair<int, int>>> adj;

public:
    void add_edge(pair<int, int> v, pair<int, int> w) {
        adj[v].insert(w);
    }

    pair<pair<int, int>, pair<int, int>> empty(pair<int, int> initial_state) {
        auto result = make_pair(initial_state, initial_state);
        result.first.first = 0;
        result.second.second = 0;
        add_edge(initial_state, result.first);
        add_edge(initial_state, result.second);
        return result;
    }

    pair<pair<int, int>, pair<int, int>> fill(pair<int, int> initial_state) {
        auto result = make_pair(initial_state, initial_state);
        result.first.first = 3;
        result.second.second = 4;
        add_edge(initial_state, result.first);
        add_edge(initial_state, result.second);
        return result;
    }

    pair<pair<int, int>, pair<int, int>> transfer(pair<int, int> initial_state) {
        int capacity;
        auto result = make_pair(initial_state, initial_state);

        capacity = abs(3 - result.first.first);
        result.first.first += min(capacity, result.first.second);
        result.first.second -= min(capacity, result.first.second);

        capacity = abs(4 - result.second.second);
        result.second.second += min(capacity, result.second.first);
        result.second.first -= min(capacity, result.second.first);

        add_edge(initial_state, result.first);
        add_edge(initial_state, result.second);
        return result;
    }

    void create(pair<int, int> initial_state) {
        set<pair<int, int>> states;

        auto empty_states = empty(initial_state);
        states.insert({empty_states.first, empty_states.second});
        auto full_states = fill(initial_state);
        states.insert({full_states.first, full_states.second});
        auto transferred_states = transfer(initial_state);
        states.insert({transferred_states.first, transferred_states.second});

        for (auto state : states) {
            if (jug_states.find(state) == jug_states.end()) {
                jug_states.insert(state);
                create(state);
            }
        }
    }

    void print() {
        for (auto [parent_state, child_states] : adj) {
            cout << '(' << parent_state.first << ", " << parent_state.second << ") --> ";
            for (auto child_state : child_states)
                cout << '(' << child_state.first << ", " << child_state.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    JugsGraph g;
    g.create(make_pair(0, 0));
    g.print();
}

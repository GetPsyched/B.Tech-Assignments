#include <bits/stdc++.h>
#define N 3

using namespace std;

struct PuzzleState {
	vector<vector<int>> data;
	int cost;
	int x, y;

    PuzzleState() { cost = INT_MAX; }

	PuzzleState(vector<vector<int>> &data, vector<vector<int>> &goal_state, int x, int y) {
		this->data = data;
		this->x = x;
		this->y = y;

		cost = costCalculator(goal_state);
	}

	int costCalculator(vector<vector<int>>& goal_state) {
		int mismatch = 0;

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if(data[i][j] != goal_state[i][j] && data[i][j] != 0) mismatch++;

		return mismatch;
	}

	string to_string() {
		string build = "";

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				build += data[i][j];

		return build;
	}

	void print() {
		cout << endl;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j)
				cout << data[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}

	int energy() { return cost; }
    bool equals(vector<vector<int>> &goal) {
        for(int i =0; i<N; i++) {
            for(int j =0; j<N; j++) {
                if(data[i][j] != goal[i][j]) return false;
            }
        }
        return true;
    }
};

vector<PuzzleState> getNeighbours(PuzzleState &curr, vector<vector<int>> &goal_state) {
    int row_off[] = {-1, 1, 0, 0};
	int col_off[] = {0, 0, -1, 1};
    vector<vector<int>> data = curr.data;
    vector<PuzzleState> ne;
    for(int i =0; i<4; i++) {
        int x = curr.x + row_off[i];
		int y = curr.y + col_off[i];

		if(x < 0 || y < 0 || x >= N || y >= N) continue;

		swap(data[curr.x][curr.y], data[x][y]);

		PuzzleState curr_state(data, goal_state, x, y);
        ne.push_back(curr_state);
		swap(data[curr.x][curr.y], data[x][y]);
    }
    return ne;
}

int main() {
	srand(time(0));

	vector<vector<int>> initialState = {
		{1, 0, 3},
		{8, 2, 4},
		{7, 6, 5}
	};

	vector<vector<int>> goal_state = {
		{0, 2, 3},
		{1, 8, 6},
		{5, 7, 4}
	};

    vector<string> tabuList;
    PuzzleState best_state;

    int times = 15;
    PuzzleState initial(initialState, goal_state, 1, 1);
    best_state = initial;
    PuzzleState curr_state = initial;

    tabuList.push_back(curr_state.to_string());

    while(times--) {
        curr_state.print();
        if(curr_state.equals(goal_state)) {
            break;
        }

        PuzzleState curr_best;
        vector<PuzzleState> neighbours = getNeighbours(curr_state, goal_state);

        for(auto it : neighbours) {
            if(find(tabuList.begin(), tabuList.end(), it.to_string()) == tabuList.end() && it.cost < curr_best.cost) {
                curr_best = it;
            }
        }

        if(curr_best.cost < best_state.cost) best_state = curr_best;
        curr_state = curr_best;
        tabuList.push_back(curr_best.to_string());
        if(tabuList.size() > 4) tabuList.erase(tabuList.begin());
    }

    cout<<"Best state possible -->" << endl;
    best_state.print();
	return 0;
}

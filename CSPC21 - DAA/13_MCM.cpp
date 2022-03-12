#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class MCM {
	int count = 1;
	int dp[100][100];
	int s[20][20], i, j;
	int n, *dimensions;

	void printParens() {
		if (i == j) {
			cout << "A" << count++ << " ";
			return;
		}
		cout << "(";
		printParens();
		s[i][j]++;
		printParens();
		cout << ")";
	}

	friend int MCM_memoized(int *dimensions, int i, int j) {
		if (i == j)
			return 0;

		if (dp[i][j] != -1)
			return dp[i][j];

		dp[i][j] = INT_MAX;
		for (int k = i; k < j; k++)
			dp[i][j] = min(
				dp[i][j],
				MCM_memoized(dimensions, i, k) + MCM_memoized(dimensions, k + 1, j) + dimensions[i - 1] * dimensions[k] * dimensions[j]
			);
		return dp[i][j];
	}

	int call_MCM_memo() {
		int i = 1, j = n - 1;
		return MCM_memoized(dimensions, i, j);
	}

public:
	void MCM_algo() {
		int m[n][n];
		int s[20][20];

		for (int i = 1; i < n; i++)
			m[i][i] = 0;

		for (int d = 1; d < n - 1; d++)
			for (int i = 1; i < n - d; i++) {
				int j = i + d;
				int min = INT_MAX;
				for (int k = i; k <= j - 1; k++) {
					int q = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
					if (q < min) {
						min = q;
						s[i][j] = k;
					}
				}
				m[i][j] = min;
			}

	cout << "The minimum number of multiplications using tabulation: " << m[1][n - 1] << '\n';
	cout << "The optimal order is:";
	i = 1; j = n - 1;
	printParens();
	}

	MCM(int size, int *dim) {
		n = size;
		dimensions = dim;
	}
};

int main() {
    int n;
    cout << "Enter the number of matrices --> ";
    cin >> n;

    int dimensions[n + 1];
    int row, col;
    char comma;
    cout << "Enter the order of matrices(row col , ): ";
    for (int i = 0; i < n; i++) {
        cin >> row >> col >> comma;
        dimensions[i] = row;
        if (i == n - 1)
            dimensions[i + 1] = col;
    }
    MCM mcm(n + 1, dimensions);
	mcm.MCM_algo();
}
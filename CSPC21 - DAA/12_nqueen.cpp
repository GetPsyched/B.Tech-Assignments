#include <iostream>
#include <cmath>
using namespace std;

class NQueen {
    int k, n;
    int *x;

    bool place() {
        bool in_same_column, in_same_diagonal;
        for(int i=0; i < k; i++) {
            in_same_column = x[i] == x[k];
            in_same_diagonal = abs(x[i] - x[k]) == abs(i - k);

            if(in_same_column || in_same_diagonal)
                return false;
        }
        return true;
    }

public:
    void NQueens() {
        while(k >= 0) {
            x[k]++;
            while(x[k] < n && !place())
                x[k]++;

            if(x[k] < n)
                if(k == n - 1)
                    print();
                else
                    x[++k] = -1;
            else
                k--;
        }
    }

    void print() {
        for(int i=0; i < n; i++)
            cout << x[i] << " ";
        cout << endl;
    }

    NQueen(int size) {
        n = size;
        x = new int[n];
        x[0] = -1; k = 1;
    }
};

int main() {
    int n;
    cout << "Enter the size of the chessboard (n × n) --> ";
    cin >> n;
    NQueen nq(n);
    nq.NQueens();
}
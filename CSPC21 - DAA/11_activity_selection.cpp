#include <iostream>
using namespace std;

class activity {
public:
    int begin, end;
};

class Activities {

public:
    void Swap(activity &a, activity &b) {
        activity temp = a;
        a = b;
        b = temp;
    }

    void sort_(activity a[], int n) {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (a[j].end > a[j + 1].end)
                    Swap(a[j], a[j + 1]);
    }

    void display(activity res[], int size) {
        cout << "Number of activities selected --> " << size << endl;

        cout << "Activities selected:" << endl;
        for (int i = 0; i < size; i++)
            cout << res[i].begin << " " << res[i].end << endl;
    }

    void ActivitySelection(activity a[], int n) {
        sort_(a, n);
        activity res[n];
        int size = 0;

        res[0] = a[0];
        size++;
        int first = 0;
        for (int second = 1; second < n; second++)
            if (a[second].begin >= a[first].end) {
                res[size++] = a[second];
                first = second;
            }

        display(res, size);
    }

    void util_fun(activity a[], int n, activity res[], int first, int &size) {
        for (int second = first + 1; second < n; second++)
            if (a[second].begin >= a[first].end) {
                res[size++] = a[second];
                util_fun(a, n, res, second, size);
                return;
            }
    }

    void run(activity a[], int n) {
        sort_(a, n);
        activity res[n];
        int size = 0;
        res[0] = a[0];
        size++;

        util_fun(a, n, res, 0, size);
        display(res, size);
    }
};

int main() {
    int n;
    cout << "Number of activities --> "; cin >> n;

    activity a[n];

    cout << "Begin and end times for each activity:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Activity " << i << " --> "; cin >> a[i].begin >> a[i].end;
    }

    Activities obj;
    obj.run(a, n);

    return 0;
}

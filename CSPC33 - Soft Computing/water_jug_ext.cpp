#include <bits/stdc++.h>
using namespace std;

int x, y;
void Display(int a, int b);

int min(int w, int z)
{
    if (w < z)
        return w;
    else
        return z;
}

// Display in tabular formate
void Display(int a, int b)
{
    cout << setw(12) << a << setw(12) << b << endl;
}

// To set the sequenced output
void sequence(int n)
{
    int xq = 0, yq = 0;
    int t;
    cout << setw(15) << "FIRST JUG" << setw(15) << "SECOND JUG" << endl;

    // Using while loop to check the value upto when we are getting the required water
    while (xq != n && yq != n)
    {
        if (xq == 0)
        {
            xq = x;
            Display(xq, yq);
        }
        else if (yq == y)
        {
            yq = 0;
            Display(xq, yq);
        }
        else
        {
            t = min(y - yq, xq);
            yq = yq + t;
            xq = xq - t;
            Display(xq, yq);
        }
    }
}

// Driver code
int main()
{
    int choice = 1;
    while (choice != 0)
    {
        int n;
        cout << "Enter the liters of water required out of the two jugs: ";
        cin >> n;
        cout << "Enter the capacity of the first jug: ";
        cin >> x;
        cout << "Enter the capacity of the second jug: ";
        cin >> y;
        if (n < x || n < y)
        {
            if (n % (__gcd(x, y)) == 0)
                sequence(n);
            else
                cout << "This is not possible....\n";
        }
        else
            cout << "This is not possible....\n";
        cout << "\nDo you Want to play again ?  press 1 for repeat and press 0 for exit: ";
        cin >> choice;
    }
}
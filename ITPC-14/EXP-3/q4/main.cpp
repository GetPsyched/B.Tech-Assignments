#include <iostream>
using namespace std;

class Employee {
    int id, sales, bonus;
    public:
        Employee(int id, int sales, int bonus){this->id = id; this->sales = sales; this->bonus = bonus;};
        Employee(void) {this->id = 0; this->sales = 0; this->bonus = 0;};
        void setAll(int id, int sales, int bonus) {this->id = id; this->sales = sales; this->bonus = bonus;};
        int getSales(void) { return this->sales; };
        int getBonus(void) { return this->bonus; };
        void setBonus(int b) { this->bonus = b; };
};

int main(void) {
    
    Employee arr[4];
    for (int i = 0; i < 4; i++) {
        int id, sales, bonus;
        cin >> id >> sales >> bonus;
        arr[i].setAll(id, sales, bonus);
    }

    float total = 0;
    for (int i = 0; i < 4; i++) {
        total += 0.125 * arr[i].getSales();
        total += arr[i].getBonus();
    }

    cout << "Federal withholding is " << (float) total / 4 << endl;
    cout << "State withholding is " << (float) total / 10 << endl;
    cout << "Retirement plan is " << (float) total * 0.08 << endl;

    return 0;

}

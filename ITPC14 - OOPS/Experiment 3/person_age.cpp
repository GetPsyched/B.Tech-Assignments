#include <iostream>
using namespace std;

void enterDate(int *m, int *d, int *y) {
    
    cout << "Enter date in MM DD YYYY format" << endl;
    cin >> *m >> *d >> *y;

}

int age(int doby, int cy) {

    return cy - doby;

}

int main(void) {

    int dobm, dobd, doby;
    int cm, cd, cy;

    enterDate(&dobm, &dobd, &doby);
    enterDate(&cm, &cd, &cy);

    cout << "Current age is " << age(doby, cy) << endl;

    return 0;

}

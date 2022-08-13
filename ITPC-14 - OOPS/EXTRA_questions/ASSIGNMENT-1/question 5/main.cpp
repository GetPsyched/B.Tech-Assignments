#include <iostream>

using namespace std;

static int roll = 1;

class student {

    private:
        int fee;
        char *name;
    public:
        int rollno;
        void init(int fee, char name[]);
        void print(void);

};

void student::init(int fee, char name[]) {

    student::rollno = roll;
    student::fee = fee;
    student::name = name;

}

void student::print(void) {

    cout << "Student name: " << student::name << endl;
    cout << "Student roll no: " << student::rollno << endl;
    cout << "Student fees: " << student::fee << endl;

}

void addStudent(int *l, student students[], int fee, char name[]) {
    
    students[*l].init(fee, name);
    roll++;
    *l = *l + 1;

}

void removeStudent(int *l, student students[], int rollno) {
    
    int p = -1;
    for (int i = 0; i < *l; i++) {
        if (students[i].rollno == rollno) {
            p = i;
            break;
        }
    }
    if (p != -1) {
        for (int i = p; i < *l - 1; i++) {
            students[i] = students[i+1];
        }
    }
    *l = *l - 1;

}

int main(void) {

    int max = 20;
    student students[max];

    int l = 0;
        
    char *x = "hello";
    char *y = "world";
    
    cout << "Adding student" << endl;
    addStudent(&l, students, 100, x);
    students[0].print();
    cout << "removing student" << endl;
    removeStudent(&l, students, 1);
    cout << "Adding student again.." << endl;
    addStudent(&l, students, 200, x);
    students[0].print();
    cout << "Adding another student" << endl;
    addStudent(&l, students, 200, y);
    students[1].print();
    cout << "Adding another student" << endl;
    addStudent(&l, students, 960, y);
    students[2].print();
    cout << "removing student" << endl;
    removeStudent(&l, students, 3);
}


#include <iostream>
#include<dirent.h>
#include<cstring>

using namespace std;

static int roll = 1;

class student {

    private:
        int fee;
        char *name;
    public:
        int rollno;
        void init(int fee, char name[]);
        void print();

};

void student::init(int fee, char name[]) {

    student::rollno = roll;
    student::fee = fee;
    student::name = name;

}

void student::print() {

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

int main() {
    
    

    
}

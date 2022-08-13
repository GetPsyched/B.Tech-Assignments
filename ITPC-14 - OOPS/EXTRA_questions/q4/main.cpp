#include <iostream>
#include <fstream>
using namespace std;

int swapNibble(int num) {

    int firstpart = (num & 0b1111) << 4;
    int secondpart = (num & 0b11110000) >> 4;
    int newnum = firstpart + secondpart;
    return newnum;

}

void encryptFile(char *data, char *filename) {

    ofstream f(filename, ios::binary);

    for (int i = 0; data[i] != '\0'; i++) {
        int x = (int) data[i];
        x = swapNibble(x);
        char y = (char) x;
        f.write(&y, sizeof(y));
    }
    f.close();

}

void decryptFile(char *filename) {

    ifstream tempfile(filename, ios::binary | ios::ate);
    int size = tempfile.tellg();
    tempfile.close();

    ifstream f(filename, ios::binary);
    char encdata[size];
    f.read(encdata, size * sizeof(char));
    f.close();
    
    for (int i = 0; i < size; i++) {
        int x = (int) encdata[i];
        x = swapNibble(x);
        char y = (char) x;
        cout << y;

    }
    cout << endl;

}

int main(int argc, char *argv[]) {

    if (argc == 1) {
        cout << "Insufficient CLI args given" << endl;
        return 1;
    } else {
        encryptFile(argv[1], argv[2]);
        decryptFile(argv[2]);
    }

    return 0;

}

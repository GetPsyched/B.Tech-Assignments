#include <iostream>
#include <dirent.h>
#include <cstring>
using namespace std;

struct node {

    char *name;
    struct node *next;

};

class LinkedList {

    struct node *head;

    public:
        LinkedList(void) {
            head = NULL;
        }
        void addNode(char *name) {
            struct node *n = new node;
            n->name = name;
            n->next = head;
            head = n;
        }
        void show(void) {
            if (head == NULL) {
                cout << "No files found!" << endl;
                return;
            }
            struct node *temp = head;
            while (temp != NULL) {
                cout << temp->name << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        ~LinkedList(void) {
            while (head != NULL) {
                struct node *temp = head;
                head = head->next;
                delete temp;
            }
        }

};


int main(void) {

    DIR *d;
    struct dirent *dir;
    d = opendir(".");

    LinkedList list;

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            long len = strlen(dir->d_name);
            char format[4];
            for (long i = len-4; i < len; i++) {
                format[len-i-1] = dir->d_name[i];
            }
            if (!(strcmp("txt.", format))) {
                list.addNode(dir->d_name);
            }
        }
        closedir(d);
    }
    
    list.show();
    
    return 0;

}

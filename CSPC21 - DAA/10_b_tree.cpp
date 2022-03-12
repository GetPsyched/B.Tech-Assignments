#include <iostream>
using namespace std;

int t = 10;

class Node {
public:
    int n, *keys;
    Node **c;
    Node(int);
};

class BTree {
public:
    Node *root;
    int t;
    BTree() { root = NULL; }
    void insert();
    void search(int);
    void levelOrder();
};

Node::Node(int n) {
    keys = new int[t - 1];
    c = new Node *[t];
    for (int i = 0; i < t; i++)
    c[i] = NULL;
    this->n = n;
}

class node {
public:
    Node *root;
    int i;
};

class queue {
public:
    int size, front, rear;
    node *arr;
    queue();
    bool empty();
    void enqueue(node);
    node dequeue();
};

queue::queue() {
    size = 100;
    front = rear = -1;
    arr = new node[100];
}

bool queue::empty() {
    if (front == rear)
    return 1;
    return 0;
}

void queue::enqueue(node key) {
    rear++;
    arr[rear] = key;
}

node queue::dequeue() {
    front++;
    return arr[front];
}

void BTree::insert() {
    int n;
    cout << "Enter number of keys in root --> "; cin >> n;

    root = new Node(n);
    cout << "Enter the keys in root --> ";
    queue q;
    for (int i = 0; i < n; i++) {
        cin >> root->keys[i];
        node newnode;
        newnode.root = root;
        newnode.i = i;
        q.enqueue(newnode);
    }

    while (!q.empty()) {
        node temp = q.dequeue();
        if (temp.i == 0) {
            cout << "Enter number of values less than " << (temp.root)->keys[0]
            << " --> "; cin >> n;
        } else {
            cout << "Enter number of values between " << (temp.root)->keys[temp.i - 1]
            << " & " << (temp.root)->keys[temp.i] << " --> "; cin >> n;
        }
        if (n) {
            Node *bnode = new Node(n);
            (temp.root)->c[temp.i] = bnode;
            cout << "Enter the values --> ";
            for (int j = 0; j < n; j++) {
                cin >> bnode->keys[j];
                node newnode;
                newnode.root = bnode;
                newnode.i = j;
                q.enqueue(newnode);
            }
        }

        if ((temp.root)->n == temp.i + 1) {
            cout << "Enter the values greater than " << (temp.root)->keys[temp.i]
            << " --> ";
            cin >> n;
            if (n) {
                Node *bnode = new Node(n);
                (temp.root)->c[temp.i + 1] = bnode;
                cout << "Enter the values --> ";
                for (int j = 0; j < n; j++) {
                    cin >> bnode->keys[j];
                    node newnode;
                    newnode.root = bnode;
                    newnode.i = j;
                    q.enqueue(newnode);
                }
            }
        }
    }
}

void searchUtil(Node *root, int k, int &lvl, int &idx, int m) {
    int i = 0;

    if (!root)
        return;

    while (i < root->n && root->keys[i] < k)
        i++;

    if (i < root->n and root->keys[i] == k) {
        lvl = m;
        idx = i + 1;
        return;
    }

    searchUtil(root->c[i], k, lvl, idx, m + 1);
}

void BTree::search(int k) {
    int lvl = -1, idx = -1;
    searchUtil(root, k, lvl, idx, 1);

    if (lvl == -1)
    cout << "Element not found!" << endl;
    else {
        cout << "Element found at level --> " << lvl << endl;
        cout << "Index --> " << idx << endl;
    }
}

void BTree::levelOrder() {
    Node *temp = root;
    queue q;
    node newnode;
    newnode.root = root;
    newnode.i = 0;
    q.enqueue(newnode);

    int num = 1;

    while (!q.empty()) {
        int num1 = q.rear - q.front;
        while (num1--) {
            num = 0;
            node temp = q.dequeue();
            int i;
            for (i = 0; i < (temp.root)->n; i++) {
                cout << (temp.root)->keys[i] << " ";
                if ((temp.root)->c[i]) {
                    node newnode;
                    newnode.root = (temp.root)->c[i];
                    newnode.i = 0;
                    q.enqueue(newnode);
                    num++;
                }
            }
            if ((temp.root)->c[i]) {
                node newnode;
                newnode.root = (temp.root)->c[i];
                newnode.i = 0;
                q.enqueue(newnode);
                num++;
            }
            cout << "   ";
        }
        cout << endl;
    }
}

int main() {
    BTree b;
    b.insert();

    cout << endl << "Level order traversal:" << endl;
    b.levelOrder();

    int x;
    cout << "Enter the value to be searched in B-Tree --> "; cin >> x;
    cout << endl;
    b.search(x);

    return 0;
}

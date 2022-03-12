#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int d) {
        data = d;
        left = NULL;
        right = NULL;
    }

    Node *insert (Node* root, int data) {
        if(root == NULL)
            return new Node(data);
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert (root->left, data);
                root->left = cur;
            }
            else {
                cur = insert (root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    Node *search (Node* root, int key) {
        if(root == NULL) return root;
        else if (root->data == key) return root;
        else if (root->data < key) return search(root->right,key);

        return search(root->left,key);
    }

    Node *FindMin (Node* root) {
        if (root == NULL) return NULL;
        while(root->left != NULL)
            root = root->left;
        return root;
    }

    Node *FindMax (Node *root) {
        if (root == NULL)
            return NULL;
        while(root->right != NULL)
            root = root->right;
        return root;
    }

    Node *successor(Node* root, int data) {
        Node* current = search(root,data);
        if (current == NULL) return NULL;
        if (current->right != NULL)
            return FindMin(current->right);
        else {
            Node* successor = NULL;
            Node* ancestor = root;
            while(ancestor != current)
                if(current->data < ancestor->data) {
                    successor = ancestor;
                    ancestor = ancestor->left;
                }
                else
                    ancestor = ancestor->right;
            return successor;
        }
    }

    Node *predecessor(Node *root, int data) {
        Node *current = search(root,data);
        if (current == NULL) return NULL;
        if (current->left != NULL) return FindMax(current->left);
        else {
            Node* ancestor = root;
            Node* predecessor = NULL;
            while(ancestor != current)
                if(current->data > ancestor->data) {
                    predecessor = ancestor;
                    ancestor = ancestor->right;
                }
                else
                    ancestor = ancestor->left;
            return predecessor;
        }
    }

    Node *deleteLeaf(Node *root) {
    	delete root;
    	return NULL;
    }

    Node *deleteOne(Node *root) {
    	Node *temp = root;
    	if (root->left == NULL) {
    		root->right->data = root->data;
    		temp = root->right;
    	}
    	else if (root->right == NULL) {
    		root->left->data = root->data;
    		temp = root->left;
    	}
    	delete root;
    	return temp;
    }

    int deleteTwo(Node *root) {
    	Node *succ = FindMin(root->right);
    	root->data = succ->data;
    	return succ->data;
    }

    Node *Delete(Node *root, int data) {
    	if (root == NULL)
    		return NULL;
    	if (root->data < data)
    		root->right = Delete(root->right, data);
    	else if (root->data > data)
    		root->left = Delete(root->left, data);
    	else
    	{
    		if (root->left == NULL && root->right == NULL)
    			return deleteLeaf(root);
    		else if (root->left == NULL || root->right == NULL)
    			return deleteOne(root);
    		else {
    			int val = deleteTwo(root);
    			root->right = Delete(root->right, val);
    			return root;
    		}
    	}
    	return root;
    }

    void inorder (Node* root) {
        if(root == NULL) return;
        inorder (root->left);
        cout << root->data << " ";
        inorder (root->right);
    }

    void preorder (Node* root) {
        if(root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder (Node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    Node Tree(0);
    Node* root = NULL;
    int t;
    cout << "Enter the number of nodes in a new tree --> ";
    cin >> t;
    int data;
    while (t--) {
        cout << "Enter data --> ";
        cin >> data;
        root = Tree.insert(root,data);
    }
    int choice;
    Node *find_element = NULL;
    do {
        cout << endl << "1. Insert";
        cout << endl << "2. Search";
        cout << endl << "3. Predecessor";
        cout << endl << "4. Successor";
        cout << endl << "5. Traversal";
        cout << endl << "6. Delete";
        cout << endl << "7. Exit\n";
        cout << endl << "Enter your choice --> ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter data --> ";
                    cin >> data;
                    Tree.insert(root,data);
                    break;
            case 2: cout << "Enter the data to find --> ";
                    cin >> data;
                    find_element = Tree.search(root,data);
                    if (find_element == NULL)
                        cout << "Element not found" << '\n';
                    else cout << "Element found" << '\n';
                    break;
            case 3: cout << "Enter the data whose predecessor is needed --> ";
                    cin >> data;
                    find_element = Tree.predecessor(root,data);
                    if (find_element == NULL)
                        cout << "Element not found" << '\n';
                    else cout << "Predecessor is --> " << find_element->data << '\n';
                    break;
            case 4: cout << "Enter the data whose successor is needed --> ";
                    cin >> data;
                    find_element = Tree.successor(root,data);
                    if (find_element == NULL)
                        cout << "Element not found" << '\n';
                    else cout << "Successor is --> " << find_element->data << '\n';
                    break;
            case 5: cout << "1.Inorder\t2. Preorder \t3. Post order\n";
                    cout << "Enter your choice --> ";
                    int new_choice;
                    cin >> new_choice;
                    switch (new_choice) {
                        case 1: cout << "In-order traversal --> ";
                                Tree.inorder(root);
                                break;
                        case 2: cout << "Pre-order traversal --> ";
                                Tree.preorder(root);
                                break;
                        case 3: cout << "Post-order traversal --> ";
                                Tree.postorder(root);
                                break;
                    }
                    break;
            case 6: cout << "Enter the data to delete --> "; cin >> data;
                    find_element = Tree.Delete(root, data);
                    if (find_element == NULL)
                        cout << "Element not found" << '\n';
                    else cout << "Element deleted" << '\n';
                    break;
            case 7: return 0;
            default: cout << endl << "Invalid choice!\n";
        }
    } while(choice != 7);
    return 0;
}

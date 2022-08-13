#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class node{
    public:
    int roll;
    char name[30];
    node*next;
    
    node(int r, char* s){
        roll=r;
        strcpy(name,s);
        next=NULL;
    }
};

void insert(node*&head, int r, char *s){
    if (head==NULL)
    {
        head=new node(r,s);
        return;
    }

    node*n=new node(r,s);
    node*temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=n;
    return;
}

void deletenode(node*&head, int r){
    if (head==NULL)
    {
        return;
    }
    node*temp=head;
    while (temp->next->roll!=r)
    {
        temp=temp->next;
    }

    node*n=temp->next;
    temp->next=n->next;
    delete n;
}

void update(node*&head, int r){
    if (head==NULL)
    {
        return;
    }

    node*temp=head;
    while (temp->roll!=r)
    {
        temp=temp->next;
    }

    char n[20];
    cout<<"Enter the new name: \n";
    cin>>n;

    strcpy(temp->name,n);
    return;
}

void add_data(node*head){
    // int r;
    // char n[20];
    // cout<<"Enter roll number and name: \n";
    // cin>>r>>n;
    // insert(head,r,n);

    fstream file;
    file.open("check.txt", ios::in|ios::out);

    node*temp=head;

    while (temp!=NULL)
    {
        file<<"Roll:"<<temp->roll<<",name:"<<temp->name<<" ";
        temp=temp->next;
    }
    int l=file.tellp();
    
    char str[l];
    file.seekg(0,ios::beg);
    while (file)
    {
        file>>str;
        cout<<str<<endl;
    }

    file.close();
}

void delete_data(node*head){
    fstream file;
    file.open("check.txt", ios::in|ios::out);
    
    int r;
    cout<<"Enter roll number to be deleted: "<<endl;
    cin>>r;
    deletenode(head,r);
    node*temp=head;

    while (temp!=NULL)
    {
        file<<"Roll:"<<temp->roll<<",name:"<<temp->name<<" ";
        temp=temp->next;
    }

    file.close();
}

void update_data(node*head){
    fstream file;
    file.open("check.txt", ios::in|ios::out);
    
    int r;
    cout<<"Enter roll number to be updated: "<<endl;
    cin>>r;
    update(head,r);
    node*temp=head;

    while (temp!=NULL)
    {
        file<<"Roll:"<<temp->roll<<",name:"<<temp->name<<" ";
        temp=temp->next;
    }

    file.close();
}

void print(node*head){
    while (head!=NULL)
    {
        cout<<head->roll<<" "<<head->name<<"->";
        head=head->next;
    }
}

int main(){
    node*head=NULL;

    int r;
    char n[20];
    cin>>r>>n;
    insert(head,r,n);
    
    add_data(head);

    //delete_data(head);
    print(head);

return 0;
}

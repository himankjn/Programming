#include<iostream>
#include<stacK>
using namespace std;

typedef struct node {
    int data;
    struct node* llink;
    struct node* rlink;
    node(int val){
        data=val;
        llink=NULL;
        rlink=NULL;
    }
}Node;

void inorder_traversal(Node* root){
    Node* temp=root;
    stack<Node*> s;

    while(!s.empty() and temp){
        while(temp){
            s.push(temp);
            temp=temp->llink;
        }
        temp=s.top(); 
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->rlink;
    }  
}

void inorder(Node* root){
    stack<Node*> s;
    if(root==NULL) return;
    s.push(root);
    Node* temp=root;

    while(!s.empty()){
        Node* temp=s.top();
        if(temp->llink){
            s.push(temp->llink);
            temp=temp->llink;
        }
        else{
            s.pop();
            cout<<temp->data<<" ";
            if(temp->rlink){
                s.push(temp->rlink);
            }
        }
    }
}
int main(){
    Node *root=new Node(1);
    root->llink=new Node(2);
    root->rlink=new Node(3);
    root->llink->llink=new Node(4);
    root->llink->rlink=new Node(5);
    root->llink->rlink->llink=new Node(6);
    root->llink->rlink->rlink=new Node(7);
    inorder_traversal(root);

    return 0;
}
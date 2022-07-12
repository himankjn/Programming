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
    stack<Node*>s;
    while(!s.empty() or root){
        while(root){
            s.push(root);
            root=root->llink;
        }

        root=s.top();
        s.pop();
        cout<<root->data;
        root=root->rlink;
    }
}
int main(){
    Node *root=new Node(1);
    root->llink=new Node(2);
    root->rlink=new Node(3);
    root->llink->llink=new Node(4);
    root->llink->rlink=new Node(5);
    root->rlink->llink=new Node(6);
    root->rlink->rlink=new Node(7);
    inorder_traversal(root);

    return 0;
}
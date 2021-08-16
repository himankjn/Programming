#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node{
    int data;
    struct node* llink;
    struct node* rlink;
}Node;


int max(int,int);
void inorder(Node* root);
void levelorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
Node* newNode(int);
int num_nodes(Node* root);
int num_leaves(Node* root);
int num_non_leaves(Node* root);
int full_nodes(Node* root);
int height(Node* root);
bool is_complete_binary(Node*);

int main(){
    
     Node *root = newNode(1); 
     root->llink = newNode(2); 
     root->rlink = newNode(3); 
     root->llink->llink = newNode(4); 
     root->llink->rlink = newNode(5); 
     printf("preorder:\n");
    preorder(root);
    printf("\ninorder:\n");
    inorder(root);
    printf("\npostorder:\n");
    postorder(root);
    printf("\nlevelorder:\n");
    levelorder(root);
    printf("\nnumber of nodes in tree: %d",num_nodes(root));
    printf("\nnumber of leaf nodes in tree: %d",num_leaves(root));
    printf("\nnumber of non leaf nodes in tree: %d",num_non_leaves(root));
    printf("\nnumber of full nodes in tree: %d",full_nodes(root));
    printf("\n height of tree: %d",height(root));
    printf("\ncomplete binary tree: ");
    printf("%s",is_complete_binary(root)?"true":"false");
    root->llink->rlink->llink=newNode(89);
    printf("\ncomplete binary tree: ");
    printf("%s",is_complete_binary(root)?"true":"false");
    return 0;


}

void printthislevel(Node* root,int level){
    if(!root)return;
    if(level==1){
        cout<<root->data<<" ";
    }
    else{
        printthislevel(root->llink,level-1);
        printthislevel(root->rlink,level-1);
    }


}
void levelorder(Node* root){
    for(int level=1;level<= height(root)+1;level++){
        printthislevel(root,level);
    }
}
void inorder(Node* root){
    if(root){
        inorder(root->llink);
        printf("%d",root->data);
        inorder(root->rlink);
    }
}

void preorder(Node* root){
    if(root){
        printf("%d",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d",root->data);
    }
}

int num_nodes(Node* root){
    if(root){
        return (1+num_nodes(root->llink)+num_nodes(root->rlink));
    }
    return 0;
}

int num_leaves(Node* root){
    if(!root) return 0;
    if(!root->llink && !root->rlink){
        return 1;
    }
    else return (num_leaves(root->rlink)+num_leaves(root->llink));
    return 0;
}

int num_non_leaves(Node* root){
    if(!root) return 0;
    if(!root->llink && !root->rlink){
        return 0;
    }   
    else return (1+num_non_leaves(root->rlink)+num_non_leaves(root->llink));// return max height out of left and right subtree  
} 

int height(Node* root){
    if(!root) return -1; //root is null return 0
    if(!root->llink && !root->rlink) return 0; // if node is leaf return 0
    else return (1+max(height(root->llink),height(root->rlink)));
}

int full_nodes(Node* root){
    if(!root) return 0;
    if(root->llink && root->rlink){
        return (1+full_nodes(root->rlink)+full_nodes(root->llink));
    }
    else return 0;
}

Node* newNode(int data) 
{ 
     Node* node = (Node*)malloc(sizeof(Node)); 
     node->data = data; 
     node->llink = NULL; 
     node->rlink = NULL; 
  
     return(node); 
} 

int max(int a,int b){
    return (a>b?a:b);
}

bool is_complete_binary(Node* root){
    if(!root){//special condition : if tree is empty.
        return true;
    }
    if(!root->rlink && !root->llink){ //if 0 children
        return true;
    }
    if(root->llink && root->rlink){ // 2 childeren
        bool left,right;
        left=is_complete_binary(root->llink);
        right=is_complete_binary(root->rlink);
        return (left&&right);
    }
    //1 child
    return false;
}
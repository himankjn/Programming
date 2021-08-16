#include<stdio.h>
#include<stdlib.h>
//ordered insertion & deletion
//balanced bst search complexity log(n)

typedef struct node {
    int data;
    struct node* llink;
    struct node* rlink;
}Node;

Node* new_node(int);
Node* insert(Node*,int);
void inorder(Node*);
Node* del(Node*,int key);
bool search(Node*,int key);
Node* inorder_succ(Node*);

int main(){
    int key,n;
    Node *temp,*root=NULL;
    while(true){
        printf("enter choice:\n 1:insert\t 2: delete\t 3:search\t 4:inorder print\t\n");
        scanf("%d",&n);
    switch(n){
        case 1: printf("enter element to be inserted :\n");
                scanf("%d",&key);
                root=insert(root,key);
                break;
        case 2: printf("enter element to be deleted:\n");
                scanf("%d",&key);
                root=del(root,key);
                break;
                
        case 3: printf("enter element to be searched:\n");
                scanf("%d",&key);
                search(root,key);
                break;
                
        case 4: inorder(root);
                break;
        default: printf("Invalid choice:\n");
    }
    }
    return 0;
}


Node* new_node(int n){
    Node* temp=(Node*)malloc(sizeof(Node));
    if(!temp){
        printf("error!");
        exit(0);
    }
    temp->data=n;
    temp->llink=NULL;
    temp->rlink=NULL;
    return temp;
}


Node* insert(Node* root,int key){

    if(root==NULL){
        return new_node(key);
    }
    if(key<root->data)  {
        root->llink=insert(root->llink,key);
    }
    else{
        root->rlink=insert(root->rlink,key);
    }
    return root;
}

bool search(Node* root,int key){
    if(root==NULL) return false;

    if(root->data==key) return true;

    else if(key<root->data){
        return search(root->llink,key);
    }
    else{
        return search(root->rlink,key);
    }
    
}

Node* del(node* root,int key){
     if(!root)
     return NULL;   

     if(key<root->data){
         root->llink=del(root->llink,key);
     }
     else if(key>root->data){
         root->rlink=del(root->rlink,key);
     }

    //this node needs to be deleted
     else{
         //node with one or no child
        if(root->llink==NULL){
            Node* temp=root->rlink;
            free(root);
            return temp;
        }
        else if(root->rlink==NULL){
            Node* temp=root->llink;
            free(root);
            return temp;
        }

        //node has two children. find inorder succesor copy its value to root and delete inorder successor;
        Node* temp= inorder_succ(root);
        root->data=temp->data;
        root->rlink=del(root->rlink,temp->data);
     }
     return root;
}

void inorder(Node* root){
    if(root){
        inorder(root->llink);
        printf("%d\t",root->data);
        inorder(root->rlink);
    }
}

//finds the minValue key in right subtree (inorder successor)
Node* inorder_succ(Node* root){
    root=root->rlink;
    while(root->llink){
        root=root->llink;
    }
    return root;
}

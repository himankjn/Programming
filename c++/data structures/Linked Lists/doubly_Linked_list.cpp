#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *llink;
struct node *rlink;
}Node;


Node* push_back(Node *);
Node* push_front(Node*);
Node* pop_front(Node*);
Node* pop_back(Node*);
Node* insert_after(Node *);
/*
Node* reverse(Node*);
*/
void display(Node*);

Node* new_node(){
    Node* temp=(Node*)malloc(sizeof(Node));
    int n;
    printf("Enter n:\n");
    scanf("%d",&n);
    temp->data=n;
    temp->llink=NULL;
    temp->rlink=NULL;
    return temp;
}
int main(){
    Node* head=NULL;
    int n;
    while(true){
    printf("enter a choice: \n 1. display\t2.push_back\t3.push_front\t4. pop_back\t5.pop_front\n6.insert after some element\n");
    scanf("%d",&n);
    switch(n){
        case 1: display(head);
        break;
        case 2:head=push_back(head);
        break;
        case 3:head=push_front(head);
        break;
        case 4:head=pop_back(head);
        break;
        case 5:head=pop_front(head);
        break;
        
        case 6:head=insert_after(head);
        break;
        /*
        case 7:head=reverse(head);
        break;
        */
        default: exit(0);
    }

    }
    return 0;
}

Node* push_back(Node* head){
    Node* temp=new_node();
    if(head==NULL){
        return temp;
    }
    Node* cur=head;
    while(cur->rlink)
        cur=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;
    return head;
}

Node* push_front(Node* head){
    Node* temp=new_node();
    
    if(head==NULL){
        return temp;
    }
    temp->rlink=head;
    head->llink=temp;
    return temp;

}
void display(Node* head){
    if(head==NULL){
        printf("Empty Linked List\n");
        return;
    }

    Node* temp=head;
    while(temp){
        printf("%d\t",temp->data);
        temp=temp->rlink;
}
}

Node* pop_front(Node* head){
    if(head==NULL){
        printf("Can't pop from empty LL\n");
        return NULL;
    }
    
    Node* temp=head;
    printf("Element popped is %d\n",temp->data);
    head=head->rlink;
    free(temp);
    return head;
}

Node* pop_back(Node* head){
    if(head==NULL){
        printf("Can't pop from empty LL\n");
        return NULL;
    }

    Node* temp=head;
    while(temp->rlink->rlink){
        temp=temp->rlink;
    }
    free(temp->rlink);
    temp->rlink=NULL;
    return head;
}

Node* insert_after(Node* head){
    int n;
    printf("enter element after which new element needs to be inserted\n");
    scanf("%d",&n);
    Node* temp=new_node();
    Node* next;
    Node* cur=head;
    while(cur->data!=n)
        cur=cur->rlink;
    next=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;
    temp->rlink=next;
    next->llink=temp;
    return head;
}
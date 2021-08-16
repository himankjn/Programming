#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}Node;

Node* push_back(Node *);
Node* push_front(Node*);
Node* pop_front(Node*);
Node* pop_back(Node*);
Node* move_last_to_front(Node *);
Node* reverse(Node*);
void display(Node*);

int main(){
    Node* head=NULL;
    int n;
    while(true){
    printf("enter a choice: \n 1. display\t2.push_back\t3.push_front\t4. pop_back\t5.pop_front\n6.move last node to front\t7.rever LL\n");
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
        case 6:head=move_last_to_front(head);
        break;
        case 7:head=reverse(head);
        break;
        default: exit(0);
    }

    }
    return 0;
}


Node* push_back(Node *head){
    Node* cur = (Node*) malloc(sizeof(Node));
    int n;
    printf("Enter element to insert at back: \n");
    scanf("%d",&n);
    cur->data=n;
    cur->link=NULL;
    
    if(head==NULL){
        return cur;
    }
    Node* temp;
    temp=head;
    while(temp->link)
        temp=temp->link;
    temp->link=cur;
    return head;
}

Node* push_front(Node* head){
    Node* cur = (Node*) malloc(sizeof(Node));
    int n;
    printf("Enter element to insert at back: \n");
    scanf("%d",&n);
    cur->data=n;
    cur->link=NULL;
    
    if(head==NULL){
        return cur;
    }
    cur->link=head;
    return cur;
}


void display(Node* head){
if(head==NULL){
    printf("Empty Linked list \n");
    return;
}
Node* cur;
cur=head;
printf("elements in Linked list: \n");
while(cur){
    printf("%d\t",cur->data);
    cur=cur->link;
}
printf("\n");
}
Node* pop_back(Node* head){
    if(!head){
        printf("Cannot pop from empty Linked list\n");
        return NULL;
    }
    if(!head->link){
        printf("Popped %d",head->data);
        free(head);
        return NULL;
    }
    Node* temp=head;
    while(temp->link->link){
        temp=temp->link;
    }
    printf("element popped from back is %d\n",temp->link->data);
        free(temp->link);
        temp->link=NULL;
    return head;

}
Node* pop_front(Node* head){
    if(!head){
        printf("Cannot pop from empty Linked list\n");
        return NULL;
    }
   
    Node* temp=head;
    head=head->link;
    printf("element popped from back is %d\n",temp->data);
    free(temp);
    return head;

}

Node* move_last_to_front(Node* head){
    Node* temp=head;
    Node* target;

    while(temp->link->link){
        temp=temp->link;
    }
    target=temp->link;
    temp->link=NULL;
    target->link=head;
    return target;

}

Node* reverse(Node* head){
Node *cur,*next,*prev;
prev=head;
cur=prev->link;
next=cur->link;
prev->link=NULL;
while(next){
    cur->link=prev;
    prev=cur;
    cur=next;
    next=next->link;
}
cur->link=prev;
return cur;
}
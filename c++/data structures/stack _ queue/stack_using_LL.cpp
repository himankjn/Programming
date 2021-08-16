#include<stdio.h>
#include<stdlib.h>
//head is the top;
//therefore constant time insertion and deletion
struct node{
    int data;
    struct node* link;
};
struct node* push(struct node*);
struct node* pop(struct node*);

int main(){
    int n;
    struct node* head=NULL;
    while(true){
        printf("enter an option:\n1.push \t 2.pop\n");
        scanf("%d",&n);
        switch(n){
            case 1: head=push(head);
            break;
            case 2: head=pop(head);
            break;
            default:printf("invalid");
        }
    }
    return 0;
}
struct node* push(struct node * head){
    int n;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("error!"); return head;
    }
    printf("enter ele to be pushed! \n");
    scanf("%d",&n);
    temp->data=n;
    temp->link=head;
    return temp;
    
}

struct node* pop(struct node* head){
    if(head==NULL){
        printf("stack underflow!");
        return NULL;
    }
    struct node* temp=head;
    head=head->link;
    printf("Element popped is: %d\n",temp->data);
    free(temp);
    return head;
}
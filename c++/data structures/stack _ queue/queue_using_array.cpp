#include<stdio.h>

//circular array using modulus addition.
#define max 5

int queue[max];
int front=0;
int rear=-1;


void enqueue();
void dequeue();
int main(){
    int n;
    while(true){
        printf("enter an option:\n1.enqueue \t 2.dequeue\n");
        scanf("%d",&n);
        switch(n){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            default:printf("invalid");
        }
    }
    return 0;
}

void enqueue(){
    //if queue is full
    if(((rear+1)==front)||(front==0 && rear==max-1)){
        printf("queue full!\n");
        return;
    }
    //initial condition (queue empty)
    else if(front==-1){
        front=0;
        rear=0;
    }
    //normal
    else{rear=(rear+1)%max;}
    int item;
    printf("enter item to be enqueued!\n");
    scanf("%d",&item);
    queue[rear]=item;
}
void dequeue(){
    //initial condition(empty queue)
    if(front==-1){
        printf("queue underflow!\n");
        return;
    }
    if(front==rear){
        //whenever only one element in queue reset it to -1,-1(initial condition)
        front=-1;
        rear=-1;
    }
    else front=(front+1)%max;
    printf("element dequeued is %d\n",queue[front]);
    front++;
}
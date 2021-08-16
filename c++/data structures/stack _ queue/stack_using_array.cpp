#include<stdio.h> 
#define max 10
int stack[max];
int top=-1;

void push();
void pop();

int main(){
    int n;
    while(true){
        printf("enter an option:\n1.push \t 2.pop\n");
        scanf("%d",&n);
        switch(n){
            case 1: push();
            break;
            case 2: pop();
            break;
            default:printf("invalid");
        }
    }
    return 0;
}
void push(){
    int n;
    if(top==max-1){
        printf("stack overflow!\n");
        return;
    }
    else
    
    printf("enter ele to be pushed:\n");
    scanf("%d",&n);
    stack[++top]=n;
}
void pop(){
    if(top==-1){
        printf("stack underflow! \n");
        return;
    }
    else
    printf("element popped is:%d\n",stack[top]);
    top--;

}
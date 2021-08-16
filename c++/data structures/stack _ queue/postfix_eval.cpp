#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct stack{
    int top;
    int* array;
}Stack;

int pop(Stack*);
int peek(Stack*);
bool isempty(Stack*);
void push(Stack* ,int);


int main(){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    if(!s){//malloc returns NULL
        printf("Error!");
        exit(0);
    }

    s->array=(int*)malloc(sizeof(int)*20);

    if(!(s->array)){
        printf("Error!");
        exit(0);
    }

    s->top=-1;
    char a,b,c;
    printf("enter postfix exression\n");
    while((c=getchar())!='\n'){ // if c is operand(digit) push on stack
        if(isdigit(c)){
            push(s,(int)(c-'0'));
        }
        else {
            b=pop(s);
            a=pop(s);
            switch(c){
                case '+': push(s,a+b);
                break;
                case '-': push(s,a-b);
                break;
                case '*': push(s,a*b);
                break;
                case '/': push(s,a/b);
                break;
                case '%': push(s,a%b);
                break;
            }
            
            
        }
    }
    printf("result=%d",pop(s));

    return 0;
}


bool isempty(Stack* s){
    return s->top==-1;
}

void push(Stack* s, int n){
    (s->top)++;
    s->array[s->top]=n;
}

int pop(Stack* s){
    if(!isempty(s)){
    return s->array[s->top--];
    }
    return '$';
}

int peek(Stack* s){
    return s->array[s->top];
}

#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int top=-1;
    char *array;

}Stack;

bool isempty(Stack*);
void push(Stack*,char);
char pop(Stack*);
char peek(Stack*);


void push(Stack* s,char c){
    (s->top)++;
    s->array[s->top]=c;
    
}
char pop(Stack* s){
    if(!isempty(s)){
    return s->array[s->top--];
    }
    return '$';

}
char peek(Stack* s) 
    { 
    return s->array[s->top]; 
    } 

bool isempty(Stack* s){
    return s->top==-1;
}

int main(){

Stack* s=(Stack*)malloc(sizeof(Stack));
    
    if(!s){         //malloc returns null pointer
        printf("Error\n");
        exit(0);
    }
    s->array=(char*)malloc(20*sizeof(char));
    
    if(!s){         //malloc returns null pointer
        printf("Error\n");
          pop(s);exit(0);
    }
    s->top=-1;
    
    push(s,'a');
    push(s,'b');
    push(s,'c');
    printf("\n");
    printf("%c",pop(s));
    printf("%c",pop(s));
    printf("%c",pop(s));
    isempty(s)?printf("EMPTY"):printf("NON_EMPTY");

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int top;
    char *array;

}Stack;

bool isempty(Stack*);
void push(Stack*,char);
char pop(Stack*);
char peek(Stack*);
int isOperand(char );
int precedence(char);

int main(){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    
    if(!s){         //malloc returns null pointer
        printf("Error\n");
        exit(0);
    }
    s->array=(char*)malloc(20*sizeof(char));
    
    if(!(s->array)){         //malloc returns null pointer
        printf("Error\n");
        exit(0);
    }
    s->top=-1;
    printf("Enter valid infix expression:\n");
    char c;
    while((c=getchar())!='\n'){
        if(isOperand(c)){ //if char read is operand simply print
            printf("%c",c);
        }
        else if(c=='('){ // if char is ( then push on stack
            push(s,c);
        }
        else if(c==')'){ // if char is ) then pop from stack till ( is encountered or stack is empty
            while(!isempty(s) && peek(s)!='('){
                printf("%c",pop(s));
            }
            pop(s);
        }

        else{ //if operator is encountered push it after popping higher precedence operators on stack
            while(!isempty(s) && (precedence(peek(s))>=precedence(c))){
                printf("%c",pop(s));
            }
            push(s,c);
            
        }
    }
    while(!isempty(s)){
        printf("%c",pop(s));
    }
    free(s->array);
    free(s);
    return 0;
}
int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

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

int precedence(char a)
{
	if(a == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(a== '*' || a== '/')
	{
		return(2);
	}
	else if(a == '+' || a == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

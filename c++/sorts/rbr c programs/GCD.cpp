#include<stdio.h>
int GCD (int a, int b);
int main(){
int a ,b;
    printf("enter two numbers:\n");
    scanf("%d%d",&a,&b);

    a=(a<0)?-a:a;
    b=(b<0)?-b:b;
    printf("gcd is: %d",GCD(a,b));
    
    
    return 0;
}
int GCD(int a,int b){
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}
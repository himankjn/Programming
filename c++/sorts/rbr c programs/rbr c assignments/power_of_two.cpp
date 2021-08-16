#include<stdio.h>
#include<stdlib.h>
bool isodd(int);
int main(){
    int n;
printf("enter n:\n");
scanf("%d",&n);
while(n!=1){
    if(isodd(n) || n==0){
        printf("not a power of 2\n");
        exit(0);
    }
    n=n>>1;
}
printf("power of 2");
    return 0;
}
bool isodd(int n){
    if(n%2==1){
        return true;
    }
return false;
}
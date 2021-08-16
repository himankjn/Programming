#include<iostream>
int main(){
    int n,count=0;
    scanf("%d",&n);
    while(n!=0){
        n=n/10;
        count++;
    }
    printf("\nnum of digits= %d\n",count);
    return 0;
}
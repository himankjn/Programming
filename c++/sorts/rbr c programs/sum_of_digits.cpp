#include<stdio.h>
int main(){
    int n,sum,r;
    scanf("%d",&n);
    sum=0;

    while(n!=0){
        r=n%10;
        sum+=r;
        n/=10;
    }
    printf("sum of digits = %d",sum);
    return 0;
}
#include<stdio.h>
int main(){
    int a,b,c,min,max;
    printf("enter 3 integers\n");
    scanf("%d%d%d",&a,&b,&c);
    a>b?(a>c?max=a:max=c):(b>c?max=b:max=c);
    a<b?(a<c?min=a:min=c):(b<c?min=b:min=c);
    printf("max=%d and min =%d",max,min);
}
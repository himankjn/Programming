#include<stdio.h>
#include<stdlib.h>
int main(){
    int a[10],count=0;
    printf("enter 10 integers");
    for (int i=0;i<10;i++){
    scanf("%d",&a[i]);
    }
int i=0;
    while(i!=7){
        if(a[i]==0 && a[i+1]==1 && a[i+2]==0 && a[i+3]==0)
        count++;
        i++;
    }
    printf("no of occurences =%d",count);
    return 0;
}
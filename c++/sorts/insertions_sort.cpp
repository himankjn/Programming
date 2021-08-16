#include<stdio.h>

void insertion_sort(int *a,int);
int main(){
    int a[]={3,8,5,9,1,4,2,6,7};
    int len=sizeof(a)/sizeof(a[0]);
    insertion_sort(a,len);
    return 0;
}

void insertion_sort(int *a,int len){
    int key,j;

    for(int i=1;i<len;i++){
        key=a[i];
        j=i-1;
        while( (key<a[j]) && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(int i=0;i<len;i++){
        printf("%d\t",a[i]);
    }


}
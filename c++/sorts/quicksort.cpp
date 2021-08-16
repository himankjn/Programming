#include<stdio.h>
void quicksort(int*,int,int);
int partition(int*, int,int);
void swap(int *,int*);

int main(){
    int a[]={4,8,1,9,2,3,6,7,5};
    int len=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,len-1);
    for(int i=0;i<len;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}
    
int partition(int* a,int p,int r){
    int pivot=a[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(a[j]<=pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
     swap(&a[i+1],&a[r]);
    return (i+1);
 }
    
    
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void quicksort(int* a,int p,int r){
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
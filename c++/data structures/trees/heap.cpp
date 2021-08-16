#include<stdio.h>
#include<iostream>
using namespace std;

void swap(int*,int*);
void heap_sort(int*,int);
void max_heapify(int*,int,int);
void build_heap(int*,int);
int extract_max(int*,int);
int insert_key(int*,int ,int);

int main(){
    int a[]= { 200,100,30,20,5,10,15,1 };
    int heapsize=sizeof(a)/sizeof(a[0]);
    printf("heapsize is :%d\n",heapsize);
    build_heap(a,heapsize);
    for(int i=0;i<heapsize;i++){
        printf("%d\t",a[i]);
    }
    // heapsize=extract_max(a,heapsize);
    /*
    for(int i=0;i<heapsize;i++){
        printf("%d\t",a[i]);
    }
    printf("\nheapsize is :%d\n",heapsize);

    heapsize=insert_key(a,300,heapsize);
    for(int i=0;i<heapsize;i++){
        printf("%d\t",a[i]);
    }
    printf("\nheapsize is :%d\n",heapsize);

    heap_sort(a,heapsize);
    for(int i=0;i<heapsize;i++){
        printf("%d\t",a[i]);
    }
    printf("\nheapsize is :%d\n",heapsize);
    */
    return 0;


}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void max_heapify(int *a,int i,int heapsize){
    int l,r,largest;
    //if 1 based indexing l=2*i   r=2*i+1
    l=2*i+1;
    r=2*i+2;
    largest=i;
    //n is heapsize
    if(l<heapsize && a[l]>a[i]) largest=l;
    if(r<heapsize && a[r]>a[largest]) largest=r;
    
    if(largest!=i){
        swap(&a[i],&a[largest]);
        max_heapify(a,largest,heapsize);
    }

}
void build_heap(int *a,int heapsize){
    //heapify all non leaf nodes since leafs are alredy max heaps.
    for(int i=heapsize/2-1;i>=0;i--){
        max_heapify(a,i,heapsize);
    }
}

int extract_max(int *a,int heapsize){
    if(heapsize<1)printf("Heap underflow!\n");
    int max=a[0];
    a[0]=a[heapsize-1];
    heapsize--;
    max_heapify(a,0,heapsize);
    printf("max=%d\n",max);
    return heapsize;
}

int insert_key(int *a,int key,int heapsize){
    int i=heapsize;
    heapsize++;
    a[i]=key; 
    while(i>0 && a[(i-1)/2]<a[i]){
        swap(&a[i],&a[(i-1)/2]);
        i=(i-1)/2;
    }
    return heapsize;

}

 void heap_sort(int* a,int heapsize){
    build_heap(a,heapsize);
    for(int i=heapsize-1;i>=1;i--){
        swap(&a[0],&a[i]);
        cout<<a[i];
        heapsize--;
        max_heapify(a,0,heapsize);
    }
 }

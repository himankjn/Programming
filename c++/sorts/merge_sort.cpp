#include<stdio.h>

void merge(int *,int,int,int);
void mergesort(int*,int,int);
int main(){
    int a[]={8,5,10,2,4,1,3,9,6,7};
    int len=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,len-1);
    for(int i=0;i<len;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}

void mergesort(int* a,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}

void merge(int*a, int p,int q,int r){
    int n1,n2;
    n1=(q-p)+1;
    n2=r-q;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++){
        left[i]=a[i+p];
    }
    for(int i=0;i<n2;i++){
        right[i]=a[i+q+1];
    }
    int k,i=0,j=0;
    for(k=p;k<=r;k++){
        if(i<n1 && j<n2){
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
        }
        else{
            a[k]=right[j];
            j++;
        }
    }
    else break;
    }

    if(i==n1){
        while(j<n2)
        a[k++]=right[j++];
    }
    else{
        while(i<n1)
        a[k++]=left[i++];
    }
}


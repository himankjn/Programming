#include<stdio.h>
int main(){
    int a,d,n,n_term;
    printf("enter value of first term, common difference and value of n: \n");
    scanf("%d%d%d",&a,&d,&n);
    n_term=a+(n-1)*d;
    printf("Nth term is: %d\n",n_term);
    
    printf("sum upto nterms is: %d\n",n*a+(d*n*(n-1)/2));
    printf("sum of n terms is %d:\n",(a+n_term)*n/2);

    return 0;
}


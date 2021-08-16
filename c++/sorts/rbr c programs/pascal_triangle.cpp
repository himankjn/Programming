#include<stdio.h>
long int factorial(int);
int main(){
    int n=5;
    for(int line=0;line<n;line++){
        printf("\n");
        for(int i=0;i<=line;i++){
            printf("%ld",factorial(line)/(factorial(line-i)*factorial(i)));
        }
    }
    return 0;

}

long int factorial(int n){
long int res=1;
for(int i=2;i<=n;i++){
    res*=i;
}
return res;
}
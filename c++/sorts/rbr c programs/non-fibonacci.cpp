#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
void non_fib(int);
int main(){
    int n;
printf("enter n:\n");
scanf("%d",&n);
non_fib(n);
return 0;
}

void non_fib(int n){
    int a=0,b=1;
    vector<int> fib;
    for(int i=1;i<=n;i++){
       fib.push_back(a);
       int temp=b;
       b=a+b;
       a=temp;
    }

    for(int i=0;i<fib[n-1];i++){
        if(binary_search(fib.begin(),fib.end(),i)){
            continue;
        }
        printf("%d\t",i);
    }
}
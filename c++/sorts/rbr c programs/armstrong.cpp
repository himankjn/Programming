#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n,m,original,r,count=0,sum=0;
    scanf("%d",&n);
    original=m=n;
    while(n!=0){
        n/=10;
        count++;
    }
    while(m!=0){
        r=m%10;
        m=m/10;
        sum+=pow(r,count);
    }
    if(sum==original){
        cout<<"\narmstrong \n";
    }
    else
    cout<<"\nNot armstrong\n";
    return 0;
}
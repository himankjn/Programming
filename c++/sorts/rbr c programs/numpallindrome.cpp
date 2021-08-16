#include<iostream>
using namespace std;

int main(){
    int n,original,rev=0,rem;
    cin>>n;
    original=n;
    while(n!=0){
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }

    if(rev==original)
    cout<<"pallindrome\n";
    else cout<<"not pallindrome\n";
    return 0;
}

#include<iostream>
using namespace std;

void print1ton(int n){
    if(n==0)
        return;
    
    print1ton(n-1);
    cout<<n<<endl;
}

int main(){
    print1ton(10);
    return 0;
}
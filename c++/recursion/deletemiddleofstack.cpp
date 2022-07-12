#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void deletekth(stack<int>&s,int k){
    if(k==1){
        s.pop();
        return ;
    }

    int temp=s.top();
    s.pop();
    deletekth(s,k-1);
    s.push(temp);
}
int main(){
    stack<int>s;
    for(int i=0;i<10;i++){
        s.push(i);
    }
    int n=s.size();
    deletekth(s,n/2+1);

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}
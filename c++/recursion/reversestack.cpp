#include<iostream>
#include<stack>

using namespace std;
void display(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void insertatbeg(stack<int>&s,int x){
    if(s.size()==0){
        s.push(x);
        return;
    }

    int temp=s.top();
    s.pop();
    insertatbeg(s,x);
    s.push(temp);
}
void reverse(stack<int>&s,int n){
    if(n==1)return;

    int temp=s.top();
    s.pop();
    reverse(s,n-1);
    insertatbeg(s,temp);
}
int main(){
    stack<int>s;
    int n=10;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    display(s);
    reverse(s,n);
    display(s);
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    int n,m,i,j;
    n=4,m=4;
    for(int i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(j<i){
            cout<<" ";
            }    
            else
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
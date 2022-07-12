#include<iostream>
using namespace std;


void toh(int x,int y,int z,int n){
    if(n==0)return;
    toh(x,y,z,n-1);
    cout<<x<<"to"<<y<<endl;
    toh(z,y,x,n-1);
    
}
int main(){
    int x=1,y=2,z=3;
    int n=1;
    toh(x,y,z,n);
    return 0;
}

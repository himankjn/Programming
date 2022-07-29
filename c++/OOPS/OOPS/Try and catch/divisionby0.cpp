#include<iostream>
using namespace std;

void divide(int x,int y){
    try{
        int temp=x/y;
        cout<<temp;
    }
    catch(exception& e){
        cout<<e.what();
    }
}

int main(){
    divide(19,2);
    divide(0,3);
    divide(3,0);
    return 0;
}
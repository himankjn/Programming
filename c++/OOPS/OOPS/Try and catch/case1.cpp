#include<iostream>
using namespace std;

int main(){
    int x=-1;
    cout<<"before try"<<endl;
    try{
        cout<<"inside try"<<endl;
        if(x<0){
            throw x;
            cout<<"after throw"<<endl;
        }
    }
    catch(int x){
        cout<<"inside catch"<<endl;
    }
    cout<<"after catch"<<endl;
    return 0;
}
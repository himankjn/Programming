#include<iostream>
using namespace std;

class A{
    public:
        int a;
        A(){
            cout<<"inside constructor"<<endl;
        }
        ~A(){
            cout<<"inside destructor"<<endl;
        }
};
int main(){
    int x=0;
    if(x==0)A obj; //scope is inside the body
    x=1;
    if(x==1)static A objj; //scope is till the end of the program
    cout<<"end of main"<<endl;
}
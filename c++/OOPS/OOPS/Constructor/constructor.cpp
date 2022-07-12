#include<iostream>
using namespace std;

class A{
    public:
        int a;
        A(){
            cout<<"inside constructor"<<endl;
        }
        A(int t){
            a=t;
        }
        A(A &t){
            a=t.a;
        }
        
};
int main(){
    A obj;
    A obj1(10);
    A obj2(obj1);

    cout<<obj1.a<<endl;
    cout<<obj2.a<<endl;

}
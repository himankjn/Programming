#include<iostream>
using namespace std;

class A{
    public:
        int a;
        A(){
            cout<<"inside A constructor"<<endl;
        }
        ~A(){
            cout<<"inside A destructor"<<endl;
        }
};
class B:public A{
    public:
        int a;
        B(){
            cout<<"inside B constructor"<<endl;
        }
        ~B(){
            cout<<"inside B destructor"<<endl;
        }
};
int main(){
    // B obj;
    A *obj= new B();
}
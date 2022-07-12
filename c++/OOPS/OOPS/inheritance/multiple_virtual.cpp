#include<iostream>
using namespace std;

class A{
    public:
        void print(){
            cout<<"IN A"<<endl;
        }
};
class B{
    public:
        virtual void print(){
            cout<<"IN B"<<endl;
        }
};
class D:public A,public B{
    public:
        void print(){
            cout<<"IN D"<<endl;
        }
};

int main(){

    B *b = new D();
    b->print();

}
#include<iostream>
using namespace std;

class A{
    public:
        int a=5;
};
class B:virtual public A{
    public:
        void get(){
            cout<<a<<endl;
        }
};
class C:virtual public A{
    public:
        void get(){
            cout<<a;
        }
};
class D:public B,public C{
    public:
        int d;
        void gett(){
            cout<<a;
        }
};

int main(){
    D dd;
    //Virtual base class
    dd.get(); //still function ambiguity is there as both the base class B and C has same function in it so we need to use the scope resolution
    dd.a=15;
    //it has only single copy of A in it
    // dd.gett();
    // dd.B::get();
            
}
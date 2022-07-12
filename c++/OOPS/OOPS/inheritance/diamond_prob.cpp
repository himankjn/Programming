#include<iostream>
using namespace std;

class A{
    public:
        int a=5;
};
class B:public A{
    public:
        void get(){
            cout<<a<<endl;
        }
};
class C:public A{
    public:
        void get(){
            cout<<a;
        }
};
class D:public B,public C{
    public:
        int d;
        // void get(){
        //     cout<<a;
        // }
};

int main(){
    D dd;
    // dd.B::get();
    dd.a=10;//ambiguity generated
    //Solution
        //Scope resolution
            // dd.B::a=10;
            // dd.C::a=15;
            // cout<<dd.B::a;
            // cout<<dd.C::a;
            //two different copies still exists in D
        //Virtual base class

}
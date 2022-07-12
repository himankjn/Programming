#include<iostream>
using namespace std;

class A{
    public:
        int a=5;
    private:
        int b=6;
    protected:
        int c=7;
};
// class B:public A{
//     public:

//     void get(){
//         // cout<<b;
//         cout<<c;
//     }
// };
// class B:private A{
//     public:

//     void get(){
//         // cout<<b;
//         cout<<c; //since B is the immediate derived class of A therefore protected members of A is accessible in B
//     }
// };
class B:protected A{
    public:

    void get(){
        // cout<<b;
        cout<<c; //since B is the immediate derived class of A therefore protected members of A is accessible in B
    }
};
class C:public B{
    public:
    void gett(){
        cout<<c; //when visibility is public or protected then only protected members are accessible transitively else not
    }
};

int main(){
    B bb;
    C cc;

    // cout<<bb.a;
    // cout<<bb.c;
    bb.get();
    // cout<<cc.a;
    cc.gett();

}
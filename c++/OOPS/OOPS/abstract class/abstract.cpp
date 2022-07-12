#include<iostream>
using namespace std;

class A{
    int x;
    public:
        A(){
            cout<<"Inside A constructor"<<endl;
        }
        virtual void show()=0;
        void set(int val){
            x=val;
        }
        int get(){
            return x;
        }
};
class B:public A{
    int y;
    public:
        B(){
            cout<<"Inside B constructor"<<endl;
        }
        void print(){
            cout<<"inside B"<<endl;
        }
};
class C:public A{
    int z;
    public:
        C(){
            cout<<"Inside C constructor"<<endl;
        }
        void show(){
            cout<<"inside C"<<endl;
        }
};
int main(){
    // A obj;
    // B obj;
    // C obj;
    // obj.show();
    // obj.set(10);
    // cout<<obj.get();

    // A *objj=new C();
    A* objj;
    objj=new C();
    // objj->show();
}   
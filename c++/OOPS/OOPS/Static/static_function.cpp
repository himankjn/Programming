#include<iostream>
using namespace std;

class A{
    int x=0;
    public:
        int a;
        A(){
            cout<<"inside constructor"<<endl;
        }
        ~A(){
            cout<<"inside destructor"<<endl;
        }
        void show(){
            cout<<"inside show"<<endl;
        }
        static void print(){
            cout<<"inside print"<<endl;
        }
};
int main(){
    A obj;
    // A objj=new A();
    // cout<<obj.x;
    obj.show();
    // obj.print();
    // A::print();
    // cout<<"end of main"<<endl;
}
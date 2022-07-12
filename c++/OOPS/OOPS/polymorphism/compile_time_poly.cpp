#include<iostream>
using namespace std;

class base{
    public:
        void print(){
            cout<<"In base class print";
        }
        void show(){
            cout<<"In base class show";
        }
};
class derived:public base{
    public:
        void print(){
            cout<<"In derived class print";
        }
        void show(){
            cout<<"In derived class show";
        }
};

int main(){
    base *b=new derived();
    //during compile time it checks for the type of pointer instead of its content due to static binding
    b->print();
    b->show();

}
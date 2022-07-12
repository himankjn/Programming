#include<iostream>
using namespace std;

class base{
    public:
        virtual void whoami()=0;

        virtual void print(){
            cout<<"In base class print"<<endl;
        }
        void show(){
            cout<<"In base class show"<<endl;
        }
};
class first_derived:public base{
    public:
        void whoami(){
            cout<<"I am in first dervied class"<<endl;
        }
        void print(){
            cout<<"In first derived class print"<<endl;
        }
        void show(){
            cout<<"In first derived class show"<<endl;
        }
};
class second_derived:public base{
    public:
        void whoami(){
            cout<<"I am in second dervied class"<<endl;
        }
        void show(){
            cout<<"In second derived class show"<<endl;
        }
};

int main(){
    base *b=new first_derived();
    //during run time it checks for the content of pointer and calls the function according to the instance due to dynamic binding
    b->print(); //since it was virtual function it goes for the instance function
    b->show(); //and it went for the type of the pointer
    b->whoami();

    b=new second_derived();

    b->show();
    b->whoami();

}
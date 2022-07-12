#include<iostream>
using namespace std;

class A{
    int x=0,y=0;
    double z=0;
    public:
        A(int a){
            x=a;
        }
        A(double a){
            z=a;
        }
        A(int a,int b){
            x=a;
            y=b;
        }
        A(int a,double b){
            x=a;
            z=b;
        }
        void get(){
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
};
void display(A object){
    //this function creates a new object of type class A called object and called its functions
    object.get();
}
int main(){
    // A obj=5;
    // A obj=5.0;
    // A obj={5,10};
    // obj.get();
    // obj={20,15.5};
    // obj.get();
    // obj={10,15};
    // obj.get();

    display({15,10});
}
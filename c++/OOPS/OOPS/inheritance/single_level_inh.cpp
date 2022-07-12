#include<iostream>
using namespace std;

class base{
    public:
        int a=10;
    private:
        int b=5;
    protected:
        int pro=15;
};
// class derived:public base{
//     public:
//         int c=5;
//     void get(){
//         cout<<pro<<" ";
//     }
// };
class derived:private base{
    public:
        int c=5;
        void show(){
            cout<<a<<" ";
        }
        void get(){
            // cout<<b<<" ";// only public and protected comes as private
            cout<<pro<<" ";
        }
};

int main(){
    derived d;
    // cout<<d.a<<" "; //in second case it is not accessible because the base class is privately inherited so object cant directly access it.
    // cout<<d.b<<" "; //it cant be accessed as it is a private member hence cant be inherited
    // d.show();// but the member functions can access the private members of base class
    cout<<d.pro;
    cout<<d.c<<" ";
    d.get();
}
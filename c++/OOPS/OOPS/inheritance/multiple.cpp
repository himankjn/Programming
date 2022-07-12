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
class B{
    public:
        int d=5;
    private:
        int e=6;
    protected:
        int f=7;
};
//CASE 1
class C:public A,public B{
    public:
        void get(){
            cout<<a;cout<<d;
            // cout<<b;cout<<e; //private members cant be accessed
            cout<<c;cout<<f; //protected can be accessed all the protected gets converted to protected members of this class
        }
};
//CASE 2
class C:public A,private B{
    public:
        void get(){
            cout<<a;cout<<d;
            // cout<<b;cout<<e; //private members cant be accessed
            cout<<c;cout<<f; //protected can be as all the protected gets converted to protected members of this class for A but for B the protected can be accessed as
                            // this is the immediate derived class of B
        }
};
//CASE 3
class C:private A,private B{
    public:
        void get(){
            cout<<a;cout<<d;
            // cout<<b;cout<<e; //private members cant be accessed
            cout<<c;cout<<f; //for both the protected can be accessed as this is the immediate derived class of B and A
        }
};
//CASE 4
class C:public A,protected B{
    public:
        void get(){
            cout<<a;cout<<d; //public member of B now became protected member of C
            // cout<<b;cout<<e; //private members cant be accessed
            cout<<c;cout<<f; // all protected members of A and B becomes the protected members of C
        }
};
//CASE 5
class C:protected A,protected B{
    public:
        void get(){
            cout<<a;cout<<d; //public member of A and B now became protected member of C
            // cout<<b;cout<<e; //private members cant be accessed
            cout<<c;cout<<f; // all protected members of A and B becomes the protected members of C
        }
};
//CASE 6
class C:private A,protected B{
    public:
        void get(){
            cout<<a;cout<<d; //public member of B now became protected member of C
            // cout<<b;cout<<e; //private members cant be accessed
            cout<<c;cout<<f; // all protected members of A and B becomes the protected members of C
        }
};
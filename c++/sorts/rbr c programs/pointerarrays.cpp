#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int a[5]={1,2,3,4,5};

    for(int i=0;i<5;i++){
        cout<<a[i];
    }

    cout<<endl;

    cout<<a[0]<<endl;
    cout<<&a[0]<<endl;
    cout<<a<<endl;

    cout<<&a[1]<<endl;
    cout<<a+1<<endl;



    int *p=a;
    cout<<p+1<<endl;


    cout<<*(a+1)<<endl;
    cout<<*(p+1)<<endl;

    *(p+1)=80;
       for(int i=0;i<5;i++){
        cout<<a[i];
    }
cout<<endl;

(p==a)?cout<<"yes":cout<<"no";cout<<endl;
(a==&a[0])?cout<<"yes":cout<<"No";cout<<endl;

char q[]="hello";
char *r=q;
cout<<q[0];


    return 0;
}
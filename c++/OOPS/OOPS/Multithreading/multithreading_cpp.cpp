#include<iostream>
#include<thread>
using namespace std;

//before cpp 11 we used posix threads (pthread)


void f1(int n){
    for(int i=1;i<=n;i++){
        cout<<"thread 1 executing"<<endl;
    }
}

void f2(int n){
    for(int i=1;i<=n;i++){
        cout<<"thread 2 executing"<<endl;
    }
}
int main(){


    thread t1(f1,5);
    thread t2(f2,5);

    t1.join();
    t2.join();

    return 0;
}
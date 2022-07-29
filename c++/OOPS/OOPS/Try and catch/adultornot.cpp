#include<iostream>
using namespace std;


void adultornot(int x){
    try{
        if(x>=18){
            cout<<"adult with age:"<<x<<endl;
        }
        else throw x;
    }

    catch(int x){
        cout<<"Exception: Yo! this is not an adult bitch!"<<endl;
    }

}
int main(){

    adultornot(22);
    adultornot(15);

    return 0;
}
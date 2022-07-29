#include<iostream>
using namespace std;

class Car{
    public:
    int a;

};
int main(){
    Car *car1= new Car();
    car1->a=10;
    Car *car2=car1;

    car1->a=20;
    cout<<car1->a;
    cout<<car2->a;
    return 0;
}
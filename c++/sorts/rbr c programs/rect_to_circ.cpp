#include<stdio.h>
#define Pi 3.142
int main(){
    int s;
    float r,area,circum;
    scanf("%d",&s);
    circum=4*s;
    r=circum/(2*Pi);
    area=Pi*r*r;
    printf("radium and area of circle : %f and %f",r,area);
    return 0;
}
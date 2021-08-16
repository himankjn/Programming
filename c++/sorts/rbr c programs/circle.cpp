/*Write a C program to check whether a circle can be drwan through
three given points on the Cartesian plane.*/

#include<stdio.h>
int main(){
    float area,x1,x2,x3,y1,y2,y3;
    printf("enter coordinates of 3 points pairwise:\n");
    scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);

    area=((x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1))/2;
    if(area==0){
        printf("No");
    }
    else{
        printf("yes");
    }
    return 0;
}
#include<stdio.h>
#include<math.h>
#define pi 3.14
int main(){
    float x1,x2,x3,y1,y2,y3,semi_per,area_of_tri,area_of_cir,side,incircle_x,incircle_y;;
    printf("enter 3 pairwise coordinates:");
    scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
    
    incircle_x= (x1+x2+x3)/3;
    incircle_y=(y1+y2+y3)/3;

    side=sqrt(pow((x2-x1),2)+ pow((y2-y1),2));
    semi_per=3*side/2;
    area_of_tri= sqrt(3)*pow(side,2)/4;

    area_of_cir=area_of_tri/semi_per;
    printf("coordinates of incenter: x=%f, y=%f \n Area of incircle = %f",incircle_x,incircle_y,area_of_cir);
    return 0;



}       


/* note: This program is for equilateral triangle.
incenter of triangle = (ax1+bx2+cx3)/(a+b+c)
KS=area of triangle. where S is semipermeter and k is  radius of incirgcle
*/
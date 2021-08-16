#include<stdio.h>
#include<math.h>
int factorial(int);
int main(){
    float term=0,prev_term=0,sum=0,x;
int n=1;
printf("enter value of x in radians: \n");
scanf("%f",&x);
do{
prev_term=term;
term= pow(-1,n+1) * (pow(x,2*n-1)/(factorial(2*n-1)));
sum+=term;
n++;
printf("%d",n);
}while(abs(abs(term)-abs(prev_term))>=0.001);


printf("value of sin(%f) is : %f",x,sum);
return 0;
}

int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

//sinx= (-1)^n+1 *  (X^2n-1)/2n-1!
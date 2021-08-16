#include<stdio.h>
void TOH(char,char,char,int);
int main(){
    char x,y,z;
    int n=3;
    x='a',y='b',z='c';

    TOH(x,y,z,n);
    return 0;
}

void TOH(char x,char y,char z,int n){
    if(n>=1){
    TOH(x,z,y,n-1);
    printf("move %c to %c\n",x,y);
    TOH(z,y,x,n-1);
    }
}


/* move:
a to b
a to c
c to b
a to b
c to a
c to b
a to b
*/

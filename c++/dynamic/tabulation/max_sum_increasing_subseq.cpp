#include<iostream>
using namespace std;


int maxSumIS(int arr[], int n)  
	{  
	   int i,j,max,temp,msis[n];//stores the max inc sum till ending at ith element
	   msis[0]=arr[0];
	   for(i=1;i<n;i++){
           temp=0;
	       for(j=0;j<i;j++){//all prev elements from i
               if(arr[j]<arr[i] && msis[j]>temp)
                   temp=msis[j];
           }
           msis[i]=arr[i]+temp;
           
	   }

	   max=arr[0];
	   for(i=0;i<n;i++){
	       if(max<msis[i]){
	       max=msis[i];
	       }
	   }
       return max;
	   
	}  

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxSumIS(a,n);
    return 0;
}
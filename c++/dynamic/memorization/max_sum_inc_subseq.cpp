#include<iostream>
#include<vector>
using namespace std;

vector<int>dp (1000,-1);

int msis(int arr[], int n)  
	{  
	  if(n==0){
          return arr[0];
      }

    int max=0;

    for(int j=0;j<n;j++){
        if (dp[j]==-1)dp[j]=msis(arr,j);

        if(arr[j]<arr[n] && dp[j]>max)
        max=dp[j];
    }

    
    return (arr[n]+max);
	   
	}  

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<msis(a,n-1);
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int den(int n){
    int x[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} ;
    int dp[n+1];// dp[i] stores # of den needed for ith element

    dp[0]=0;

    for(int i=0;i<=n;i++)dp[i]=i;

    for(int i=1;i<=n;i++){
       // a[]=//elements from x which are smaller or equal to i;
       int min=i;
        for(int j=0;j<10;j++){
        if(x[j]>i)break;
        if(min>dp[i-x[j]]+1)min=dp[i-x[j]]+1;
        }
        dp[i]=min;

    }
    return dp[n];   
}


int main(){
    int n;
    cin>>n;

    cout<<den(n);

    return 0;
}
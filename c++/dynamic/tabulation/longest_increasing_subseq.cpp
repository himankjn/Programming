#include<iostream>

using namespace std;


int liss(int a[],int N){
    int dp[N];
    for(int i=0;i<N;i++)dp[i]=1;
    
    for(int i=1;i<N;i++)
    for(int j=0;j<i;j++){
        if((a[i]>a[j]) && (dp[i]<dp[j]+1))dp[i]=dp[j]+1;
    }

    int max=0;
    for(int i=0;i<N;i++){
        if(dp[i]>max)max=dp[i];
    }
    return max;
}
int main(){
    int T,N,a[1000];
    cin>>T;
    while(T--){
    cin>>N;
    
    for(int i=0;i<N;i++)cin>>a[i];
    
    cout<<liss(a,N)<<endl;
    }
    
    return 0;
}
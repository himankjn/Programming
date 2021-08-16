#include<iostream>
using namespace std;

int max(int x,int y){return (x>y)?x:y;}

int ks(int p[],int w[],int C,int N){
    int dp[N+1][C+1];
    for(int i=0;i<=N;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=C;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=N;i++){
    for(int j=1;j<=C;j++){
        
        if(j==0){
            dp[i][j]=0;
            break;
        }
        if(w[i-1]>j){
            dp[i][j]=dp[i-1][j];
        }
        else{
            dp[i][j]=max( dp[i-1][j], dp[i-1][j-w[i-1]]+p[i-1]);
        }
     }
    }
    return dp[N][C];
}
int main(){
    int T,N,C,p[1000],w[1000];

    cin>>T;
    while(T--){
    cin>>N;
    cin>>C;
    for(int i=0;i<N;i++)cin>>p[i];
    for(int i=0;i<N;i++)cin>>w[i];
    cout<<ks(p,w,C,N)<<endl;
    }
    return 0;
}
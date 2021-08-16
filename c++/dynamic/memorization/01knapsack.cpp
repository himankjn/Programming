#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int max(int x,int y){return (x>y)?x:y;}

vector<vector<int>> dp (1000 , vector<int> (1000,-1));


int ks(int p[],int w[],int C,int N){
    if(N==0||C==0)return 0;
    
    if(dp[N][C]!=-1)return dp[N][C];
    
    if(C<w[N-1]){
        if(dp[N][C]==-1) return dp[N][C]=ks(p,w,C,N-1);
    }
    else{
        if(dp[N][C]==-1) return dp[N][C]=max(ks(p,w,C,N-1), ks(p,w,C-w[N-1],N-1)+p[N-1]);
                                        
    }
    return 0;
}

int main(){
    int T,N,C,p[1000],w[1000];

    cin>>T;
    while(T--){
    cin>>N;
    cin>>C;
    
    fill(dp.begin(), dp.end(), vector<int>(1000,-1));
    
    for(int i=0;i<N;i++)cin>>p[i];
    for(int i=0;i<N;i++)cin>>w[i];
    cout<<ks(p,w,C,N)<<endl;
    }
    return 0;
}
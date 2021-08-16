#include<iostream>
#include<string>
using namespace std;
int max(int x,int y){ return (x>y)?x:y;}

int lcs(string a,string b,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++){
        dp[i][j]=0;
    }


    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(a[i-1]==b[j-1]){     //0 indexing correction
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    int max=0;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(dp[i][j]>max)max=dp[i][j];
    }
    return max;

}
int main(){
    int t;
    string a,b;
    int n,m;

    cin>>t;
    while(t--){
    cin>>n>>m;
    getline(cin,a);
    getline(cin,a);
    getline(cin,b);
    
    cout<<lcs(a,b,n,m)<<endl;
    }
    
    return 0;
}
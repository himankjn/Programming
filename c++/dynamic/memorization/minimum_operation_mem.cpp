#include<iostream>
#include<vector>


using namespace std;
 vector<int> dp(10000,-1);

int min(int x,int y){
    return ((x<y)?x:y);
}

int min_op(int n){

    if(n==0)return 0;
    

    else if(n%2==0){//even n
    if(dp[n-1]==-1)dp[n-1]=min_op(n-1);
    if(dp[n/2]==-1)dp[n/2]=min_op(n/2);

       return min(dp[n-1]+1,dp[n/2]+1);
    }


    else{//odd n
         if(dp[n-1]==-1)dp[n-1]=min_op(n-1);
         if(dp[(n-1)/2]==-1)dp[(n-1)/2]=min_op((n-1)/2);

       return min(dp[(n-1)/2]+2,dp[n-1]+1);
    }
    
}
int main(){
    int t;
    cin>>t;
    int a[100];
    for(int i=0;i<t;i++)cin>>a[i];
    for(int i=0;i<t;i++){
        cout<<min_op(a[i])<<endl;
    
    }
    return 0;
}

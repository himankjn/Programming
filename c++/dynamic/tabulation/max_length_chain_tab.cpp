#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int lc(vector<pair<int,int>> a,int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }

    for(int i=1;i<n;i++){  //max length subseq till ith element
        for(int j=0;j<i;j++){
            if(a[i].first>a[j].second && dp[i]<dp[j]+1){
            dp[i]=dp[j]+1;
            }
        }
    }

    int max=0;
    for(int i=1;i<n;i++){
        if(max<dp[i])max=dp[i];
    }
    return max;
    
}

bool cmp(pair<int,int>a,pair<int,int>b){
    return (a.first<b.first);
}
int main(){
    int n,first,second;
    cin>>n;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        cin>>first;
        cin>>second;
        a.push_back(pair<int,int>(first,second));
    }

    sort(a.begin(),a.end(),cmp);
    cout<<lc(a,n);

    return 0;
}
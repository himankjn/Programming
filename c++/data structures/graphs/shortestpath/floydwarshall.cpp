#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n=3;
    vector<vector<int>>dist(n,vector<int>(n,0));
    dist={{1,2,3},{0,0,0},{3,2,1}};
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//check if graph is bipartite
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(int src,vector<int>&color,vector<vector<int>>&edges){
    color[src]=-1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int curV=q.front();
        int curcol=color[curV];
        q.pop();
        for(auto it:edges[curV]){
            if(color[it]==curcol)return false;
            else if(color[it]==curcol*-1)continue;
            color[it]=curcol*-1;
            q.push(it);
        }
    }
    return true;
}
int main() {
    int A=5;
    vector<vector<int>>B={{1,2},{2,3},{1,5},{2,4}};

    vector<vector<int>>edges(A+1,vector<int>());
    for(auto it:B){
        edges[it[0]].push_back(it[1]);
        edges[it[1]].push_back(it[0]);
    }
    
    vector<int>color(A+1,0);//-1 for red, 1 for blue
    for(int i=1;i<=A;i++)
    {   
        if(color[i]==0 and !bfs(i,color,edges))cout<<false;
    }
    
    cout<< true;
}

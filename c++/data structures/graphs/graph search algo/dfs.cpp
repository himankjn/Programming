#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
class Graph{
    int V;
    vector<int> *adj;
    int *visited;
    public:
    Graph(int V ){
    this->V=V;
    adj=new vector<int>[V];
    visited=new int[V]();
    }
    void addedge(int i,int j);
    void dfs(int i);
    
};

void Graph::addedge(int i,int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void Graph::dfs(int i){
    visited[i]=1;
    cout<<"\nJust visited node: "<<i;
    for(auto it:adj[i]){
        if(!visited[it]){
            dfs(it);
        }
    }
}
int main(){
    Graph G(5);
    G.addedge(0,1);
    G.addedge(0,2);
    G.addedge(1,4);
    G.addedge(2,3);
    G.dfs(0);
    return 0;
}
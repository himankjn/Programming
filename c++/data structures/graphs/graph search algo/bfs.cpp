#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;


class Graph{
    int V;
    vector<int> *adj;
    queue<int> Q;
    int *visited;
    public:
    Graph(int V){
        this->V=V;
        visited=new int[V];
        adj=new vector<int>[V]();
    }
    void addedge(int i,int j);
    void bfs(int i);
};



void Graph::addedge(int i,int j){
    adj[i].push_back(j);
}

void Graph::bfs(int i){
    visited[i]=1;
    cout<<"\njust visited node: \t"<<i;
    for(auto it:adj[i]){
        if(!visited[it]){
            Q.push(it);
            visited[it]=1;
        }
    }
    while (!Q.empty()){
        int temp=Q.front();
        Q.pop();
        bfs(temp);
    }
}

int main(){
    Graph G(5);
    G.addedge(0,1);
    G.addedge(0,2);
    G.addedge(1,4);
    G.addedge(2,3);
    G.bfs(0);

    return 0;
}
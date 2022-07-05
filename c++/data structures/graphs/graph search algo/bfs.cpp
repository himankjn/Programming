#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
#include<queue>

using namespace std;


class Graph{
    public:
    int V;
    vector<int> *adj;
    unordered_map<int,bool>visited;
    queue<int> Q;
    Graph(int V){
        this->V=V;
        adj=new vector<int>[V]();
    }
    void addedge(int i,int j);
    void bfs(int i);
};



void Graph::addedge(int i,int j){
    adj[i].push_back(j);
}

void Graph::bfs(int i){
    Q.push(i);
    while (!Q.empty()){
        int temp=Q.front();
        Q.pop();
        visited[temp]=true;
        cout<<"\njust visited node: \t"<<temp;
        
        for(int it:adj[temp])
            {
            if(visited[it]==0)
                Q.push(it);
            }
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
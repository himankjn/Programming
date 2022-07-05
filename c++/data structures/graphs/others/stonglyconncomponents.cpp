//kosaraju algorithm (# of strongly connected components)

// note: scc remain scc even after reversing edges. but outgoing edges not part of scc are no more outgoing. hence no dfs on them
// thats why dfs on reversed graph gives # of strongly connected comps

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

void printgraph(vector<int>adj[],int V){
    for(int i=0;i<5;i++){
        for(auto it:adj[i]){
            cout<<"edge: "<<i<<"to"<<it<<endl;
        }
    }
}

void dfs(int u,vector<int>adj[],vector<bool>&visited,stack<int>&stk){
    visited[u]=true;
    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(v,adj,visited,stk);
        }
    }
    stk.push(u);
}
int kosaraju(vector<int>adj[],int V){
    stack<int>stk;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i])
            dfs(i,adj,visited,stk);
    }

    vector<int>new_adj[V];
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            new_adj[it].push_back(i);
        }
    }

    visited=vector<bool>(V,false);
    stack<int>extrastk;
    int count=0;
    while(!stk.empty()){
        int curV=stk.top();
        stk.pop();
        if(!visited[curV]){
            count++;
            dfs(curV,new_adj,visited,extrastk);
        }
    }
    return count;

}
int main(){
    //number of vertices
    int V=9;
    vector<int>adj[V];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,0);
    addedge(adj,2,4);
    addedge(adj,4,5);
    addedge(adj,5,6);
    addedge(adj,6,7);
    addedge(adj,7,8);
    
    //printgraph(adj,V);

    int n=kosaraju(adj,V);
    cout<<"number of strongly connected components: "<<n;
    return 0;
}

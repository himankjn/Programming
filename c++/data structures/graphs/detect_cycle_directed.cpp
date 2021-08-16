#include<iostream>
#include<vector>
#include<cstring>
#include<list>
using namespace std;
//note: for directed graph cycle detection using dfs. we need to keep track of currect vertices in stack in addition to visited.
class Graph{
    int V;
    vector<vector<int>> edges;// adjacency list of edges

    public:
    Graph(int V) 
    { 
    this->V = V; 
    edges=vector<vector<int>>(V);
   
    }  
    void addEdge(int m,int n){
        edges[m].push_back(n);
    }
    bool dfs_cycle();
    bool dfs_util(int, bool[],bool []);

};
 
 
  


bool Graph:: dfs_util(int V,bool visited[],bool rec_stack[]){
    if(!visited[V]){
    visited[V]=true;
    rec_stack[V]=true;

    for(auto it:edges[V]){ 
        if(visited[it] && rec_stack[it])return true;
        else if(!visited[it] && dfs_util(it,visited,rec_stack))return true;
        //if adjacent edge is visited & it is in recursion stack, then cycle.
        //if adjacent edge is unvisited dfs it. 
        
    }
    }
    rec_stack[V]=false;//backtrack

    return false;//no cycle.
}
bool Graph::dfs_cycle(){
    bool visited[100];
    bool rec_stack[100];
    for(int i=0;i<V;i++){
        memset(visited,0,sizeof(visited)/sizeof(bool));
        memset(rec_stack,0,sizeof(rec_stack)/sizeof(bool));
        if(dfs_util(i,visited,rec_stack))return true;
    }
    return false;
    
}

int main(){
    Graph g1(4);
    g1.addEdge(0,1);
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(2, 0); 
    


    if(g1.dfs_cycle())cout<<"cycle detected"<<endl;
    else cout<<"No cycle"<<endl;
    return 0;
}
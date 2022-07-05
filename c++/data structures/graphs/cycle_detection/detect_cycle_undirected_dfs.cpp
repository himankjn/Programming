#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//Note: cycle can also be detected using disjoint sets in V*logE.

//Note: in undirected graph instead of recursion stack we use a parent variable in conjunction with visited array.
// If the adjacent node is visited then return true except when the adjacent node happens to be the parent.
class Graph{
    int V;
    vector<vector<int>> edges;
    public:
    Graph(int);
    void addEdge(int ,int);
    bool dfs(int,bool[],int);
    bool is_cyclic();
};
Graph:: Graph(int V){//constructor to initialize Vertices and adjacencly list;
    this->V=V;
    edges=vector<vector<int>>(V);
    }

void Graph::addEdge(int m,int n){
    edges[m].push_back(n);
    edges[n].push_back(m);
}

bool Graph::dfs(int V,bool Visited[],int parent){
    Visited[V]=true;
    for(auto it:edges[V]){//for all edges adjacent to V
        if(Visited[it] && it!=parent){
            return true; 
        }
        else if(!Visited[it]&& dfs(it,Visited,V))return true;
    }
    return false;
    
}
bool Graph::is_cyclic(){//O(VE)
    bool Visited[100];
    memset(Visited,false,sizeof(Visited)/sizeof(bool));
    for(int i=0;i<V;i++){
        if(Visited[i])continue;
        if(dfs(i,Visited,-1))return true;
    }
    return false;
}




int main(){
    Graph g1(4);
    g1.addEdge(1,3);
    g1.addEdge(1,2);
    g1.addEdge(2,3);

    if(g1.is_cyclic()){
        cout<<"graph g1 contains cycle"<<endl;
    }
    else cout<<"No cycle detected"<<endl;
    return 0;
}


/*

        vector<int>indegree(numCourses,0);
        queue<int>q;
        vector<vector<int>>edges(numCourses,vector<int>());
        
        
        for(auto it:prerequisites){
            indegree[it[0]]++;
            edges[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        vector<int>fin;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            fin.push_back(v);
            for(auto u:edges[v]){
                indegree[u]--;
                if(indegree[u]==0)q.push(u);
            }
        }

        if(fin.size()==V) no cycle
        else cycle

*/
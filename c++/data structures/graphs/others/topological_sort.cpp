#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Graph{
    int V;
    vector<vector<int>> edges;
    public:
    Graph(int V){
        this->V=V;
        this->edges=vector<vector<int>>(V);
    }

    void addEdge(int src,int dest);
    void topological_sort();

    void topological_util(int i,stack<int>&S, bool visited[]);

};


void Graph::addEdge(int src,int dest){
    edges[src].push_back(dest);
}

void Graph::topological_sort(){

    stack<int>S;
    bool visited[100];
    for(int i=0;i<V;i++){
        visited[i]=0;
    }

    for(int i=0;i<V;i++){ //incase of disconnected graph, else not needed.
        if(!visited[i]){
            topological_util(i,S,visited);
        }
    }

    int n=S.size();
    while(n--){
        cout<<S.top()<<endl;
        S.pop();
    }
    
}

void Graph::topological_util(int i,stack<int>&S,bool visited[]){

    if(!visited[i]){
        visited[i]=true;
        for(auto it:edges[i]){
            topological_util(it,S,visited);
        }
        S.push(i);
    }
}

int main(){

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topological_sort();
    return 0;
}
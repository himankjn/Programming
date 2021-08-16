#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Graph{
     public:
    int V;
    unordered_map<int,unordered_map<int,int>>edges;

    
   
    Graph(int V){
        this->V=V;
    }
    void addedge(int src,int dest,int wt){
        this->edges[src][dest]=wt;
    }

};

int main(){

    Graph G(5);
    G.addedge(1,2,3);
    G.addedge(0,1,2);
    G.addedge(2,3,9);
    G.addedge(3,4,21);

    for (auto u:G.edges){
        for (auto d:u.second){
            cout<<u.first<<"->"<<d.first<<" : "<<d.second<<endl;
        }
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
        int V = 4, E = 5;
        vector<vector<int>>edges={{0,3,3},{0,2,1},{1,3,1},{3,0,5},{2,3,1}};
        vector<int> dist(V,INT_MAX);
        int src=0;
        // Step 1: Initialize distances from src to all other
        // vertices as INFINITE
        dist[src] = 0;
 
        // Step 2: Relax all edges |V| - 1 times. A simple
        // shortest path from src to any other vertex can
        // have at-most |V| - 1 edges
        for (int i = 1; i < V; ++i) {
            for (int j = 0; j < E; ++j) {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        for(int i=0;i<V;i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
    return 0;
}
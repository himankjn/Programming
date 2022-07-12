#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;


struct cmp{
        bool operator()(pair<int,int>&p1,pair<int,int>&p2){
            p1.first>p2.first;
        }
    };
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
        dist[S]=0;
        q.push({0,S});
        
        while(!q.empty()){
            pair<int,int>p=q.top();
            q.pop();
            int curdist=p.first;
            int curv=p.second;
            for(auto it:adj[curv]){
                int neig=it[0];
                int uvdist=it[1];
                if(dist[neig]> curdist+uvdist){
                    dist[neig]=dist[curv]+uvdist;
                    q.push({dist[neig],neig});
                }
            }
        }
        return dist;
        
    }

    int main(){
        int V=3;
        vector<vector<int>>adj[]={{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
        int S=2;
        vector<int>dist=dijkstra(V,adj,S);
        for(int i=0;i<V;i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
        
        return 0;
    }
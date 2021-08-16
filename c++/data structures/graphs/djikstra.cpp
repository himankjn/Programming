#include<iostream>
#include<vector>
#include<cstring>
#include<limits.h>
using namespace std;






class Graph{
    public:
    int V;
    vector<pair<int,int>> *edges;

    Graph(int V){
        this->V=V;
        this->edges=new vector<pair<int,int>>[V]; //each edge/index stores vectors of pair(destionation vertex,distance);
       
    }

    void djikstra(int i);
    void addEdge(int src,int dest,int wt){
        edges[src].push_back(make_pair(dest,wt));
    }

};

class MinHeapNode{
    public:
    int vertex;
    int wt;
};

class MinHeap{
    public:
    int heapsize;
    int *pos;
    MinHeapNode *arr;

    MinHeap(int V){
        this->heapsize=V;
        this->pos=new int [V];
        this->arr=new MinHeapNode[V];
    }
    
    MinHeapNode extract_min();
    void decrease_key(int,int);
    void min_heapify(int);
};

void min_heapify(int arr[],int i,int heapsize);
void create_heap(int arr[],int heapsize);


void swap(MinHeapNode *n,MinHeapNode *m){
    MinHeapNode temp=*n;
    *n=*m;
    *m=temp;
}
void MinHeap:: min_heapify(int i){
    int min=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<heapsize && arr[l].wt<arr[min].wt) min=l;
    if(l<heapsize && arr[r].wt<arr[min].wt)min=r;
    
    if(min!=i){
        pos[arr[min].vertex]=i;
        pos[arr[i].vertex]=min;
        swap(&arr[i],&arr[min]);
        min_heapify(min);
    }
}

MinHeapNode MinHeap::extract_min(){
    if(heapsize!=0){// no underflow
       
        // Store the root node 
        MinHeapNode root = arr[0]; 
    
        // Replace root node with last node 
        MinHeapNode lastNode = arr[heapsize - 1]; 
        this->arr[0] = lastNode; 
    
        // Update position of last node 
        this->pos[root.vertex] = heapsize - 1; 
        this->pos[lastNode.vertex] = 0; 
    
        // Reduce heap size and heapify root 
        --this->heapsize;
        min_heapify(0); 
    
        return root; 

}
MinHeapNode root = arr[0]; 
return root;
}

void MinHeap:: decrease_key(int vertex,int wt){
    int i=pos[vertex];
    this->arr[i].wt=wt;
    int parent=(i-1)/2;
    while (i!=0 && arr[i].wt < arr[(i-1)/2].wt) { 
        parent=(i-1)/2;
        // Swap this node with its parent 
        pos[arr[i].vertex] = parent; 
        pos[arr[parent].vertex] = i; 
        swap(&arr[i], &arr[parent]); 
  
        // move to parent index 
        i = (i-1)/2;
    } 
}
int main(){
    int V=9;
    Graph g1(V);

    g1.addEdge(0, 1, 4); 
    g1.addEdge(0, 7, 8); 
    g1.addEdge(1, 2, 8); 
    g1.addEdge(1, 7, 11); 
    g1.addEdge(2, 3, 7); 
    g1.addEdge(2, 8, 2); 
    g1.addEdge(2, 5, 4); 
    g1.addEdge(3, 4, 9); 
    g1.addEdge(3, 5, 14); 
    g1.addEdge(4, 5, 10); 
    g1.addEdge(5, 6, 2); 
    g1.addEdge(6, 7, 1); 
    g1.addEdge(6, 8, 6); 
    g1.addEdge(7, 8, 7); 
  
    g1.djikstra(0);
    
    return 0;
}

void Graph:: djikstra(int src){

    MinHeap heap(V);
    int dist[V];  
    int mst[V];
    int sum=0;

    for(int v=0;v<V;v++){
        mst[V]=0;
        dist[v]=INT_MAX;
        heap.arr[v].wt=INT_MAX;
        heap.arr[v].vertex=v;
    }

    mst[src]=1;
    heap.arr[src].vertex=0;
    heap.arr[src].wt=INT_MAX;
    heap.pos[src]=src;
    dist[src]=0;
    heap.decrease_key(src,0);

    heap.heapsize=V;

    while(heap.heapsize!=0){
        MinHeapNode cur_node= heap.extract_min();
        int cur_vertex=cur_node.vertex;
            sum=sum+cur_node.wt;
        for(auto it:edges[cur_vertex]){
            int adj_vertex=it.first;
            int adj_dist=it.second;
            if (dist[cur_vertex] != INT_MAX &&  adj_dist + dist[cur_vertex] < dist[adj_vertex]) 
                { 
                    dist[adj_vertex] = dist[cur_vertex] + adj_dist; 

                    // update distance value in min heap also 
                    heap.decrease_key(adj_vertex, dist[adj_vertex]); 
                }  
        }
    }
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
    
    cout<<"total sum of dist: "<<sum<<endl;
}
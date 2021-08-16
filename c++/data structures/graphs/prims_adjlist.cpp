#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<cstring>
using namespace std;




class Graph{
    public:
    int V;
    vector<pair<int,int>> *edges;

    Graph(int V){
        this->V=V;
        this->edges=new vector<pair<int,int>>[V]; //each edge/index stores vectors of pair(destionation vertex,distance);
       
    }

    void prims();
    void addEdge(int src,int dest,int wt){
        edges[src].push_back(make_pair(dest,wt));
        edges[dest].push_back(make_pair(src,wt));
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
    int capacity;
    int *pos;
    MinHeapNode *arr;

    MinHeap(int V){
        this->heapsize=0;
        this->capacity=V;
        this->pos=new int[V]; 
        this->arr=new MinHeapNode[capacity];
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
    
    int V;
    V=9;
    Graph g1(V);
    
   /* g1.addEdge(0, 1, 4); 
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
    */
   g1.addEdge(7,6,1);
   g1.addEdge(8,2,2);
   g1.addEdge(6,5,2);
    g1.addEdge(0,1,4);
    g1.addEdge(2,5,4);
    g1.addEdge(8,6,6);
    g1.addEdge(2,3,7);
    g1.addEdge(7,8,7);
    g1.addEdge(0,7,8);
    g1.addEdge(1,2,8);
    g1.addEdge(3,4,9);
    g1.addEdge(5,4,10);
    g1.addEdge(1,7,11);
    g1.addEdge(3,5,14);
    g1.prims();

}

void Graph:: prims(){
 
    int mst[V];
    int parent[V];
    int wt[V];

    int sum=0;

    MinHeap heap(V);

    for (int v= 1; v < V; v++) { 
        parent[v] = -1;  
        wt[v]=INT_MAX;
        heap.arr[v].vertex=v;
        heap.arr[v].wt=INT_MAX;
        heap.pos[v]=v;
        mst[v]=0;
    } 

    mst[0]=1;//0 vertex visited;
    heap.arr[0].vertex=0;
    heap.arr[0].wt=0;
    heap.pos[0]=0;
    heap.heapsize=V;

    int  prev_node=0;
    while(heap.heapsize!=0){
        MinHeapNode cur_node=heap.extract_min();
        prev_node=parent[cur_node.vertex];
        cout<<prev_node<<"-"<<cur_node.vertex<<"weight: "<<cur_node.wt<<endl;

        sum=sum+cur_node.wt;
        int cur_vertex=cur_node.vertex;
     
        mst[cur_vertex]=1;
        for(auto it: edges[cur_vertex]){ //for all adjacent vertices of cur_vertex update heap key
            int adj_vertex=it.first;
            int adj_wt=it.second;
            if(mst[adj_vertex]!=1 && (adj_wt< wt[adj_vertex]) ){
                wt[adj_vertex]=adj_wt; 
                parent[adj_vertex]=cur_vertex;
                heap.decrease_key(adj_vertex,adj_wt);
            }
            
        }
    }



    /*for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }*/
    cout<<"total sum of dist: "<<sum<<endl;

}
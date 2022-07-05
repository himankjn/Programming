#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Edge{
    public:
    int src,dest,wt;
};

class dis_set{// disjoint set
    public:
    int root;
    int rank;
};

class Graph{
    int V,E;//no. of vertices and edges

    Edge *edges;//array of edges

    //disjoint set for every vertex
    dis_set *subsets;

    public:
    
    Graph(int,int);
    void addEdge(int,int,int ,int);
    void kruskal();
    void prims();
    void create_set(dis_set subsets[],int V);
    int find_root(dis_set subsets[],int V);
    void Union(dis_set subsets[], int x, int y);
};

bool compare_edges(Edge e,Edge);



 int main(){
     int V = 9; // Number of vertices in graph  
    int E = 14; // Number of edges in graph  
    Graph g1(9,14); 
  
  
    // add edge 0-1  
    /*g1.addEdge(0,0,1,10);
    g1.addEdge(1,0,2,6);
    g1.addEdge(2,0,3,5);
    g1.addEdge(3,1,3,15);
    g1.addEdge(4,2,3,4);
    */
   g1.addEdge(0,7,6,1);
   g1.addEdge(1,8,2,2);
   g1.addEdge(2,6,5,2);
    g1.addEdge(3,0,1,4);
    g1.addEdge(4,2,5,4);
    g1.addEdge(5,8,6,6);
    g1.addEdge(6,2,3,7);
    g1.addEdge(7,7,8,7);
    g1.addEdge(8,0,7,8);
    g1.addEdge(9,1,2,8);
    g1.addEdge(10,3,4,9);
    g1.addEdge(11,5,4,10);
    g1.addEdge(12,1,7,11);
    g1.addEdge(13,3,5,14);
    
    g1.kruskal();  
     return 0;
 }


 Graph:: Graph(int V,int E){//constructor to initialize Vertices and adjacencly list;
    this->V=V;
    this->E=E;
    edges=new Edge[E];//array of E edges initilized
    subsets=new dis_set[(V*sizeof(dis_set))];
    }

void Graph:: addEdge(int i,int s,int d,int w){
    edges[i].src=s;
    edges[i].dest=d;
    edges[i].wt=w;
    
}
void Graph:: kruskal(){
    
    sort(edges,edges+E,compare_edges);

    for(int i=0;i<V;i++){
        create_set(subsets,i);//create new disjoint set for every vertex
    }

    int count=0,sum=0,source,destination,root_src,root_dest;
    for(int i=0;i<E;i++){
        source=edges[i].src;
        destination=edges[i].dest;
        root_src=find_root(subsets,source);
        root_dest=find_root(subsets,destination);
        
        if(root_src==root_dest){
            //cycle detected;
            continue;
        }
        else{
            Union(subsets,source,destination);
            printf("Edge added from %d to %d with weight %d ",source,destination,edges[i].wt);
            cout<<endl;
            count++;
            sum=sum+edges[i].wt;

        }
        if(count==V-1)break;

    }
    cout<<"Min Spanning tree weight sum= "<<sum<<endl;

}




bool compare_edges(Edge e1,Edge e2){
    return (e1.wt<e2.wt);
}

void Graph:: create_set(dis_set subsets[],int V){
    subsets[V].root=V;
    subsets[V].rank=0;
}

int Graph:: find_root(dis_set subsets[],int V){
    int V_root= subsets[V].root;
    if(V_root==V)return V_root; //if root(V) ==V return V

    else{ // if root(V) is differnt from V. make root of root(V) as root(root(V))
        subsets[V].root=find_root(subsets,V_root);
    }

    return subsets[V].root;
}
void Graph:: Union(dis_set subsets[],int x,int y){ // union by rank, sets of x and y;
    int x_root=find_root(subsets,x);
    int y_root=find_root(subsets,y);
    int x_set_rank=subsets[x_root].rank;
    int y_set_rank=subsets[y_root].rank;

    if(x_set_rank<y_set_rank)//if rank of set containin x is less than set containing y
        subsets[x_root].root=y_root;
    else if(y_set_rank<x_set_rank)
        subsets[y_root].root=x_root;

    else{
        subsets[y_root].root=x_root;
        subsets[x_root].rank++;
    }
}


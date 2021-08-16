#include<iostream>

using namespace std;

class set{
    public:
    int rank;
    int parent;
};

void create_set(set subsets[],int v){
    subsets[v].parent = v;  
        subsets[v].rank = 0; 
}

int find_parent(set subsets[],int i){
    if (subsets[i].parent != i) //path compression. 
        subsets[i].parent = find_parent(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void union_set(set subsets[],int x,int y){//union by rank. i.e. small unioned to bigger
    int xparent=find_parent(subsets,x);
    int yparent=find_parent(subsets,y);
    int xrank=subsets[xparent].rank;
    int yrank=subsets[yparent].rank;


    if (xrank < yrank)  //rank of x set is smaller
        subsets[xparent].parent = yparent;  
    else if (yrank < xrank) // rank of y set is smaller 
        subsets[yparent].parent = xparent;  
  
    // If ranks are same, then make one as root and  
    // increment its rank by one  
    else
    {  
        subsets[yparent].parent = xparent;  
        subsets[xparent].rank++;  
    }  
}

int main(){
    set subsets[10];
    for (int v = 0; v < 10; ++v)  
    {
        create_set(subsets,v); 
    }  

    union_set(subsets,0,1);
    union_set(subsets,2,3);
    union_set(subsets,0,2);

    cout<<find_parent(subsets,0);
    cout<<find_parent(subsets,1);
    cout<<find_parent(subsets,2);
    cout<<find_parent(subsets,3);
    return 0;
}
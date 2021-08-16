/*Heap in c++
1) priorityqueue<int> q;    //max heap of int
2) priorityqueue<int,vector<int>,greater<int>> q;  //min heap of ints
3) priorityquque<node, vector<node>, mycomp> q;    //max heap of nodes compared based on mycomp
4) make_heap(v.begin(),v.end())    //build heap of arr

*/
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;

class node{
    public:
    int a,b,c;
    node(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
};

class mycomp{
    public:
    int operator()(node A,node B){
        return A.b>B.b;
    }
};

int main(){
    priority_queue<node,vector<node>,mycomp> q;

    q.push(node(1,2,3));
    q.push(node(8,9,10));
    q.push(node(0,1,1));
    q.push(node(6,3,0));

    cout<<q.top().b;
    q.pop();

    
    return 0;
}
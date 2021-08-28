/*
#Longest common substring between two strings A and B
#Brute force is O(N*M*M) check every length substring in both m and n

#Dynamic programming O(N*M)

#We can do O(Nlog(N)) using robin karp and hashtable and binary search.
#Find L using binary search. start with L -> M->M/2->M/4....
#For every such L apply commonsubstr algo using robin karp and hash table which takes O(N+M)
# Therefore total = O((N+M)*LogM)
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<math.h>
using namespace std;


bool match(string A,int i,string B,int j,int L){
    int k=0;
    while(k<L){
    if(A[i+k] != B[j+k]){
        return false;
    }
    k+=1;
    }
    return true;
    
}
string commonsubstr(string A,string B, int L, int q,unordered_map<int,vector<int>> table){
    table.clear();
    int m=A.size();
    int n=B.size();
    int val=0;
    for (int i=0;i<L;i++){
        val=val*2+(A[i]-'0');       
    }
    table[val].push_back(0);

    for (int i=1;i<=m-L;i++){
        int j=i+L-1;
        val= ( val*2 + (A[j]-'0') )%q;
        val=val - ( (int)pow(2,L) * (A[i-1]-'0') )%q;
        table[val].push_back(i);
    }
    
    val=0;
    //Match the table entries with substrings of B;
    for (int i=0;i<L;i++){
            val=val*2+(B[i]-'0');       
    }

    if (!table[val].empty()){
        for (auto it:table[val]){
            if(match(A,it,B,0,L)){
                return B.substr(0,L);
            }
        }
    }

    for (int i=1;i<=n-L;i++){
        int j=i+L-1;
        val= ( val*2 + (B[j]-'0') )%q;
        val=val - ( (int)pow(2,L) * (B[i-1]-'0') )%q;
        if (!table[val].empty()){
        for (auto it:table[val]){
            if(match(A,it,B,i,L)){
                return B.substr(i,L);
            }
        }
    }
    }


    return "-1";

}
class node{
    public:
    string s;
    int idx;
    node(string s,int idx){
        this->s=s;
        this->idx=idx;
    }
};

node LCSubStr(string A,string B,int q){
    int m=A.size();
    int n=B.size();
    int L=min(n,m);
  
    unordered_map<int,vector<int>>table;
    string x=commonsubstr(A,B,L,q,table);
    if (x!="-1")
        return node(x,L);
    int start=0;
    int end=L;
    
    while(start<end){
        int mid=(start+end)/2;
        table.clear();
        if (commonsubstr(A,B,mid,q,table)!="-1")
            start=mid+1;
        else
            end=mid-1;
    }
    table.clear();
    return node(commonsubstr(A,B,end,q,table),end);
}
int main(){
    
    string A="1000110001100100110101";
    string B="00100011011";
    int q=pow(2,20);
    node x=LCSubStr(A,B,q);
    cout<<"longest string of len "<<x.idx<<" : "<<x.s;
    return 0;
}
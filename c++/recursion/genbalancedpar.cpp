#include<iostream>
#include<vector>
using namespace std;
void genpar(int open,int closed,string op,vector<string>&fin){
    if(open==0 and closed==0){
        fin.push_back(op);
        return;
    }
    if(open>0){
        genpar(open-1,closed,op+'(',fin);
    }
    if(closed>open){
        genpar(open,closed-1,op+')',fin);
    }
}

int main(){
    int n=3;
    int open=n;
    int closed=n;
    string op="";
    vector<string>fin;
    genpar(open,closed,op,fin);

    for(auto it:fin){
        cout<<it<<" ";
    }
    return 0;
}
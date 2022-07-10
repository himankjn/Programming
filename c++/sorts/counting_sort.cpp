#include<iostream>
#include<vector>
using namespace std;

//given a range 0 to n . sort them;

vector<int> countsort(vector<int>&A,int n){
    vector<int>count(n+1,0);

    for(auto it:A){
        count[it]++;
    }
    vector<int>fin;
    for(int i=0;i<=n;i++){
        int k=count[i];
        while(k--){
            fin.push_back(i);
        }
    }
    return fin;
}
int main(){

    vector<int>A={0,3,5,2,1,0,4,2,5,3,2,1,4,3,5};

    vector<int>fin=countsort(A,5);
    for(auto it:fin){
        cout<<it<<" ";
    }
    return 0;
}
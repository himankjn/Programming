#include<iostream>
#include<vector>
using namespace std;

void insertionsort(vector<int>&A){
    int n=A.size();
    for(int j=1;j<n;j++){
        int key=A[j];
        int i=j;
        while(i-1>=0 and A[i]<A[i-1]){
            swap(A[i],A[i-1]);
            i--;
        }
        A[i]=key;
    }
}
int main(){
    vector<int>A={3,1,5,2,4};
    insertionsort(A);
    for(auto it:A){
        cout<<it<<" ";
    }
    return 0;
}
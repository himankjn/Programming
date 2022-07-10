#include<iostream>
#include<vector>
using namespace std;

//Optimized bubble sort. return if no swap occur in one iteration
void bubble(vector<int>&A){
    int n=A.size();
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j]){
                flag=true;
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
        if(!flag)return;
    }
}
int main(){
    vector<int>A={3,1,5,2,4};
    bubble(A);
    for(auto it:A){
        cout<<it<<" ";
    }
    return 0;
}
#include<iostream>
using namespace std;
#include<vector>


void insertatend(vector<int>&arr,int temp){
    if(arr.empty()){arr.push_back(temp);return ;}

    if(arr[arr.size()-1]<=temp){
        arr.push_back(temp);
        return;
    }

    int x=arr[arr.size()-1];
    arr.pop_back();
    insertatend(arr,temp);
    arr.push_back(x);
}
void sort(vector<int>&arr,int n){
    if(arr.size()==1)return;
    int temp=arr[arr.size()-1];
    arr.pop_back();
    sort(arr,n-1);
    insertatend(arr,temp);
}
int main(){
    vector<int>arr={2,1,4,3};
    int n=arr.size();
    sort(arr,n);
    for(auto it:arr){
        cout<<it<< " ";
    }
    return 0;
}
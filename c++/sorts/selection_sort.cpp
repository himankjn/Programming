#include<iostream>
#include<vector>
using namespace std;

void selectionsort(vector<int>&A){
    int n=A.size();
    for(int i=0;i<n;i++){
        int minele=A[i];
        int mineleidx=i;
        for(int j=i;j<n;j++){
            if(A[j]<minele){
                minele=A[j];
                mineleidx=j;
            }
        }
        swap(A[i],A[mineleidx]);
    }

}
int main(){
    vector<int>A={3,1,5,2,4};
    selectionsort(A);
    for(auto it:A){
        cout<<it<<" ";
    }
    return 0;
}
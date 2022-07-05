//5, 1, 9, 2, 5, 1, 7

//store indexes instead of elements in stack.


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int>&arr){
    int n=arr.size();
    vector<int> fin(n,-1);
    stack<int>stk;
    for(int i=n-1;i>=0;i--){
        if(stk.empty()){
            fin[i]=-1;
        }
        else if(arr[i]>=arr[stk.top()]){
            while(!stk.empty() and arr[i]>=arr[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                fin[i]=-1;
            }
            else{
                fin[i]=stk.top();
            }
        }
        else if(arr[i]<arr[stk.top()]){
            fin[i]=stk.top();
        }
        stk.push(i);
    }
   
   
    return fin;
}


vector<int> nextSmaller(vector<int>&arr){
    int n=arr.size();
    vector<int> fin(n,-1);
    
    stack<int>stk;
    for(int i=n-1;i>=0;i--){
        if(stk.empty()){
            fin[i]=-1;
        }
        else if(arr[i]<=arr[stk.top()]){
            while(!stk.empty() and arr[i]<=arr[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                fin[i]=-1;
            }
            else{
                fin[i]=stk.top();
            }
        }
        else if(arr[i]>arr[stk.top()]){
            fin[i]=stk.top();
        }
        stk.push(i);
    }

    
    return fin;
}
int main(){

    vector<int>A={5, 1, 9, 2, 5, 1, 7};
    int n=A.size();

   
    vector<int>Ngreater= nextGreater(A);
    vector<int>Nsmaller=nextSmaller(A);
    

    for(int i=0;i<n;i++){
        if(Ngreater[i]!=-1 &&  Nsmaller[Ngreater[i]]!=-1)
            cout<<A[Nsmaller[Ngreater[i]]]<<" ";
        else
            cout<<-1<<" ";
        
 
  
    }



    return 0;
   
}
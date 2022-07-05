//given an array find the index of next greater element. if no next greater then -1
//brute force is O(n^2). stack is O(n)
// usually array question with two loops where second loop variable is dependent on first loop variable can be done using stack
//refer: https://www.youtube.com/watch?v=P1bAPZg5uaE&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=2

//ip: 5, 1, 9, 2, 5, 1, 7
//op: 2, 2,-1, 4, 6, 6, -1

//algo: Begin from right end. stack stores the bigger elements on right.
// if stack is empty ans[i]=-1
// if arr[i]>stk.top() keep popping 
// if(arr[i]<stk.top) ans[i]=stk.top()
//stk.push(arr[i])

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
        else if(arr[i]>stk.top()){
            while(!stk.empty() and arr[i]>stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                fin[i]=-1;
            }
            else{
                fin[i]=stk.top();
            }
        }
        else if(arr[i]<=stk.top()){
            fin[i]=stk.top();
        }
        stk.push(arr[i]);
    }

    return fin;
}
int main(){

    vector<int>A={5, 1, 9, 2, 5, 1, 7};
    vector<int>fin= nextGreater(A);

    for(auto it:fin){
        cout<<it<<" ";
    }

}
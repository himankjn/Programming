#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:


typedef struct node{
    int val;
    int lr;
    int rr;
    struct node* left;
    struct node* right;
    
    node(int lr_,int rr_,int val_){
        lr=lr_;
        rr=rr_;
        val=val_;
    }
    
}Node;

    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int>fin;
        Node* root=createsegtree(arr,0,n-1);
        
        for(int i=0;i<2*q;i+=2){
            int l=queries[i];
            int r=queries[i+1];
            
            fin.push_back(getsum(root,l-1,r-1));
        }
        return fin;
    }
    
    int getsum(Node* root,int l,int r){
        
        int lr=root->lr;
        int rr=root->rr;
        int val=root->val;
        
        //if required range is superset of given node range
        if(l<=lr and r>=rr){
            return root->val;
        }
        
        //the required range is completely outside the node range. ie. no intersection
        if(l>rr or r<lr){
            return 0;
        }
        
        //if there is intersection in node range and required range
        return getsum(root->left,l,r)+getsum(root->right,l,r);
    }
    
    Node* createsegtree(int arr[],int low,int high){
        if(low==high){
            return new node(low,high,arr[low]);
        }
        
        int mid=(low+high)/2;
        
        Node* left=createsegtree(arr,low,mid);
        Node* right=createsegtree(arr,mid+1,high);
        
        Node* root=new node(low,high,left->val+right->val);
        root->left=left;
        root->right=right;
        return root;
        
    }
};

// { Driver Code Starts.

int main(){
    int n=4, q=2;
    int arr[n]={1, 2, 3, 4};
    int queries[2*q]={1, 4, 2, 3};
    
    
    Solution ob;
    vector<int> ans = ob.querySum(n, arr, q, queries);
    for(int u: ans)
        cout<<u<<" ";
    cout<<endl;
    return 0;
} 
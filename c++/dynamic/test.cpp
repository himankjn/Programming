// C++ program to find minimum 
// number of denominations 
#include <bits/stdc++.h> 
using namespace std; 
  
// All denominations of Indian Currency 
int deno[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} ;
int n = sizeof(deno) / sizeof(deno[0]); 
  
void findMin(int V) 
{ 
    sort(deno, deno + n); 
  
    // Initialize result 
    vector<int> ans; 
    ans.clear();
    // Traverse through all denomination 
    for (int i = n - 1; i >= 0; i--) { 
  
        // Find denominations 
        while (V >= deno[i]) { 
            V -= deno[i]; 
            ans.push_back(deno[i]); 
        } 
    } 
  
    // Print result 
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " "; 
} 
  
// Driver program 
int main() 
{ 
    int n[100],t;
    cin>>t;
    for(int i=0;i<t;i++){
    cin>>n[i];
    }
    for(int i=0;i<t;i++)
    findMin(n[i]); 
    

    
    return 0; 
} 
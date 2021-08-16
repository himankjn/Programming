//similar to dictionary in python. O(1) access


/* Unordered Map operations:

1) m[key]=val
2) for(auto it:m){
    key=it.first
    val=it.second
}
3) unordered_map<int> m+
4) unordered_map<int,unodered_map<int,int>>m   // hashmap of <key,hashmap> can be used to represent weighted graph edges adjacency list
5) unordered_map<int,vector<int>> m   //hashmap of <int,vector> can be used to represent unweighted edges adjacency list
6) unodered_set<int>   //set O(1) lookup
7) m.find(key) similar to .get in python
*/
#include<unordered_map>
#include<iostream>
#include<vector>

using namespace std;


int main(){

    unordered_map<int,int>m;
    m[1]=3;
    m[2]=10;

    for (auto it:m){
        cout<<it.first<<": "<<it.second<<endl;
    }

    if (m.find(10)==m.end()){
        cout<<"no key 10";
    }


    return 0;
}
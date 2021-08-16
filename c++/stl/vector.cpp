#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Vector operations

1) v.push_back()  //inserts at end
2) v.erase( iterator )  //deletes at pos
3) v.insert( iterator, ele)
4) v.insert(v.end(), v2.begin(),v2.end())   //adds elements from v2.begin() to v2.end() to v's end
5)reverse(v.begin(),v.end())
6)v.size()
7) v.clear()
8) count(v.begin(),v.end(),ele)
9) sort(v.begin(),v.end())

*/
int main(){
    vector<int> v;
    v.push_back(21);
    v.push_back(23);
    v.push_back(25);
    

    vector<int>v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.insert(v2.begin()+1,87);
   

   //concat v2 to v
    v.insert(v.end(),v2.begin(),v2.end());
    
    for (auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;

    v.erase(v.begin()+3);

    for (auto it:v){
        cout<<it<<" ";
    }

    reverse(v.begin(),v.end());
    v.clear();

       
    return 0;
}
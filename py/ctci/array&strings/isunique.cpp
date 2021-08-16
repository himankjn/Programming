#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

bool isUnique(string s){
    int n=s.size();
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++){
        string remaining=s.substr(0,i)+s.substr(i+1,n-1-i);
        char ch=s[i];
        if(binary_search(remaining.begin(),remaining.end(),ch)){
            return false;
        }
    }
    return true;
}
int main(){

string s="hello";
cout<<isUnique(s);

return 0;
}
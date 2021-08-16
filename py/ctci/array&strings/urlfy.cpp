#include<iostream>
using namespace std;

string urlfy(string s,int n,string x){
    string new_s;
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            new_s=new_s+s[i];
        }
        else{
            count+=3;
            new_s=new_s+"%20";
        }
    }
    return new_s;
}
int main(){

    string s="Mr John Smith";
    int n=13;
    string x="%20";
    cout<<urlfy(s,n,x);
}


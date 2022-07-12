#include<iostream>
#include<string>
#include<vector>
using namespace std;

void generate(string s,vector<string>&fin,string op){
    if(s.size()==0){
        fin.push_back(op);
        return;
    }

    generate(s.substr(0,s.size()-1),fin,op);
    generate(s.substr(0,s.size()-1),fin,s[s.size()-1]+op);
}
int main(){
    string s="abc";
    vector<string>fin;
    generate(s,fin,"");

    for(auto it:fin){
        cout<<it<<endl;
    }
    return 0;
}
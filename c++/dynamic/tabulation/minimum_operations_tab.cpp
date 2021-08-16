#include<iostream>
#include<vector>


using namespace std;


int min(int x,int y){
    return ((x<y)?x:y);
}

int min_op(int n){
    int op[n];
    op[0]=0;
    for(int i=1;i<=n;i++){
        if(i%2==0){//even i
        op[i]=min(op[i-1]+1, op[i/2]+1);
        }
        else
        {
            op[i]=min(op[(i-1)/2]+2, op[i-1]+1);
        }
        
    }
    return op[n];
}
    

int main(){
    int t; //testcases
    cin>>t;
    int a;
    while(t--){
    cin>>a;        
    cout<<min_op(a)<<endl;
    }
    return 0;
}

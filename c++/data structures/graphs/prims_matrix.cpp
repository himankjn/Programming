#include <iostream>
#include <vector>
#include<limits.h>
#include<cstring>
#include<algorithm>

using namespace std;


void prims(int a[][5]){//O(V^2)
    int sum=0;
    int min=INT_MAX,min_row,min_col;
    int visited[5];
    memset(visited,5,0);
    int V=5;
    int E=V-1;
    visited[0]=1;
    while(E--){     
        min=INT_MAX;
        
        for(int i =0;i<5;i++ ){
            for(int j=0;j<5;j++){//for every column
                if(visited[j]==1)continue;
                if(visited[i]==1){
                    if(a[i][j]<min){
                        
                        min=a[i][j];
                        min_row=i;
                        min_col=j;
                    }
                }
            }
        }
        visited[min_col]=1;
        sum+=min;
        printf("Edge selected is from %d to %d with weight %d ",min_row,min_col,min);
        cout<<endl;
        
    }
    cout<<sum<<endl;

}


int main(){
    int matrix[5][5] = {
        {INT_MAX, 1, 8, 1, 4},
        {1, INT_MAX, 12, 4, 9},
        {8, 12, INT_MAX, 7, 3},
        {1, 4, 7, INT_MAX, 2},
        {4, 9, 3, 2, INT_MAX}
    };
    std::cout << "    a          b c d e" << std::endl;
    char ch = 'a';
    for(int i = 0; i < 5; i++){
        std::cout << ch++ << " : ";
        for(int j = 0; j < 5; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    
    prims(matrix);
    
    return 0;
}

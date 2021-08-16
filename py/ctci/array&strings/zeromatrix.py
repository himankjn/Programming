from __future__ import print_function
n=4
m=3

mat=[[1,2,3],
     [5,0,7],
     [8,9,10],
     [11,0,13]]


def zeromat(mat):
    
    for i in range(n):
        for j in range(m):

            if(mat[i][j]==0):
                mat[i][0]=0
                mat[0][j]=0
    for i in range(n):
        if(mat[i][0]==0):
            for j in range(m):
                mat[i][j]=0
    
    for j in range(m):
        if(mat[0][j]==0):
            for i in range(n):
                mat[i][j]=0
    
    for row in range(n):
        print()
        for col in range(m):
            print(mat[row][col],end=" ")

zeromat(mat)
#Longest common substring between two strings A and B
#Brute force is O(N*M*M) check every length substring in both m and n

#Dynamic programming O(N*M)

#We can do O(Nlog(N)) using robin karp and hashtable and binary search.
#Find L using binary search. start with L -> M->M/2->M/4....
#For every such L apply commonsubstr algo using robin karp and hash table which takes O(N+M)
# Therefore total = O((N+M)*LogM)

def match(A,i,B,j,L):
    if A[i:i+L]==B[j:j+L]:
        return True
    return False

def commonsubstr(A,B,L,q,table):

    #build table with substrings of A
    val=0
    for i in range(L):
        val=(val*2+int(A[i]))%q
    table[val]=table.get(val,[])+[0]


    for i in range(1,len(A)-L+1):
        j=i+L-1
        val=(val*2+int(A[j]))%q
        val=val-(pow(2,L)*int(A[i-1]))%q
        table[val]=table.get(val,[])+[i]

    #match substrings of B against the table entries
    val=0
    for i in range(L):
        val=(val*2+int(B[i]))%q

    if table.get(val,False):
        for idx in table[val]:
            if match(A,idx,B,0,L):
                return A[idx:idx+L]
    
    for i in range(1,len(B)-L):
        j=i+L-1
        val=(val*2+int(B[j]))%q
        val=val-(pow(2,L)*int(B[i-1]))%q
        if table.get(val,False):
            for idx in table[val]:
                if match(A,idx,B,i,L):
                    return A[idx:idx+L]

    return -1

def LCSubStr(A,B,q):
    n=len(A)
    m=len(B)
    #max substr length = min of two strings
    L=min(n,m)
    #prime q=1000 slots in hashtable.
  

    table={}
    x=commonsubstr(A,B,L,q,table)
    if x!=-1:
        return (len(x),x)
    start=0
    end=L
    
    while(start<end):
        mid=(start+end)//2
        table.clear()
        if commonsubstr(A,B,mid,q,table)!=-1:
            start=mid+1
        else:
            end=mid-1
    
    return (end,commonsubstr(A,B,end,q,table))
    
import random
import sys
import math

n=random.randint(0,40)
m=random.randint(0,40)
A=""
B=""

for i in range(m):
    A=A+str(random.randint(0,1))
for i in range(n):
    B=B+str(random.randint(0,1))

print(A,B)
q=pow(10,5)

table={}

ans=LCSubStr(A,B,q)
print(ans)

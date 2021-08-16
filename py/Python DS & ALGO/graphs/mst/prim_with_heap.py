#O((E+V)logV) since every edge we might do decrease key in worst case
from collections import defaultdict
import sys

class minheap:
    def __init__(self,A=[]):
        self.A=A
        self.size=len(self.A)
        self.pos={}
        for i in range(len(A)):
            self.pos[self.A[i][1]]=i
        
    
    def swappos(self,a,b):
        self.pos[self.A[a][1]]=b
        self.pos[self.A[b][1]]=a

    def swapnode(self,a,b):
        temp=self.A[a]
        self.A[a]=self.A[b]
        self.A[b]=temp
    
    def heapify(self,idx):
        smallest=idx
        left=idx*2+1
        right=idx*2+2

        if(left < self.size and self.A[left][0]<self.A[smallest][0]):
            smallest=left
        if(right < self.size and self.A[right][0]<self.A[smallest][0]):
            smallest=right
        
        if(smallest!=idx):
            self.swappos(idx,smallest)
            self.swapnode(idx,smallest)

            self.heapify(smallest)

    def buildheap(self):
        n=self.size
        for i in range(n//2,-1,-1):
            self.heapify(i)
    
    def isempty(self):
        return self.size==0
    def decreasekey(self,x,newval):
        xpos=self.pos[x]
        self.A[xpos][0]=newval

        while(xpos>0 and self.A[xpos][0]<self.A[(xpos-1)//2][0]):
            self.swappos(xpos,(xpos-1)//2)
            self.swapnode(xpos,(xpos-1)//2)
            xpos=(xpos-1)//2

    def present(self,x):
        return self.pos[x]<self.size

    def extractmin(self):
        root=self.A[0]
        
        last=self.A[self.size-1]

        self.swappos(0,self.size-1)
        self.swapnode(0,self.size-1)

        self.size-=1
        self.heapify(0)
        return root


class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(dict)
    
    def addedge(self,src,dest,wt):
        self.edges[src][dest]=wt
        self.edges[dest][src]=wt
    
    def prims(self,src):
    
        dist=[[sys.maxsize,v] for v in self.V]
        dist=minheap(dist)
        dist.buildheap()
        totalweight=0
        dist.decreasekey(src,0)
        mst=[]#to stpre weights of mst
        parent={}#to keep track of parents of vertices in mst
     
        while(not dist.isempty()):  
            cur_dist,cur_v=dist.extractmin()
            totalweight+=cur_dist
            mst.append(cur_dist)

            for neighbour in self.edges[cur_v]:
                if(dist.present(neighbour) and self.edges[cur_v][neighbour]<dist.A[dist.pos[neighbour]][0]):
                    parent[neighbour]=cur_v
                    dist.decreasekey(neighbour,self.edges[cur_v][neighbour])
            
        for i in parent:
            print(parent[i],i,':',self.edges[parent[i]][i])
        print("total=",totalweight)

V=[0,1,2,3,4,5,6,7,8]     
G=Graph(V)
G.addedge(0, 1, 4)
G.addedge(0, 7, 8)
G.addedge(1, 2, 8)
G.addedge(1, 7, 11)
G.addedge(2, 3, 7)
G.addedge(2, 8, 2)
G.addedge(2, 5, 4)
G.addedge(3, 4, 9)
G.addedge(3, 5, 14)
G.addedge(4, 5, 10)
G.addedge(5, 6, 2)
G.addedge(6, 7, 1)
G.addedge(6, 8, 6)
G.addedge(7, 8, 7)

G.prims(0)

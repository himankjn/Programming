#O((E+V)logV)= O(ElogV)
# decrease key takes log(V) and its done for every edge(E+V)
#works for both directed and undirected graphs
import sys
from collections import defaultdict

class heapnode:
    def __init__(self,v,dist):
        self.v=v
        self.dist=dist
    def __str__(self):
        return str(self.v)+":"+str(self.dist)

# example A=[ heapnode("A",2),heapnode("B",3)]
class minheap:
    def __init__(self,A):
        self.A=A
        self.size=len(A)
        self.pos={}
        for i in range(len(A)):
            self.pos[A[i].v]=i
        
    #function to print heap contents easily
    def __str__(self):
        temp=[]
        for i in self.A:
            temp.append("V:"+str(i.v)+" dist:"+str(i.dist))
        return "\n".join(temp)       


        
    
    def swappos(self,a,b):
        self.pos[self.A[a].v]=b
        self.pos[self.A[b].v]=a
    def swapnode(self,a,b):
        temp=self.A[a]
        self.A[a]=self.A[b]
        self.A[b]=temp

    def heapify(self,idx):
        smallest=idx
        left=idx*2+1
        right=idx*2+2

        if(left<self.size and self.A[left].dist<self.A[smallest].dist):
            smallest=left
        if(right <self.size and self.A[right].dist<self.A[smallest].dist):
            smallest=right
        
        if(smallest!=idx):
            self.swappos(smallest,idx)
            self.swapnode(smallest,idx)
            
            self.heapify(smallest)


    def buildheap(self):
        n=self.size
        for i in range(n//2,-1,-1):
            self.heapify(i)

    #checks if node is in heap or deleted
    def presentinheap(self,x):
        return self.pos[x]<self.size

    def isempty(self):
        return self.size==0
    def extract_min(self):

        #the return value is stored
        finnode=self.A[0]

        root=0
        last=self.size-1

        #replace first and last node and delete last my reducing heapsize
        self.swappos(root,last)
        self.swapnode(root,last) 

        self.size-=1
        self.heapify(0)

        return finnode

    def decrease_key(self,v,newval):
        vpos=self.pos[v]
        
        self.A[vpos].dist=newval

        while(vpos>0 and self.A[vpos].dist < self.A[(vpos-1)//2].dist):
            self.swappos(vpos,(vpos-1)//2)
            self.swapnode(vpos,(vpos-1)/2)
            vpos=(vpos-1)//2




class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(dict)
    
    def addedge(self,src,dest,wt):
        self.edges[src][dest]=wt
        self.edges[dest][src]=wt
    
    def djikstra(self,src):
        #create a list of distances foor each vertex make it infinite
        #make heap of these dist
        #cecrease key src dist to 0
        #while heap is not empty keep updating(decrease key) distances of neighbours of min node in heap
        distances=[]
        for v in self.V:
            distances.append(heapnode(v,sys.maxsize))
        
        distances=minheap(distances)
        #optional buildheap as initially all are infinite so its already heap
        #distances.buildheap()

        distances.decrease_key(src,0)

        while(not distances.isempty()):
            g=distances.extract_min()
            cur_v,curdist=g.v,g.dist
            
            for neighbour in self.edges[cur_v]:
                #check if any neighbour has already been finalised. dont update it
                n_dist=distances.A[distances.pos[neighbour]].dist
                edge_dist=curdist+self.edges[cur_v][neighbour]
                if(edge_dist<n_dist):
                    distances.decrease_key(neighbour,edge_dist)
           
        return distances

"""#extra example

G=Graph(["S","A","B","C"])

G.addedge("S","A",4)
G.addedge("S","B",1)
G.addedge("B","A",1)
G.addedge("B","C",6)
G.addedge("A","C",4)
"""
G=Graph(range(0,9))
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
print(G.djikstra(0))
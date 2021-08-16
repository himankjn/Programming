#detect cycle in undirected graph using disjoint set in O(V log E)
#Note: we must only add edge to one of the vertex adjacency list even though graph is undirected
#Note: disjoint set cannot detect cycle in directed graph. as it only stores info of set and not direction.
from collections import defaultdict


class disjset:
    def __init__(self):
        self.rank={}
        self.parent={}
    
    def createset(self,x):
        if(self.parent.get(x,False)):
           return
        
        self.rank[x]=0
        self.parent[x]=x
        

    def findset(self,x):
        if(self.parent[x]==x):
            return x
        
        self.parent[x]=self.findset(self.parent[x])
        return self.parent[x]

    def union(self,x,y):
        xparent,yparent=self.findset(x),self.findset(y)
        if(xparent == yparent):
            return
        
        xrank,yrank=self.rank[xparent],self.rank[yparent]
        if(xrank<yrank):
            self.parent[xparent]=yparent
        elif(yrank<xrank):
            self.parent[yparent]=xparent
        else:
            self.parent[yparent]=xparent
            self.rank[xparent]+=1

class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(list)

    def addedge(self,src,dest):
        self.edges[src].append(dest)
    
    def containscycle(self):
        obj=disjset()
        for v in self.V:
            obj.createset(v)
            
           
        for a in self.V:
            for b in self.edges[a]:
                aset=obj.findset(a)
                bset=obj.findset(b)
                if(aset==bset):
                    return True
                obj.union(a,b)

        return False

V=[0,1,2,3]
G=Graph(V)
G.addedge(0,1)
G.addedge(1,2)
G.addedge(2,3)
#G.addedge(3,1)
print(G.containscycle())
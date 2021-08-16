#O(ElogE+ElogV)
# it takes O(ElogE) to sort E edges
# it takes O(ElogV) since in worst case for every edge we might do union operation which can take Log(V) in worst case
from collections import defaultdict

class disjointset:
    def __init__(self):
        self.rank={}
        self.parent={}
    
    def createset(self,v):
        self.rank[v]=0
        self.parent[v]=v
    
    def findset(self,v):
        if(self.parent[v]!=v):
            self.parent[v]=self.findset(self.parent[v])
        
        return self.parent[v]
    
    def union(self,x,y):
        xparent=self.parent[x]
        yparent=self.parent[y]

        if(xparent==yparent):
            return
        
        elif(self.rank[xparent]<self.rank[yparent]):
            self.parent[xparent]=self.parent[y]
        elif(self.rank[yparent]<self.rank[xparent]):
            self.parent[yparent]=self.parent[x]
        
        else:
            self.parent[yparent]=self.parent[x]
            self.rank[xparent]+=1


class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(dict)
    def addedge(self,src,dest,wt):
        self.edges[src][dest]=wt
    
    def kruskal(self):
        #sort all edges with weight and then add to mst while mst not full and cur_edge doesnt form cycle
        weights=[]
        mst=[]
        disj=disjointset()
        for v in self.V:
            disj.createset(v)
        

        for src,subdict in self.edges.items():
            for dest,wt in subdict.items():
                weights.append([src,dest,wt])

        weights.sort(key=lambda x:x[2])
        #for every edge if cycle doesnt form, include it in mst
        for i in weights:
            src=i[0]
            dest=i[1]
            #if same parent then this edge forms cycle. skip it.
            if(disj.findset(src)==disj.findset(dest)):
                continue
            mst.append(i)
            disj.union(src,dest)
            
        return mst

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

print(G.kruskal())
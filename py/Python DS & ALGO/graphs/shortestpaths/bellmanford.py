from collections import defaultdict
#O(V*(E+V)) = O(EV)
class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(dict)
    
    def addedge(self,src,dest,wt):
        self.edges[src][dest]=wt

    def bellmanford(self,src):
        distances={v:float("inf") for v in self.V}
        distances[src]=0

        for i in range(len(self.V)-1):
                #
                for u,d in self.edges.items():
                    for v,w in d.items():
                        if distances[u]+w < distances[v]:
                            distances[v]=distances[u]+w
                            


                
               
      
        for u,d in self.edges.items():
                    for v,w in d.items():
                        if  distances[u]+w < distances[v]:
                            print("negative cycle exists!")
                            return

        return distances
G=Graph([0,1,2,3,4])

G.addedge(0,1,-1)
G.addedge(0, 1, -1)
G.addedge(0, 2, 4)
G.addedge(1, 2, 3)
G.addedge(1, 3, 2)
G.addedge(1, 4, 2)
G.addedge(3, 2, 5)
G.addedge(3, 1, 1)
G.addedge(4, 3, -3)

print(G.bellmanford(0))
#O(E+V) to find shortest path between Two vertices
import sys
from collections import defaultdict

class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(dict)
    
    def addedge(self,src,dest,wt):
        self.edges[src][dest]=wt
        self.edges[dest][src]=wt
    
    
    def shortestpath(self,src,dest,visited):
        #base case
        if(src==dest):
            return 0

        #to avoid loops use visited to keep track of vertices in current dfs stack
        visited[src]=True

        min_val=sys.maxsize
        for u in self.edges[src]:
            if(not visited.get(u,False) and self.edges[src].get(u,False)):
                cur_dist=self.edges[src][u]+self.shortestpath(u,dest,visited)
                min_val=min(min_val,cur_dist)
        visited[src]=False
        return min_val
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

print(G.shortestpath(0,3,{}))
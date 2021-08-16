from collections import defaultdict

class Graph:
    def __init__(self):
        self.edges=defaultdict(list)

    def addedge(self,src,dest):
        self.edges[src].append(dest)

    
G=Graph()
G.addedge("a","b")
G.addedge("b","c")
G.addedge("c","a")

print(G.edges)
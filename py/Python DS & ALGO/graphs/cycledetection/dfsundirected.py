#O(V+E) simple dfs with modificaton

from collections import defaultdict
class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(list)
    
    def addedge(self,src,dest):
        self.edges[src].append(dest)
        self.edges[dest].append(src)
    
    def detectcycle(self):
        visited={}
        for v in self.V:
            parent=-1
            if(not visited.get(v,False)):
                if(self.detectcyclehelper(v,visited,parent)):
                    return True
        return False
    
    def detectcyclehelper(self,src,visited,parent):

        visited[src]=True
        for neighbour in self.edges[src]:
            if(visited.get(neighbour,False) and neighbour != parent):
                return True
            elif(not visited.get(neighbour,False) and self.detectcyclehelper(neighbour,visited,src)):
                return True
      


G=Graph([0,1,2])
G.addedge(0,1)
G.addedge(1,2)
G.addedge(2,0)


print(G.detectcycle())
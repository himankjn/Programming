#O(V+E) simple dfs with modificaton
from collections import defaultdict
class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(list)
    
    def addedge(self,src,dest):
        self.edges[src].append(dest)
    
    def detectcycle(self):
        visited=dict()
        recstack=dict() 
        for v in self.V:
            
            if self.detectcyclehelper(v,visited,recstack):
                return True
        return False
    def detectcyclehelper(self,src,visited,recstack):
        visited[src]=True
        recstack[src]=True
        for neighbour in self.edges[src]:
            
            if(visited.get(neighbour,False)  and recstack.get(neighbour,False)):
                return True
                
            elif(not visited.get(neighbour,False) and self.detectcyclehelper(neighbour,visited,recstack)):
                return True
        
        recstack[src]=False
        return False
            
  

G=Graph([0,1,2])
G.addedge(0,1)
G.addedge(1,2)
G.addedge(2,0)

print(G.detectcycle())
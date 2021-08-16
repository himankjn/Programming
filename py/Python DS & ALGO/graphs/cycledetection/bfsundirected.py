#O(V+E) simple dfs with modificaton
from collections import deque
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
        q=deque()
        parent={}
        for v in self.V:
            parent[v]=-1
        
        for v in self.V:
            if(not visited.get(v,False)):
                if(self.detectcyclehelper(v,visited,parent,q)):
                    return True
        return False
    
    def detectcyclehelper(self,startingV,visited,parent,q):
        q.append(startingV)
        visited[startingV]=True
        
        while(q):

            src=q.popleft()
            for neighbour in self.edges[src]:
                if(not visited.get(neighbour,False)):
                    visited[neighbour]=True
                    q.append(neighbour)
                    parent[neighbour]=src
                elif(visited.get(neighbour,False) and parent[src]!=neighbour):
                    return True

        return False

G=Graph([0,1,2])
G.addedge(0,1)
G.addedge(1,2)
G.addedge(2,0)

print(G.detectcycle())
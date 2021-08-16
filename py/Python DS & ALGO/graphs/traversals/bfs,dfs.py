from collections import deque
from collections import defaultdict
class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(list)

    def addedge(self,src,dest):
        self.edges[src].append(dest)

    def dfs(self,src):
        visited={}
        self.dfs_helper(src,visited)
        
    def dfs_helper(self,src,visited):
            visited[src]=True
            print(src)
            for adj in self.edges[src]:
                if(not visited.get(adj,False)):
                    self.dfs_helper(adj,visited)
        
    
    def bfs(self,src):
        q=deque()
        visited={}
        self.bfs_helper(src,visited,q)

    def bfs_helper(self,src,visited,q):
        visited[src]=True
        print(src)
        for adj in self.edges[src]:
            if(not visited.get(adj,False)):
                visited[adj]=True
                q.append(adj)
        
        while(q):
            self.bfs_helper(q.popleft(),visited,q)
G=Graph(4)
G.addedge("a","b")
G.addedge("b","c")
G.addedge("c","a")
G.addedge("d","c")
G.addedge("d","a")


G.bfs("d")

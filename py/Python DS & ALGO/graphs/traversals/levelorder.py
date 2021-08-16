#level order can be done either by bfs or dfs. just by using an extra hash table storing level of each node


from collections import defaultdict, deque


class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(list)

    def addedge(self,src,dest):
        self.edges[src].append(dest)

    def levelorder(self,src):
        #hash table to store levels
        level={}    
        self.bfs(src,level)

    def bfs(self,src,level):
        q=deque()
        visited={}

        visited[src]=True
        q.append(src)
        level[src]=0

        while(q):
            cur=q.popleft()
            for neighbour in self.edges[cur]:
                if not visited.get(neighbour,False):
                    visited[neighbour]=True
                    q.append(neighbour)
                    level[neighbour]=level[cur]+1
        print(level)
G=Graph(4)
G.addedge("a","b")
G.addedge("b","c")
G.addedge("c","a")
G.addedge("d","c")
G.addedge("d","a")


G.levelorder("d")
#undirecte graph shortest cycle using bfs
#just do cycle detection using bfs with every edge and keep min_len_cycle updated
from collections import defaultdict
from collections import deque
import sys
class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(list)
        self.min_cyclelen=sys.maxsize
    
    def addedge(self,src,dest):
        self.edges[src].append(dest)
        self.edges[dest].append(src)
    
    def shortest_cycle(self):
        for v in self.V:
            self.find_cycle(v)
        print(self.min_cyclelen)

    
    def find_cycle(self,src):
            dist={v:sys.maxsize for v in self.V}
            parent={v:-1 for v in self.V}
            visited={v:False for v in self.V}
            q=deque()

            dist[src]=0
            q.append(src)

            while(q):
                cur=q.popleft()
                for neigbhour in self.edges[cur]:
                    if(not visited[neigbhour]):
                        visited[neigbhour]=True
                        dist[neigbhour]=dist[cur]+1
                        parent[neigbhour]=cur
                        q.append(neigbhour)
                    elif(parent[cur]!=neigbhour and parent[neigbhour]!=cur):
                        self.min_cyclelen=min(self.min_cyclelen,dist[neigbhour]+dist[cur]+1)
            

            




V=[0,1,2,3,4,5,6]
G=Graph(V)

G.addedge(0, 6)
G.addedge(0, 5)
G.addedge(5, 1)
G.addedge(1, 6)
G.addedge(2, 6)
G.addedge(2, 3)
G.addedge(3, 4)
G.addedge(4, 1)

G.shortest_cycle()

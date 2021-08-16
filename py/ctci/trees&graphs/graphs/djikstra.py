#Single source shortest paths. Cannot detect negative weight cycles

from collections import defaultdict
import heapq
import sys



class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(dict)
        

    def addedge(self,src,dest,wt):
        self.edges[src][dest]=wt

# Time: O(E log(E))= O(E 2log(V)) 
# Space: O(E+V) as we are storing duplicate vertex distances in heap. since we didnt map node to index hence cant do decrease key
# check this for doubt: https://leetcode.com/problems/network-delay-time/discuss/329376/efficient-oe-log-v-python-dijkstra-min-heap-with-explanation

    def djikstra(self,src):
        
        distances={v:float("inf") for v in self.V}
        distances[src]=0
        
        visited=set()

        min_dist=[(0,src)]


        while(min_dist):
            cur_dist,cur=heapq.heappop(min_dist)
            if(cur in visited):
                continue
            visited.add(cur)

            for neighbour in self.edges[cur]:
                if neighbour in visited:
                    continue
                this_dist=cur_dist+self.edges[cur][neighbour]
                if(this_dist<distances[neighbour]):
                    distances[neighbour]=this_dist
                    heapq.heappush(min_dist,(this_dist,neighbour))

      
        return distances
    
        

G=Graph(["S","A","B","C"])

G.addedge("S","A",4)
G.addedge("S","B",1)
G.addedge("B","A",1)
G.addedge("B","C",6)
G.addedge("A","C",4)


print(G.djikstra("S"))  
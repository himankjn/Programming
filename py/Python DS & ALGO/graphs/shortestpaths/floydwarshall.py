#All pairs Shortest Paths
# O(VVV)
INF=float("inf")

class Graph:
    def __init__(self,E):
        self.edges=E
    

    def floydwarshall(self):
        n=len(self.edges)
        for i in range(n):
            for row in range(n):
                for col in range(n):
                    this_dist=self.edges[row][i]+self.edges[i][col]
                    if(this_dist<self.edges[row][col]):
                        self.edges[row][col]=this_dist
        
        return self.edges



E=[[0, 5, INF, 10],
         [INF, 0, 3, INF],
         [INF, INF, 0,   1],
         [INF, INF, INF, 0]
         ]
G=Graph(E)

print(G.floydwarshall())
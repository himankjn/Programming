#basically just dfs but after recursively doing dfs on neighbours add vertex to stack
from collections import defaultdict
class Graph:
    def __init__(self,V):
        self.V=V
        self.edges=defaultdict(list)
    
    def addedge(self,src,dest):
        self.edges[src].append(dest)
    
    def topologicalsort(self):
        s=[]
        visited={}
        v_stack={}
        for v in self.V:
            if not visited.get(v,False):
                if self.dfs(v,visited,s,v_stack):
                    return "cycle exists"
        
        return s[::-1]
    

    #simple dfs. works for dag but not for cyclic graph(gives wrong answer)
    """def dfs(self,src,visited,s):
            visited[src]=True
            for neighbour in self.edges[src]:
                if(not visited.get(neighbour,False)):
                    self.dfs(neighbour,visited,s)
            #basically dfs adjacent nodes and then backtrack adding to stack
            s.append(src)   
    """
    #in normal toplogical sort we mix cycle detection to ensure right answer in case of cyclic graph
    #below dfs also takes care if there are cycles and hence tells that no topological sort exists
    def dfs(self,src,visited,s,v_stack):
        visited[src]=True
        v_stack[src]=True

        for neighbour in self.edges[src]:
            if visited.get(neighbour,False) and v_stack.get(neighbour,False):
                return True
            if not visited.get(neighbour,False):
                if self.dfs(neighbour,visited,s,v_stack):
                    return True

        v_stack[src]=False
        s.append(src)
        return False

    """
    # using standard algo. remove 0 incoming edge vertices and delete their outgoing edges.
    #O(V+E)
    def topologicalsort(self):
        sorted_v=[]
        visited={}
        while len(sorted_v)!=len(self.V):
            if(self.topsort(sorted_v,visited)==-1):
                return "no toplogical sort. cycle exists"
        return sorted_v
    def topsort(self,sorted_v,visited):
        #O(V)
        cur_poss={v:False for v in self.V}
        #O(E)
        for src,sublist in self.edges.items():
            for dest in sublist:
                cur_poss[dest]=True
        #remaining cur_pos which are false have no incoming edges
        #O(V)
        poss=[v for v in self.V if cur_poss[v]==False and not visited.get(v,False)]
        if(not poss):
            #there is cycle since all vertices have incoming edges
            return -1

        for v in poss:
            self.edges[v]=[]
            visited[v]=True
            
        sorted_v.extend(poss)
        """


g=Graph([0,1,2,3,4,5])
g.addedge(5, 2)
g.addedge(5, 0)
g.addedge(4, 0)
g.addedge(4, 1)
g.addedge(2, 3)
#g.addedge(3,5)
g.addedge(3, 1)
print(g.topologicalsort())

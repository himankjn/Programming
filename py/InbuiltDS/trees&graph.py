from collections import defaultdict

class node:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None

class bst:
    def __init__(self):
        self.root=None
    

#Graphs

class Graph:
    def __init__(self):
        self.edges=defaultdict(dict)
        #for unweighted graphs: self.edges=defaultdict(list)
        
    
    def addedge(self,src,dest,wt):
        self.edges[src][dest]=wt
        #for undirected graphs. also exchange src,dest and add.
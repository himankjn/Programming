

#used in kruskal, undirected graph cyle detection
#amortized analysis shows create O(1)  find is O(1) after path compression  union is O(1)
class disjset:
    def __init__(self):
        self.rank={}
        self.parent={}

    def createset(self,x):
        if(self.parent.get(x,False)):
            print("Set already exists!")
            return

        self.rank[x]=0
        self.parent[x]=x

    def findset(self,x):

        if(x != self.parent[x]):
            self.parent[x]=self.findset(self.parent[x])

        return self.parent[x]
    
    def union(self,x,y):
        xparent=self.findset(x)
        yparent=self.findset(y)

        if(xparent==yparent):
            return 
        
        if(self.rank[xparent]<self.rank[yparent]):
            self.parent[xparent]=yparent
        elif(self.rank[yparent]<self.rank[xparent]):
            self.parent[yparent]=xparent
        
        else:
            self.parent[yparent]=xparent
            self.rank[xparent]+=1
        


obj=disjset()
obj.createset(0)
obj.createset(1)
obj.createset(2)
obj.createset(3)
obj.createset(4)

obj.union(0,2)
obj.union(2,4)
obj.union(1,3)

print(obj.findset(0))
print(obj.findset(2))
print(obj.findset(4))
print(obj.findset(1))
print(obj.findset(3))
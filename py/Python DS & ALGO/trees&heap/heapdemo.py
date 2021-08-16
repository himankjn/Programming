#we need extra dictionary of position for every node if want to implemet
# decrease key which is often used in djikstra, prim, etc.

class minheap:
    def __init__(self,V=[]):
        self.size=len(V)
        self.pos={}
        for i in range(len(V)):
            self.pos[V[i]]=i
        self.A=V

    def swap(self,a,b):
        
        temp=self.A[a]
        self.A[a]=self.A[b]
        self.A[b]=temp
        
       
    def heapify(self,idx):
       
        left=2*idx+1
        right=2*idx+2

        smallest=idx
        if(left<self.size and self.A[left]<self.A[smallest]):
            smallest=left
        if(right<self.size and self.A[right]<self.A[smallest]):
            smallest=right
        
        if(smallest!=idx):
            #swap smallest and idx(both Array and positions) and heapify smallest 
            self.swappos(idx,smallest)
            self.swapnode(idx,smallest)
            self.heapify(smallest)

            
    
    def swappos(self,a,b):
        self.pos[self.A[a]]=b
        self.pos[self.A[b]]=a
    
    def swapnode(self,idx,smallest):
        temp=self.A[idx]
        self.A[idx]=self.A[smallest]
        self.A[smallest]=temp

    def buildheap(self):
        n=self.size
        for i in range(n//2,-1,-1):
            self.heapify(i)

    def extractmin(self):
        if(self.size==0):
            return
        
        lastidx=self.size-1
        self.swappos(0,lastidx)
        self.swapnode(lastidx,0)
        self.size-=1
        self.heapify(0)
        return self.A[self.size]
    
    def decrease_key(self,v,dist):
        i=self.pos[v]

        self.A[i]=dist

        while(i>0 and self.A[i]<self.A[(i-1)//2]):
            #swap child and parent if parent is lower than child
            self.swappos(i,(i-1)//2)
            self.swapnode(i,(i-1)//2)
            #move up to parent
            i=(i-1)//2

    def insert(self,x):
        self.A.append(x)
        self.pos[x]=self.size

        i=self.size
        while(i>0 and self.A[i]<self.A[(i-1)//2]):
            self.swappos(i,(i-1)//2)
            self.swapnode(i,(i-1)//2)
            i=(i-1)//2


        self.size+=1
        
        
H=minheap([4,1,3,5,0,6])
H.buildheap()

print(H.A)
H.insert(2)
print(H.A)
class heap:
    def __init__(self,A=[]):
        self.size=len(A)
        self.A=A
        
    def swap(self,a,b):
        temp=self.A[a]
        self.A[a]=self.A[b]
        self.A[b]=temp
    
    def buildheap(self):
        n=self.size
        for i in range(n//2,-1,-1):
            self.min_heapify(i)

    def min_heapify(self,index):
        left=index*2+1
        right=index*2+2
        smallest=index

        if(left<self.size and self.A[left]<self.A[smallest]):
            smallest=left
        if(right<self.size and self.A[right]<self.A[smallest]):
            smallest=right
        
        if(smallest!=index):
            self.swap(smallest,index)
            self.min_heapify(smallest)

        
    def extract_min(self):
        last=self.size-1
        self.swap(0,last)
        min_ele=self.A[last]

        self.size-=1
        self.min_heapify(0)

        return min_ele
    def insert(self,ele):
        self.A.append(ele)
       
        child=self.size
        parent=(child-1)//2

        while(child!=0 and self.A[child]<self.A[parent]):
            self.swap(child,parent)
            child=parent
            parent=(child-1)//2

        self.size+=1

A=[200,100,30,20,5,10,15,1]
"""
H=heap(A)
print(H.size)

H.buildheap()
H.insert(8)
for i in range(H.size):
    print(H.extract_min())

"""

 
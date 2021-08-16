class sorts:
    def __init__(self,A):
        self.unchanged=A
        self.A=A
        self.len=len(A)
    
    def mergesort(self,l,r):
        if(l>=r):
            return
        mid=(l+r)//2
        self.mergesort(l,mid)
        self.mergesort(mid+1,r)
        self.merge(l,mid,r)
    def merge(self,l,mid,r):
        A1=self.A[l:mid+1]
        A2=self.A[mid+1:r+1]

        k=l
        i=j=0
        while(i<len(A1) and j<len(A2)):
            if(A1[i]<A2[j]):
                self.A[k]=A1[i]
                i+=1
                k+=1
            else:
                self.A[k]=A2[j]
                k+=1
                j+=1
        while i<len(A1):
            self.A[k]=A1[i]
            i+=1
            k+=1

        while j<len(A2):
            self.A[k]=A2[j]
            j+=1
            k+=1
    
    def quicksort(self,l,r):
        if(l>=r):
            return
        q=self.partition(l,r)
        self.quicksort(l,q-1)
        self.quicksort(q+1,r)
    
    def partition(self,l,r):
        pivot=self.A[r]
        q=l-1
        for i in range(l,r):
            if(self.A[i]<pivot):
                q+=1
                self.A[q],self.A[i]=self.A[i],self.A[q]
        
        self.A[q+1],self.A[r]=self.A[r],self.A[q+1]
        return q

    def insertion_sort(self):
        A=self.A
        for i in range(1,len(A)):
            k=i
            j=i-1
            while(j>=0):
                if(A[j]<A[k]):
                    break
                else:
                    A[j],A[k]=A[k],A[j]
                    j-=1
                    k-=1
        

    def selectionsort(self):
        A=self.A 
        for i in range(len(A)):
            min_idx=i
            k=i
            while(k<len(A)):
                if(A[k]<A[min_idx]):
                    min_idx=k
                k+=1

            A[i],A[min_idx]=A[min_idx],A[i]
    
            
    def bubblesort(self):
        A=self.A
        for _ in range(len(A)):
            flag=False
            i=0
            j=1
            while(j<len(A)):
                if(A[j]<A[i]):
                    flag=True
                    A[j],A[i]=A[i],A[j]
                i+=1
                j+=1
            if(flag is False):
                return
   


#just for heap sort
class heap:
    def __init__(self,A):
        self.A=A
        self.size=len(A)
        #no requirement of tracking pos as no decrease key required
    
    def heapify(self,idx):
        smallest=idx
        left=idx*2+1
        right=idx*2+2

        if(left<self.size and self.A[left]<self.A[smallest]):
            smallest=left
        if(right<self.size and self.A[right]<self.A[smallest]):
            smallest=right
        if(smallest!=idx):
            self.A[smallest],self.A[idx]=self.A[idx],self.A[smallest]
            self.heapify(smallest)

    def buildheap(self):
        n=self.size
        for i in range(n//2,-1,-1):
            self.heapify(i)
    
    def extractmin(self):
        root=self.A[0]

        self.A[self.size-1],self.A[0]=self.A[0],self.A[self.size-1]
        self.size-=1
        self.heapify(0)

        return root

    def heapsort(self):
        temp=[]
        n=self.size
        for i in range(n):
            temp.append(self.extractmin())
        
        self.A=temp
    
A=[4,1,2,5,3]
"""
s=sorts(A)
s.bubblesort()
print(A)
"""


h=heap(A)
h.buildheap()
h.heapsort()
print(h.A)
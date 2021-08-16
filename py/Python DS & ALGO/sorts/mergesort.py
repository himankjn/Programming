#O(nlog2N)

def mergesort(A,l,r):
    if(l>=r):
        return
    mid=(l+r)//2
    mergesort(A,l,mid)
    mergesort(A,mid+1,r)
    merge(A,l,mid,r)

def merge(A,l,mid,r):
    A1=A[l:mid+1]
    A2=A[mid+1:r+1]
    i=0
    j=0
    k=l

    while(i<len(A1)and j<len(A2)):
        if(A1[i]<A2[j]):
            A[k]=A1[i]
            i+=1
            k+=1
        else:
            A[k]=A2[j]
            j+=1
            k+=1
    while(i<len(A1)):
        A[k]=A1[i]
        k+=1
        i+=1
    while(j<len(A2)):
        A[k]=A2[j]
        k+=1
        j+=1



A=[3,1,4,2,7,6,5]
mergesort(A,0,len(A)-1)
print(A)
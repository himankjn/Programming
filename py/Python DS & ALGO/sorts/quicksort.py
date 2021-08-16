def quicksort(A,l,r):
    if(l>=r):
        return
    q=partition(A,l,r)
    quicksort(A,l,q-1)
    quicksort(A,q+1,r)

def swap(a,b):
    temp=a
    a=b
    b=temp
def partition(A,l,r):
    q=l-1
    pivot=A[r]
    for i in range(l,r):
        if(A[i]<pivot):
            q+=1
            A[i],A[q]=A[q],A[i]
    
    A[q+1],A[r]=A[r],A[q+1]
    return q

A=[4,3,1,2]
quicksort(A,0,3)
print(A)


    
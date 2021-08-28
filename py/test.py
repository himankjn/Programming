def findkth(arr1,arr2,k):
        m=len(arr1)
        n=len(arr2)
        if k==1:
            return min(arr1[0],arr2[0])
        
        if not arr1:
            return arr2[k-1]
        if not arr2:
            return arr1[k-1]

        idx=k//2-1


        if idx>=m:
            if(arr1[m-1]<arr2[idx]):
                return arr2[k-m-1]
            else:
                return findkth(arr1,arr2[k//2:],k-k//2)

        if idx>=n:
            if arr2[n-1]<arr1[idx]:
                return arr1[k-n-1]
            else:
                return findkth(arr1[k//2:],arr2,k-k//2)
        
        if arr1[idx]<arr2[idx]:
            return findkth(arr1[k//2:],arr2,k-k//2)
        else:
                return findkth(arr1,arr2[k//2:],k-k//2)


print(findkth([100,200],[72, 86, 113, 119, 265, 445, 892,1220],7))

nums=[50, 3, 10, 7, 40, 80]
L=[1]*len(nums)

for i in range(len(nums)):
    for j in range(i):
        if(nums[j]<nums[i]):
            L[i]=max(L[i],1+L[j])

max_el=1
for i in L:
    max_el=max(max_el,i)

print(max_el)   

        
import heapq

l=[4,1,2,3,8,0]
heapq.heapify(l)
print(l)
heapq.heappush(l,-1)
print(l)
heapq.heappop(l)
print(l)




#make heap of objects using class.
#define __lt__ less than method in class as heapq uses that

class node:
    def __init__(self,x,y,z):
        self.x=x
        self.y=y
        self.z=z
    def __lt__(self,other):
        #heapify based on second element
        return self.y<other.y
    
l=[node(1,2,3),node(1,1,3),node(1,2,2),node(2,1,3)]
heapq.heapify(l)
print(l)
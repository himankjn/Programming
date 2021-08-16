import heapq
from os import O_NDELAY

li=[5,7,9,4,3]

"""Min Heap


heapq.heapify(li)

while(li):
    print(li[0])
    heapq.heappop(li)
"""
## for maxheap just multplity each element by -1 and while poppoing again do same.
"""
li=map(lambda x:x*-1,li)
heapq.heapify(li)
while(li):
    print(-1*li[0])
    heapq.heappop(li)
"""



#min heap of nodes containing 3 elements where comparison(key) is made on middle element
class node():
    def __init__(self,one,two,three):
        self.one=one 
        self.two=two
        self.three=three
    def __str__(self):
        return "{},{},{}".format(self.one,self.two,self.three)

    def __lt__(self,other):
        if(self.two != other.two):
            return self.two<other.two 
        else:
            return self.one<other.one
triplets=[node(1,2,3),node(1,4,4),node(7,3,8),node(9,2,4),node(8,7,1)]

heapq.heapify(triplets)

while(triplets):    
    print(triplets[0])
    heapq.heappop(triplets)

from collections import deque

#deque: double ended queue. O(1) operations. implemented like double ended linkedlist

l=[1,2,3,4,5]
q=deque(l)

#enqueue from rear
q.append(10)
#deque from front
q.popleft()
# check if q empty
not q
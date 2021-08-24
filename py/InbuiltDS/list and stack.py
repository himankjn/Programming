#Lists can be used as normal arrays, stack, or collection of hetrogenous items.

#operations: 
# l.append() adds to end of l O(1)
# l.pop() pops from end of l O(1)
# l.insert(pos,ele)  O(n)
# l[:] list slicing, l[3:] everything from 4th element till end, l[:-2] everything except last 2 elements
# l2= l[:] to make deep copy. otherwise l2=l just gives alias
class stack:
    def __init__(self,maxsize):
        self.l=[]
        self.maxsize=maxsize
    
    def top(self):
        if self.l:
            return self.l[-1]
    def push(self,x):
        if len(self.l)==self.maxsize:
            print("stack full")
            return 
        self.l.append(x)
    
    def pop(self):
        if not self.l:
            print("empty stack")
            return
        temp=self.l[-1]
        self.l.pop()
        return temp
    def empty(self):
        return len(self.l)==0

s=stack(5)
s.push(10)
s.push(4)
s.push(3)
s.push(2)
s.push(1)
#s.push(100)
s.pop()

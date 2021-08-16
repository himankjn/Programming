from collections import deque

class AnimalQ:
    def __init__(self):
        self.dogq=deque()
        self.catq=deque()
        self.timestamp=0

    def enqueuecat(self,cat):
        self.catq.append((cat,self.timestamp))
        self.timestamp+=1
    
    def enqueuedog(self,dog):
        self.dogq.append((dog,self.timestamp))
        self.timestamp+=1
    
    def dequeany(self):
        if(self.dogq and self.catq):
            if(self.dogq[0][1]< self.catq[0][1]):
                print(self.dogq.popleft())
        
            else:
                print(self.catq.popleft())
        
        elif(self.dogq):
            print(self.dogq.popleft())
        elif(self.catq):
            print(self.catq.popleft())

        else:
            print("no dogs or cats available :(")
    
    def dequecat(self):
        if(self.catq):
            print(self.catq.popleft())
        else:
            print("no cats available :(")
    
    def dequedog(self):
        if(self.dogq):
            print(self.dogq.popleft())
        else:
            print("no dogs available :(")

q=AnimalQ()
q.enqueuecat(("cat1"))
q.enqueuecat(("cat2"))
q.enqueuedog(("dog1"))
q.enqueuedog(("dog2"))
q.enqueuecat(("cat3"))
q.dequeany()
q.dequecat()
q.dequecat()
q.dequedog()
q.dequecat()
class stack():
    def __init__(self):
        self.A=[0]*10
        self.top=-1
        self.capacity=10
    
    def push(self,ele):
        if(self.top==self.capacity-1):
            print("stack full. cannot push anymore")
            return False
        else:
            self.top+=1
            self.A[self.top]=ele
            return True

    def pop(self):
        if(self.top==-1):
            print("stack empty")
            return
        else:
            temp=self.A[self.top]
            self.top-=1
            return temp
    def empty(self):
        if(self.top==-1):
            return True
        return False

class queue:
    def __init__(self):
        self.s1=stack()
        self.s2=stack()
        self.size=0
    
    def enqueue(self,ele):
       if(self.s1.push(ele)):
           self.size+=1
           print("enqueued element : "+str(ele))
       
    
    def dequeue(self):
        if(not self.s2.empty()):
            print("dequeued ele: "+str(self.s2.pop()) )
            self.size-=1
        else:
            while(not self.s1.empty()):
                self.s2.push(self.s1.pop())
            if(self.s2.empty()):
                print("queue empty. cannot dequeue")
            else:
                print("dequeued ele: "+str(self.s2.pop()))
                self.size-=1


q=queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.dequeue()
q.dequeue()
q.enqueue(4)
q.enqueue(5)
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()
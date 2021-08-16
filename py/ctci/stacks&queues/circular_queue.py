
## we can use inbuilt deque from collections module in python.

class queue:
    def __init__(self,capacity=5):
        self.A=[0]*capacity
        self.capacity=capacity
        self.size=0
        self.front=0
        self.rear=0
    
    #boundary cond: 
        # front==rear means queue empty
        # (rear+1)%capacity==front means queue full
        # increment both front and rear by 1 and %capacity
    def enqueue(self,ele):
        if((self.rear+1)%self.capacity==self.front):
                print("queue full!")
                return
        self.rear=(self.rear+1)%self.capacity
        self.A[self.rear]=ele
        print("inserted: "+str(ele))
    
    def dequeue(self):
        if(self.front==self.rear):
            print("queue empty")
            return
        
        self.front=(self.front+1)%self.capacity
        print("deleted ele: "+str(self.A[self.front]))

    def peek(self):
        if(self.front==self.rear):
            print("queue empty")
            return
        print("element at front of queue: "+str(self.A[(self.front+1)%self.capacity]))

q=queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.dequeue()
q.dequeue()
q.dequeue()
q.enqueue(5)
q.enqueue(6)
q.enqueue(7)
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()

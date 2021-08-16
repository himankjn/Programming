class queue:
    def __init__(self,capacity):
        self.capacity=capacity
        self.front=-1
        self.rear=-1
        self.Q=[None for i in range(capacity)]

    def enqueue(self,data):
        #initial element
        if(self.front==-1 and self.rear==-1):
            self.front=0
            self.rear=0
            self.Q[self.rear]=data

        # full when rear+1 % capacity = front
        elif((self.rear+1)%self.capacity== self.front):
            print("Queue full")
            
        else:
            self.rear= (self.rear+1)%self.capacity
            self.Q[self.rear]=data

    def dequeue(self):
        if(self.front==-1 and self.rear==-1):
            print("Empty queue")
        elif(self.front ==self.rear):
            print("element popped=",self.Q[self.front])
            self.front=-1
            self.rear=-1
        else:
            print("element popped:",self.Q[self.front])
            self.front=(self.front+1)%self.capacity



myq=queue(4)

myq.enqueue(1)
myq.enqueue(2)
myq.enqueue(3)
myq.enqueue(4)
myq.dequeue()

myq.dequeue()
myq.dequeue()
myq.dequeue()
myq.dequeue()
myq.enqueue(1)
myq.enqueue(2)
myq.enqueue(3)
myq.enqueue(4)
myq.dequeue()
class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class queue:
    def __init__(self,capacity):
        self.count=0
        self.capacity=capacity
        self.front=None
        self.rear=None

    def enqueue(self,data):
        if(self.count==self.capacity):
            print("Queue FULL")
        elif(self.count==0):
            temp=node(data)
            self.front=temp
            self.rear=temp
            self.count+=1
        else:
            temp=node(data)
            self.rear.next=temp
            self.rear=temp
            self.count+=1

    def dequeue(self):
        if(self.count==0):
            print("Queue Empty")
        else:
            print("Dequeued Element:",self.front.data)
            self.front=self.front.next
            self.count-=1



myqueue=queue(3)
myqueue.dequeue()
myqueue.enqueue(1)
myqueue.enqueue(2)
myqueue.enqueue(3)
myqueue.enqueue(4)
myqueue.dequeue()
myqueue.dequeue()
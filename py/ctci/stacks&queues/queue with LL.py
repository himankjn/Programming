class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None

class queue:
    def __init__(self,capacity=10):
        self.front=None
        self.rear=None
        self.size=0
        self.capacity=capacity
    
    #front  ------------ rear
    def enqueue(self,ele):
        if(self.size==self.capacity):
            print("Queue full. max limit= "+str(self.capacity))
            return
        
        temp=Node(ele)
        if(not self.rear):
            self.front=self.rear=temp
        else:
            self.rear.next=temp
            temp.prev=self.rear
            self.rear=temp

        self.size+=1
    
    def dequeue(self):
        if(not self.front):
            print("Queue empty!")
            return
        
        if(self.front==self.rear):
            #if only one node in queue
            self.front=self.rear=None
        else:  
            self.front=self.front.next 
            self.front.prev=None
                
        self.size-=1
    
    def peek(self):
        if(self.size==0):
            print("empty Queue")
            return
        print(self.front.data)
    
        

q=queue()
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)
q.enqueue(6)
q.peek()
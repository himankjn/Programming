class stack:
    def __init__(self,capacity=10):
        self.A=[0]*capacity
        self.top=-1
        self.capacity=capacity
        
    def push(self,ele):
        if self.top!=(self.capacity-1):
            self.top+=1
            self.A[self.top]=ele
        else:
            print("stack full")
    def pop(self):
        if(self.top==-1):
            print("stack empty")
        else:
            temp=self.A[self.top]
            print("popped: "+ str(temp))
            self.top-=1
            return temp
    
    def empty(self):
        if(self.top==-1):
            return True
        return False
    def peek(self):
        return self.A[self.top]

    def print_all(self):
        while(self.top!=-1):
            print(self.pop())

    def sortstack(self):
        s2=stack()
        while(not self.empty()):
            temp=self.pop()
            print("first stack's top is:" + str(temp))
            while(not s2.empty() and temp>s2.peek()):
                self.push(s2.pop())
            s2.push(temp)
            print("pushed "+ str(temp)+ "to to stack 2")

        s2.print_all()



    
s=stack()
s.push(7)
s.push(9)
s.push(8)
s.push(2)
s.push(6)
s.push(1)
s.push(5)

s.sortstack()

s.print_all()

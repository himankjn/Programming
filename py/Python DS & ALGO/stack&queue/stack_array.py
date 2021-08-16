class stack:
    
    def __init__(self,capacity):
        self.st=[]
        self.capacity=capacity
        self.count=0
        self.top=-1


    def peek(self):
        if(self.top==-1):
            print("stack empty")
            return
        print(self.st[self.top])

    def push(self,data):
        if(self.count==self.capacity):
            print("stack fulL")
            return
        self.st.append(data)
        self.count+=1
        self.top+=1
        

    def pop(self):
        if(self.top==-1):
            print("stack empty")
            return
        del(self.st[0])
        self.top-=1
        

    def display(self):
        if(self.top==-1):
            print("stack empty")
            return
        for i in range(len(self.st)):
            print(self.st[i])
    
    
    

    
s=stack(5)
s.display()
s.pop()
s.push(3)
s.push(4)
s.display()
s.pop()
s.display()
s.push(1)
s.push(2)
s.push(4)
s.display()
s.push(8)
s.display()


        
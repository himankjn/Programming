
class stack():
    
    def __init__(self,capacity):
        self.A=[0]*capacity
        self.capacity=capacity
        self.top=-1
    
    def isempty(self):
        if(self.top==-1):
            return True
        else:
            return False

    def isfull(self):
        if(self.top==self.capacity-1):
            return True
        else:
            return False
    
    def push(self,ele):
        if(self.top==self.capacity-1):
            print("stackfull")
            return
        else:
            self.top+=1
            self.A[self.top]=ele
            print("pushed into stack :",ele)

    def  pop(self):
        if(self.top==-1):
            print("stack empty")
            return
        else:
            print("popped ele: ",self.A[self.top])
            self.top-=1
    
class setofstacks:

    def __init__(self,capacity):
        temp=stack(capacity)
        self.capacity=capacity
        self.stacks=[temp]
   
    def push(self,ele):
        if(self.stacks[-1].isfull()):
            print("added new stack")
            temp=stack(self.capacity)
            self.stacks.append(temp)
            self.stacks[-1].push(ele)
        else:
            self.stacks[-1].push(ele)

    def pop(self):
        
        if(self.stacks[-1].isempty()):
            
            if(len(self.stacks)==1):
                print("all stacks empty")
                return
            else:
                print("popped a stack")
                self.stacks.pop(-1)
        
        self.stacks[-1].pop()
    def popAt(self,i):
        if(len(self.stacks)<=i or i<0):
            print("index out of range. number of stacks are fewer")
        elif(i==len(self.stacks)-1):
            self.pop()
        else:
            self.stacks[i].pop()
            n=len(self.stacks)
            #rollover
            

            self.stacks[i].push(self.stacks[i+1].A[0])

            i=i+1
            while(i<n-1):
                print("moved one ele from stack "+str(i+1)+"to"+str(i))
                temp=self.stacks[i].A
                self.stacks[i].A=temp[1:]
                self.stacks[i].A.append(self.stacks[i+1].A[0])
                i+=1
            

            # i is now last stack in stacks
            #making last stack move to one left
            temp=self.stacks[i].A
            self.stacks[i].A=temp[1:]
            self.stacks[i].top-=1

            #if last stack now has no elements. pop it
            if(self.stacks[i].top==-1):
                self.stacks.pop(-1)
                        
            

ss=setofstacks(3)#capacity of each stack is 3

for i in range(10,130,10):
    ss.push(i)


ss.popAt(1)
ss.pop()
ss.pop()
ss.pop()
ss.pop()
ss.pop()
ss.pop()
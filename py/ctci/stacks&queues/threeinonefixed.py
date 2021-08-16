from __future__ import print_function
class stack:
    def __init__(self,A,start,end):
        self.A=A
        self.end=end 
        self.start=start 
        self.top=start-1

    def push(self,ele):
        if self.top<self.end:
            self.top+=1
            A[self.top]=ele
        else:
            print("stack full")
    def pop(self):
        if(self.top<self.start):
            print("stack empty")
        else:
            self.top-=1
    def print_all(self):
        if(self.top<self.start):
            print("stack empty")
        else:
            k=self.start
            while(k<=self.top):
                print(A[k],end=" ")
                k+=1
A=[0]*10
n=10
s1=stack(A,0,(n//3)-1)
s2=stack(A,n//3,(2*n//3)-1)
s3=stack(A,2*n/3,n-1)

s1.push(2)
s1.push(3)
s1.push(4)


s2.push(1)
s2.push(2)
s2.push(3)


s1.pop()
s1.print_all()
s1.push(4)
s1.print_all()
s1.pop()
s1.pop()
s1.pop()



s1.pop()
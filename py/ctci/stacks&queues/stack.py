from __future__ import print_function
import sys
class stack:
    def __init__(self,top=-1,capacity=5):
        self.min=sys.maxint
        self.A=[0]*capacity
        self.top=top
        self.capacity=capacity
        
    def push(self,ele):
        if(ele<self.min):
            self.min=ele
        if self.top!=(self.capacity-1):
            self.top+=1
            self.A[self.top]=[ele,self.min]
        else:
            print("stack full")
    def pop(self):
        if(self.top==-1):
            print("stack empty")
        elif(self.top==0):
            self.min=sys.maxint
            self.top-=1
        else:
            self.top-=1
    def peek(self):
        if(self.top==-1):
            print("stack empty")
        else:
            print(self.A[self.top][0])
    def show_min(self):
        if(self.top==-1):
            print("stack empty")
        else:
            print(self.A[self.top][1])

s1=stack()
s1.push(11)
s1.push(4)
s1.push(24)
s1.push(1)
s1.push(23)

s1.show_min()
s1.pop()
s1.pop()
s1.show_min()
s1.pop()
s1.pop()
s1.pop()
s1.show_min()
s1.push(2220)
s1.show_min()


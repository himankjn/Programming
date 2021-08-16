from __future__ import print_function
from copy import deepcopy


class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class nextcal():# class for rec pallindrome
        def __init__(self,node,res):
            self.node=node
            self.res=res

class LinkedList():
    def __init__(self):
        self.head=None
        self.size=0


    
    def print_all(self):
        if(not self.head):
            print("empty LL")

        temp=self.head
        while(temp != None):
            if(temp.next==None):
                print(temp.data)
            else:
                print(temp.data,end="->")
            temp=temp.next

    def insert(self,x,pos=0):
    
        if(pos>self.size):
            print("position invalid")
            return

        temp=Node(x)

        if(pos==0):
            temp.next=self.head
            self.head=temp
            self.size+=1
            return
        
        elif(pos==self.size):
            cur=self.head
            while(cur.next is not None):
                cur=cur.next
            cur.next=temp
       

        else:
            count=1
            prev=self.head
            next=prev.next
            while(count<pos):
                prev=next
                next=next.next
                count+=1
        
            prev.next=temp
            temp.next=next
            
        
        self.size+=1

    def delete(self,x):
        temp=self.head
        if(temp.data==x): #delete first node
            self.head=temp.next
            self.size-=1
            return
        
        prev=temp   
        next=temp.next

        while(next is not None and next.data!=x): #posx
            prev=next
            next=next.next
        
        if(next is None):
            
            prev.next=None
            self.size-=1
            return
        else:
    
            prev.next=prev.next.next
            next.next=None
            
            self.size-=1
            return   
    def runner(self):
        if(self.size%2==1):
            print("odd length. cannot execute runner on odd length chain")
            return
        p1=self.head
        p2=self.head
        
        while(p1 is not None):
            p1=p1.next.next
            p2=p2.next
        p1=self.head
    

        while(p2 is not None):
            t1=deepcopy(p1)
            t2=deepcopy(p2)
            if(p2.next is None):
                p1.next=p2
                p2.next=None
                return
            
            
            p1.next=p2
            p2.next=t1.next
            
            #p1=3
            #p2=4
            p1=t1.next
            p2=t2.next

        print(self.head.next.data)

    def remove_dup(self):
        cur=self.head
        prev=self.head
        freq={}
        while(cur is not None):
            if(cur.data not in freq):
                freq[cur.data]=1
                prev=cur
                cur=cur.next
            else:
                self.size-=1
                cur=cur.next
                prev.next=cur


    def kthtolast(self,k):
        if(k>self.size or k<1):
            print("not enough elements.k is too large")
            return
        pos=self.size-k
        count=0
        cur=self.head
        while(count<pos):
            cur=cur.next
            count+=1
        print(cur.data)

    def recursivekthlast(self,k):
        if(k>self.size or k<1):
            print("k invalid")
            return
        if(k==self.size):
            return self.head
        return  self.recursivekthlast(k+1).next
    
    def partition(self,k):
        left=self.head
        running=self.head

        while(running is not None):
            if(running.data<k):
                temp=left.data
                left.data=running.data
                running.data=temp   
                left=left.next
                running=running.next
            else:
                running=running.next

    def sumlist(self,l2):
        cur1=self.head
        cur2=l2.head
      

        num1=0
        num2=0

        exp=0
        while(cur1 is not None):
            num1=cur1.data*(10**exp)+num1
            cur1=cur1.next
            exp+=1
        exp=0
        while(cur2 is not None):
            num2=cur2.data*(10**exp)+num2
            cur2=cur2.next
            exp+=1

        sumll=num1+num2

        l=LinkedList()
        pos=0
        while(sumll!=0):
            rem=sumll%10
            sumll=sumll//10
            l.insert(rem,pos)
            pos+=1

        l.print_all()

    def sumlistforw(self,l2):
        # 1->2->3
        # 3->3->5
        head1=self.head
        head2=l2.head

        sum1=0
        sum2=0

        while(head1 is not None):
            sum1=sum1*10+head1.data
            head1=head1.next
        
        while(head2 is not None):
            sum2=sum2*10+head2.data
            head2=head2.next
        
        fin=sum1+sum2
        print(fin)
        l=LinkedList()
        
        req=[]
        
        while(fin!=0):
            rem=fin%10
            fin=fin//10
            req.append(rem)
        req.reverse()
        for i in range(len(req)):
            l.insert(req[i],i)

        l.print_all()
   
    
    def sumllistwo(self,l2):
        head1=self.head
        head2=l2.head
        nums=[]
        # 716 592
        rest=0
        while(head1 is not None and head2 is not None):
            rem=(head1.data+head2.data+rest)%10
            rest=(head1.data+head2.data+rest)//10
            nums.append(rem)
            head1=head1.next
            head2=head2.next
       

        while(head1 is not None):
            rem=(head1.data+rest)%10
            rest=(head1.data+rest)//10
            nums.append(rest)
            head1=head1.next
        
        while(head2 is not None):
            rem=(head2.data+rest)%10
            rest=(head2.data+rest)//10
            nums.append(rest)
            head2=head2.next
        
        if(rest>0):
            nums.append(rest)

        l=LinkedList()
        
       
      
        for i in range(len(nums)):
            l.insert(nums[i],i)

        l.print_all()

    def sumlistrec(self,l2):
        #(l->5->9, 2->3->6->7) and sum(5->9, 3->6->7)?
        head1=self.head
        head2=l2.head

        head=self.recsum(head1,head2,0)

        l=LinkedList()
        l.head=head
        l.print_all()

    def recsum(self,head1,head2,rest):
        if(head1 is None and head2 is None and rest==0):
            return None
        elif(head1 is None and head2 is None):
            temp=Node(rest)
            return temp
        elif(head1 is None):
            rem=(head2.data+rest)%10
            rest=(head2.data+rest)//10
            temp=Node(rem)
            temp.next=self.recsum(None,head2.next,rest)
            return temp

        elif(head2 is None):
            rem=(head1.data+rest)%10
            rest=(head1.data+rest)//10
            temp=Node(rem)
            temp.next=self.recsum(head1.next,None,rest)
            return temp

        rem=(head1.data+head2.data+rest)%10
        rest=(head1.data+head2.data+rest)//10
        temp=Node(rem)
        temp.next=self.recsum(head1.next,head2.next,rest)
        return temp

    def pallindrome(self):
        head=self.head
        elem=[]
        while(head is not None):
            elem.append(head.data)
            head=head.next
        
        i=0
        j=len(elem)-1
        while(i<j):
            if(elem[i]!=elem[j]):
                return False
            i+=1
            j-=1
        return True

    def recursivepallindrome(self):
        head=self.head
        s1=[]
        s2=[]
        self.recpal(s1,s2,head)
        print(s1==s2)

    def recpal(self,s1,s2,head):
        if(head is None):
            return
        s1.append(head.data)
        self.recpal(s1,s2,head.next)
        s2.append(head.data)

        return s1,s2
    
    def recursivepal2(self):
        n=self.size
        head=self.head
        rest=self.recpal2(head,n)
        print(rest.res)
    

    def recpal2(self,head,n):
    
        if(n==0):#takes care of even length base case
            return nextcal(head,True)
        if(n==1):#takes care of odd length base case
            return nextcal(head.next,True) 
        
        rest=self.recpal2(head.next,n-2)
        
        if(rest.node is None or rest.res==False ):
            return rest #if not pallindrome in child call 
            #just keep forwarding the false result up the stack
            #the node.next doesnt matter. since bool value is false.


        if(rest.node.data==head.data):
            #if pallindrome satisfied in child call,
            #  forward true and the next node up the stack
            return nextcal(rest.node.next,True)
        else:
            return nextcal(rest.node.next,False)


    def intersect(self,l2):
        head1=self.head
        head2=l2.head
        while(head1.next is not None):
            head1=head1.next
        while(head2.next is not None):
            head2=head2.next
        
        if(head1!=head2):
            print("No intersection")
            return 
        else:
            head1=self.head
            head2=l2.head
            if(self.size>l2.size):
                bigger=head1
                smaller=head2
            else:
                bigger=head2
                smaller=head1
             
            extra_n=abs(self.size-l2.size)
            while(extra_n):
                bigger=bigger.next
                extra_n-=1
            
            #both chains(bigger,small) head to tail are now equal
            while(bigger != smaller):
                bigger=bigger.next
                smaller=smaller.next
            
            #the intersection start from node, bigger&smaller is pointing too
            while(bigger is not None):
                print(bigger.data)
                bigger=bigger.next

    def loopdetect(self):
        head=self.head
        seen={}
        while(True and head!=None):
            if head in seen:
                return head
                break
            seen[head]=1
            head=head.next
        
        return None

    def loopdetectnospace(self):
        head1=self.head
        head2=self.head
        while(True):
            if(head1 is None or head2 is None):
                return None
            head1=head1.next
            head2=head2.next.next
            if(head1==head2):
                return head1
        
    def reverse(self):
        cur=self.head
        prev=None
        next=None
        while(cur):
            next=cur.next
            cur.next=prev
            prev=cur
            cur=next
            
            
        self.head=prev

    def reverserec(self):
        head=self.head
        self.head=  self.rev(head)
    def rev(self,head):
        if(head.next is None):
            return head
        
        rest=self.rev(head.next)
        head.next.next=head
        head.next=None
        return rest

    def kthtolastrec(self,k):
        head=self.head
        res=self.kthtolastrechelp(head,k)
        print(res[0].data)

    def kthtolastrechelp(self,head,k):
        if(head.next is None):
            return head,k-1
        
        res=self.kthtolastrechelp(head.next,k)

        if(res[1]==0):
            return res[0],0
        
        return head,res[1]-1
        


l1=LinkedList()
l1.insert(1)
l1.insert(2,1)
l1.insert(7,2)
l1.insert(2,3)
l1.insert(1,4)

l1.recursivepal2()
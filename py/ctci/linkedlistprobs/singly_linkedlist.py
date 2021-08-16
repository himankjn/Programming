class node:
    def __init__(self,data):
        self.data=data
        self.next=None


ll=node(1)
ll.next=node(5)
print(ll.next.data)
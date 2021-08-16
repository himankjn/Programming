alphabet_size=26

class node:
    def __init__(self,val):
        self.val=val
        self.isleaf=False
        self.children={}
class trie:
    def __init__(self):
        self.root=node("*")
        
    def insert(self,s):
        cur=self.root

        for i in s:
            if(not cur.children.get(i,False)):
                cur.children[i]=node(i)
            
            
            
            #move on to next char
            cur=cur.children.get(i,False)
        
        cur.isleaf=True

    def search(self,s):

        cur=self.root

        for c in s:
            
            if(cur.children.get(c,False) is None):
                return False
            
            cur=cur.children.get(c,False)
        
        if(cur ==False):
            return False
        else:
             return True


T=trie()
T.insert("gg")
T.insert("g")
print(T.search("g"))


alphabet_size=26

class node:
    def __init__(self):
        self.isleaf=False
        self.children=[None]*alphabet_size
    
class trie:
    def __init__(self):
        self.root=node()
        
    def insert(self,s):
        cur=self.root

        for i in s:
            index=ord(i)-ord('a')
            
            #if next char not in tree add new node at that index
            if(cur.children[index] is None):
                cur.children[index]=node()
            
            #move on to next char
            cur=cur.children[index]
        
        cur.isleaf=True

    def search(self,s):

        cur=self.root

        for c in s:
            index=ord(c)-ord('a')
            if(cur.children[index] is None):
                return False
            
            cur=cur.children[index]
        
        return cur.isleaf


T=trie()
T.insert("gg")
T.insert("g")
print(T.search("g"))


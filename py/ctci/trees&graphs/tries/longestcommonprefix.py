alphabet_size=26

class node:
    def __init__(self,curchar="*"):
        self.curchar=curchar
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
                cur.children[index]=node(i)
            
            #move on to next char
            cur=cur.children[index]
        
        cur.isleaf=True

    def lcp(self):
        cur=self.root
        longest=""
        while(cur and not cur.isleaf and len(cur.children)-cur.children.count(None)==1):
            next=[i for i in cur.children if i is not None][0]
            cur=next
            longest=longest+cur.curchar

        return longest
    def search(self,s):

        cur=self.root

        for c in s:
            index=ord(c)-ord('a')
            if(cur.children[index] is None):
                return False
            
            cur=cur.children[index]
        
        return cur.isleaf


T=trie()
a=["code", "coder", "coding", "codable", "codec", "codecs", "coded",
        "codeless", "codependence", "codependency", "codependent",
        "codependents", "codes", "codesign", "codesigned", "codeveloped",
        "codeveloper", "codex", "codify", "codiscovered", "codrive"]
for s in a:
    T.insert(s)

print(T.lcp())

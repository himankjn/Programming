#find max occurence of a string in an array of strings.
#typical soln using two loops takes O(n^2* maxwordlength)
#using tries takes O(n*maxwordlength)

alphabet_size=26

class node:
    def __init__(self):
        self.isleaf=False
        self.children=[None]*alphabet_size
        self.count=0
    
class trie:
    def __init__(self):
        self.max_count=0
        self.root=node()
        self.maxoccur=""
        
    def insert(self,s):
        cur=self.root

        for i in s:
            index=ord(i)-ord('a')
            
            #if next char not in tree add new node at that index
            if(cur.children[index] is None):
                cur.children[index]=node()
            
            #move on to next char
            cur=cur.children[index]
        
        cur.leaf=True
        cur.count+=1
        if(cur.count>self.max_count):
            self.maxoccur=s
        self.max_count=max(self.max_count,cur.count)
        
        


    def search(self,s):

        cur=self.root

        for c in s:
            index=ord(c)-ord('a')
            if(cur.children[index] is None):
                return False
            
            cur=cur.children[index]
        
        return cur.isleaf


T=trie()

array= ["code", "coder", "coding", "codable", "codec", "codecs", "coded", "codeless", "codec", "codecs", "codependence", "codex", "codify", "codependents", "codes", "code", "coder", "codesign", "codec", "codeveloper", "codrive", "codec", "codecs", "codiscovered"]
for s in array:
    T.insert(s)

print(T.max_count,T.maxoccur)
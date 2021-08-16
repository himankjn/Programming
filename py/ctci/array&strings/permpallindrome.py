s="Tact Coa"

def pall(s):
    i=0
    j=len(s)-1
    while(i<j):
        if(s[i]!=s[j]):
            return False
        i+=1
        j-=1
    return True
def perm(s,prefix,l):
    if(s==""):
        l.append(prefix)
    
    for i in range(len(s)):
        main_char=s[i]
        remaining=s[0:i]+s[i+1:]
        perm(remaining,prefix+s[i],l)

def palperm(s):
    l=[]
    s=s.lower()
    s=''.join(s.split())
    perm(s,"",l)
    for i in l:
        if(pall(i)):
            return True
    
    return False



#more optimal

def palpermopt(s):
    s=s.lower()
    s=''.join(s.split())
    
    m={}
    for i in s:
        m[i]=m.get(i,0)+1
    
    odds=0
  
    for v in m.values():
        if(v%2==1):
            odds+=1

    if(odds>1):
       return False
    else:
        return True


print(palpermopt(s))
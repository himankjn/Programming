
s="abcef"

def permutations(s):
    l=[]
    perm(s,"",l)
    print(l)

def perm(s,prefix,l):
    if(s==""):
        l.append(prefix)
    
    for i in range(len(s)):
        remaning=s[0:i]+s[i+1:]
        perm(remaning,prefix+s[i],l)


permutations(s)


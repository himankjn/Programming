s1= "hello"
s2= "elhdo"

# O(n+m) time and space.

def perm(s1,s2):
    mp={}
    mp2={}
    for c in s1:
        mp[c]=mp.get(c,0)+1
    for c in s2:
        mp2[c]=mp2.get(c,0)+1
    
    if(mp2==mp):
        return True
    else:
        return False


print(perm(s1,s2))


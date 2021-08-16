
s1="waterbottle"
s2="erbottlewat"

def issubstring(s1,s2):
    if(s1 in s2):
        return True
    return False


def isrotation(s1,s2):
    s1=s1+s1
    print(issubstring(s2,s1))


isrotation(s2,s1)

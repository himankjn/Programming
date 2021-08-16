
s1="pale"
s2="peee"

def equalcheck(s1,s2):
    count=0
    for i in range(len(s1)):
        if(s1[i]!=s2[i]):
            count+=1
    if(count>1):
        return False
    return True

def unequalcheck(s1,s2):
    n1=len(s1)
    n2=len(s2)
    if(n1<n2):
        min_s=s1
        max_s=s2
    else:
        min_s=s2
        max_s=s1

    count=0

    for i in range(len(min_s)):
        if(min_s[i]==max_s[i+count]):
            continue
        else:
            if(min_s[i]==max_s[i+count+1]):
                count+=1
            else:
                return False

        
        
    if(count>1):
        return False
    return True


def oneaway(s1,s2):
    n1=len(s1)
    n2=len(s2)

    if(abs(n1-n2)>1):
        return False

    if(n1==n2):
        return equalcheck(s1,s2)
    else:
        return unequalcheck(s1,s2)

    
print(oneaway(s1,s2))
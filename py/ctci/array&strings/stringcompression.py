s="aabcccccaab"

def compress(s):
    i=0
    cur_count=1
    fin_s=""
    while(i<len(s)):

        
        if(i!=len(s)-1 and s[i]==s[i+1]):
            cur_count+=1
        else:
            fin_s+=s[i]+str(cur_count)
            cur_count=1
            
        i+=1

    if(len(fin_s)<len(s)): 
        return fin_s
    else:
        return s

print(compress(s))
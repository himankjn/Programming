
from bisect import bisect_left
import sys
def binary_s(a,x):
    i=bisect_left(a,x)
    if(i!=len(a) and a[i]==x):
        return True
    else:
        return False

s="hhelo"

s=''.join(sorted(s))
for i in range(len(s)):
    ch=s[i]
    remaining=s[0:i]+s[i+1:]
    
    if(binary_s(remaining,ch)):
        print("Not Unique")
        sys.exit()

print("Unique")
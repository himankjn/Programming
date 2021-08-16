def dectobin(n):
    if(n==1 or n==0):
        return n
    return dectobin(n//2)*10+n%2

print(dectobin(5))  
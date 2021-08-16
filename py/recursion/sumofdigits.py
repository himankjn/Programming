def sumofdigits(n):
    if(n==0):
        return 0
    return sumofdigits(n//10)+n%10

print(sumofdigits(523))
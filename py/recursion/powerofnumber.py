def power(x,n):
    assert int(n)==n, "exponent cannot be float"
    if n<0:
        return 1/power(x,abs(n))
    if x<0:
        if(n%2==0):
            return power(abs(x),n)
        else:
            return -power(abs(x),n)
    if(n==0):
        return 1
    return x*power(x,n-1)

print(power(-2,3.5))
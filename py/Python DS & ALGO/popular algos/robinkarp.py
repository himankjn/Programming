#string matching is a popular problem
# give string a,b find if b is a substring of a
#normal brute force would be O(n*m)
# Robin karp gives O(n). It essentially represents substring as an binary number/integer. which helps us compute the next sliding window in just O(1) using previous sliding window.
#if the string is english characters: replace the base 2 by base 26
#Algorthm: keep a sliding window and return true if match is found. The sliding window update takes only O(1) unlike O(m) in brute force case.

a="101010111010101100010"
b="1110"
#example: the first window= "1010"=10
#to compute second sliding window:  
#add next bit and update: 10101=  10*2+1= 21
#remove first bit and update=  21-1* pow(2,m)=5


def robinkarp(a,b):
    #get the value of b string
    n=len(a)
    m=len(b)
    
    target=0
    for c in b:
        if c=="0":
            target=target*2
        else:
            target=target*2+1
    
    window=0
    for i in range(m):
        if a[i]=="0":
            window=window*2
        else:
            window=window*2+1
#now match target value with every sliding window
    if window==target:
            return True

    i=m
    pow2m=1<<m
    while(i<len(a)):
        window=window*2+int(a[i])- int(a[i-m])*pow2m
        if window==target:
            return True
        i+=1


    return False

print(robinkarp(a,b))
    
#Note: if the substring b is greater than 2^64 then we cant store it even in a float variable. Then we can use a modulo with a prime number. This technique is essentially hashing
# If the prime number is q. then prob of collision is (1/q). For n iterations, expected no. of collision = (n/q)
# each collision we check if match is there brute forces. Therefore total expected complexity= O(n * (n/q)) where (n/q) is almost constant for large q.
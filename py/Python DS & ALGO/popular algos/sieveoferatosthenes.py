#used to generate all prime numbers upto n
#create a bool array from 2 to n then for every number keep eliminating its multiples

def sieveoferatosthenes(n):
    primes={x:1 for x in range(2,n+1)}
    #denotes if number is prime from 0 to n.
    #initially all are prime.then we mark the nonprimes to 0

    cur=2
    while(cur*cur<len(primes)):
        if(primes[cur]==1):
            eliminate(primes,cur)
        cur+=1
    
    print(primes)

def eliminate(primes,x):
    #eliminate multiples of x starting from x*x since x*k for k<x is already marked by previous iterations
    for i in range(x*x,len(primes),x):
        primes[i]=0
    



sieveoferatosthenes(50)

#this can aslo be used to find prime factorization of a number.
#initialise the spf[i]=i for all number
#instead of marking primes just mark smallest prime factor of every number
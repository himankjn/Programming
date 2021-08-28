#Given two string a and b and a length L. find common substring of length L in a and b.
#Brute force will take L*N*M
#even with robin carp it will take O(N*M)
#Optimized robin karp with hash will give O(N+M)

#Algorithm:
#Store substrings hashes of both string and match.
#Store (hash value,idx) of all substrings of size L of A into a hash table using a large prime number and robin karp where idx is starting idx of substring
# hashvalu= substring % prime
# idx= starting idx of substring
# linked list/list for collision(separate chaining)

#Now for every substring of size L in b. check if its hashvalue matches to any in the stored table.
#If so match this substring and substring of A staring at index idx store at that hashvalue using robin karp.

#Note: on 64 bit machine we can take prime number q to be maximum 2^63
#that is the maximum no. of slots possible as long int value cannot store more than that.

#func used to match two strings. used in case of match in hash value.
def match(A,i,B,j,L):
    if A[i:i+L]==B[j:j+L]:
        return True
    return False

def commonsubstr(A,B,L,q,table):

    #build table with substrings of A
    val=0
    for i in range(L):
        val=(val*2+int(A[i]))%q
    table[val]=table.get(val,[])+[0]


    for i in range(1,len(A)-L+1):
        j=i+L-1
        val=(val*2+int(A[j]))%q
        val=val-(pow(2,L)*int(A[i-1]))%q
        table[val]=table.get(val,[])+[i]

    #match substrings of B against the table entries
    val=0
    for i in range(L):
        val=(val*2+int(B[i]))%q

    if table.get(val,False):
        for idx in table[val]:
            if match(A,idx,B,0,L):
                return A[idx:idx+L]
    
    for i in range(1,len(B)-L):
        j=i+L-1
        val=(val*2+int(B[j]))%q
        val=val-(pow(2,L)*int(B[i-1]))%q
        if table.get(val,False):
            for idx in table[val]:
                if match(A,idx,B,i,L):
                    return A[idx:idx+L]

    return -1

A="101010111010101100010"
B="110101011000"
L=12
#Let prime number q be 1000 here. but q can go upto 2^64 if we want. Since key can be a float and float can hold 2^64
table={}
q=1000
print(commonsubstr(A,B,L,q,table))
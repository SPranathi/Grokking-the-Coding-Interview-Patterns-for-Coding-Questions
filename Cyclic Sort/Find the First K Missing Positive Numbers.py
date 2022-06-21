"""
Problem Statement
Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.

Example 1:

Input: [3, -1, 4, 5, 5], k=3
Output: [1, 2, 6]
Explanation: The smallest missing positive numbers are 1, 2 and 6.

Example 2:

Input: [2, 3, 4], k=3
Output: [1, 5, 6]
Explanation: The smallest missing positive numbers are 1, 5 and 6. 

Time complexity #
The time complexity of the above algorithm is O(n+k), as the last two for loops will run for O(n) and O(k) times respectively.

Space complexity #
The algorithm needs O(k) space to store the extraNumbers.
""" 
def KMissing_numbers(l,k):
    i,n=0,len(l)
    while i<n:
        j=l[i]-1
        if l[i]>0 and l[i]<=n and l[i]!=l[j]:
            l[i],l[j]=l[j],l[i]
        else:
            i+=1
    
    missingnumbers=[]
    extranumbers=set()
    for i in range(n):
        if len(missingnumbers)<k:
            if l[i]!=i+1:
                missingnumbers.append(i+1)
                extranumbers.add(l[i])
    
    #add the remaining missing numbers
    i=1
    while len(missingnumbers)<k:
        num=i+n
        if num not in extranumbers:
            missingnumbers.append(num)
        i+=1
    return missingnumbers

def main():
    l=list(map(int,input().split()))
    k=int(input())
    print(KMissing_numbers(l,k))

main()
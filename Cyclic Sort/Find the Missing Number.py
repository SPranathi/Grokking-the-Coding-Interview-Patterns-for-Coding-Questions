"""
Problem Statement #
We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.

Example 1:

Input: [4, 0, 3, 1]
Output: 2
Example 2:

Input: [8, 3, 5, 2, 4, 6, 0, 1]
Output: 7

Time complexity #
The time complexity of the above algorithm is O(n). 

Space complexity #
The algorithm runs in constant space O(1).
""" 
def missing_num(l):
    i,n=0,len(l)
    while i<n:
        j=l[i]
        if l[i]<n and l[i]!=l[j]:
            l[i],l[j]=l[j],l[i]
        else:
            i+=1
        
    for i in range(n):
        if l[i]!=i:
            return i
    return n

def main():
    l=list(map(int,input().split()))
    print(missing_num(l))

main()
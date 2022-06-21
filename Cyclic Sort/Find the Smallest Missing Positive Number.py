"""
Problem statement
Given an unsorted array containing numbers, find the smallest missing positive number in it.

Example 1:

Input: [-3, 1, 5, 4, 2]
Output: 3
Explanation: The smallest missing positive number is '3'

Example 2:

Input: [3, -2, 0, 1, 2]
Output: 4 

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1).
""" 

def first_missing_num(l):
    i,n=0,len(l)
    while i<n:
        j=l[i]-1
        if l[i]>0 and l[i]<=n and l[i]!=l[j]:
            l[i],l[j]=l[j],l[i]
        else:
            i+=1

    for i in range(n):
        if l[i]!=i+1:
            return i+1
    return len(l)+1

def main():
    l=list(map(int,input().split()))
    print(first_missing_num(l))

main()
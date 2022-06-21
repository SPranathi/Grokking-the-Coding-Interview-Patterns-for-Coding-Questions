"""
Problem Statement #
We are given an unsorted array containing numbers taken from the range 1 to ‘n’. The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.

Example 1:

Input: [2, 3, 1, 8, 2, 3, 5, 1]
Output: 4, 6, 7
Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
Example 2:

Input: [2, 4, 1, 2]
Output: 3

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
Ignoring the space required for the output array, the algorithm runs in constant space O(1).
"""

def missing_numbers(l):
    i=0
    while i<len(l):
        j=l[i]-1
        if l[i]!=l[j]:
            l[i],l[j]=l[j],l[i]
        else:
            i+=1
    missingnumbers=[]
    for i in range(len(l)):
        if l[i]!=i+1:
            missingnumbers.append(i+1)
    return missingnumbers

def main():
    l=list(map(int,input().split()))
    print(missing_numbers(l))

main()
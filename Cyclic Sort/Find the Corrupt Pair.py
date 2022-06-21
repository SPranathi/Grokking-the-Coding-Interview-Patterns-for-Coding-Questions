"""
Problem statement#
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’.
The array originally contained all the numbers from 1 to ‘n’, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing.
Find both these numbers.

Example 1:

Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.
Example 2:

Input: [3, 1, 2, 3, 6, 4]
Output: [3, 5]
Explanation: '3' is duplicated and '5' is missing. 

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1).
""" 

def corrupt_numbers(l):
    i=0
    while i<len(l):
        j=l[i]-1
        if l[i]!=l[j]:
            l[i],l[j]=l[j],l[i]
        else:
            i+=1
    for i in range(len(l)):
        if l[i]!=i+1:
            return [l[i],i+1]
    return [-1,-1]

def main():
    l=list(map(int,input().split()))
    print(corrupt_numbers(l))

main()
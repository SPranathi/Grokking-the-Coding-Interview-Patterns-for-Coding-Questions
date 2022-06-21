"""
Problem Statement #
We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’. The array has only one duplicate but it can be repeated multiple times. Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.

Example 1:

Input: [1, 4, 4, 3, 2]
Output: 4
Example 2:

Input: [2, 1, 3, 3, 5, 4]
Output: 3

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1) but modifies the input array.

"""

def duplicate(l):
    i=0
    while i<len(l):
        if l[i]!=i+1:
            j=l[i]-1
            if l[i]!=l[j]:
                l[i],l[j]=l[j],l[i]
            else:
                return l[i]
        else:
            i+=1
    return -1

def main():
    l=list(map(int,input().split()))
    print(duplicate(l))

main() 

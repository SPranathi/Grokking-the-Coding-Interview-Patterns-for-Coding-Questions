"""
Problem Statement #
Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the new length of the array.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].

Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11]. 

Time Complexity #
The time complexity of the above algorithm will be O(N), where ‘N’ is the total number of elements in the given array.

Space Complexity #
The algorithm runs in constant space O(1).
"""

def remove_duplicates(l):
    #index of the next non-duplicate element
    next_non_duplicate=1

    i=1
    while(i<len(l)):
        if l[next_non_duplicate-1]!=l[i]:
            l[next_non_duplicate]=l[i]
            next_non_duplicate+=1
        i+=1
    return next_non_duplicate

def main():
    l=list(map(int,input().split()))
    print(remove_duplicates(l))

main()
"""
Problem Statement #
Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects,
hence, we can’t count 0s, 1s, and 2s to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; and
since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.

Example 1:

Input: [1, 0, 2, 1, 0]
Output: [0 0 1 1 2]

Example 2:

Input: [2, 2, 0, 1, 2, 0]
Output: [0 0 1 2 2 2 ] 

Time complexity #
The time complexity of the above algorithm will be O(N)O(N) as we are iterating the input array only once.

Space complexity #
The algorithm runs in constant space O(1)O(1).
"""

def dutch_flag(li):
    lo,hi,i=0,len(li)-1,0
    while i<=hi:
        if li[i]==0:
            li[i],li[lo]=li[lo],li[i]
            i+=1
            lo+=1
        elif li[i]==1:
            i+=1
        else:
            li[i],li[hi]=li[hi],li[i]
            #decrement 'high' only, after the swap the number at index i could be 0 or 1 or 2
            hi-=1
    

def main():
    li=list(map(int,input().split()))
    dutch_flag(li)
    print(li)

main()
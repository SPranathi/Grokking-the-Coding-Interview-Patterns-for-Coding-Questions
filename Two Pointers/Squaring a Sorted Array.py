"""
Problem Statement #
Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]

Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9] 

Time complexity #
The time complexity of the above algorithm will be O(N)O(N) as we are iterating the input array only once.

Space complexity #
The space complexity of the above algorithm will also be O(N)O(N); this space will be used for the output array.
"""

def makesquares(v):
    n=len(v)
    sq=[0]*n
    highestsquareidx=n-1
    l=0
    r=n-1
    while(l<=r):
        lsquare=v[l]*v[l]
        rsquare=v[r]*v[r]
        if(lsquare>rsquare):
            sq[highestsquareidx]=lsquare
            l+=1
        else:
            sq[highestsquareidx]=rsquare
            r-=1
        highestsquareidx-=1
        
    return sq

def main():
    l=list(map(int,input().split()))
    print(makesquares(l))

main()
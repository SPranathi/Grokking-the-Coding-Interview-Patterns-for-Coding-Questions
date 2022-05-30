"""
Problem Statement #
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

Example 1:

Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.

Example 2:

Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.

Time complexity #
Sorting the array will take O(N∗logN). Overall searchTriplet() will take O(N*logN+N^2),which is asymptotically equivalent to O(N^2).

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for sorting.
"""

def searchTriplet(li,target):
    li.sort()   
    smalldiff=999999        #taking max as 999999
    for i in range(len(li)):
        l,r=i+1,len(li)-1
        while l<r:
            #comparing the sum of three numbers to the targetsum can cause overflow
            #so,we will try to find a target difference
            targetdiff=target-li[i]-li[l]-li[r]
            if targetdiff==0:   #we have found a triplet with exact sum
                return target-targetdiff     #return sum of all the numbers
            if abs(targetdiff)<abs(smalldiff):
                smalldiff=targetdiff    #save the closet difference
            if targetdiff>0:
                l+=1
            else:
                r-=1
    return target-smalldiff


def main():
    li=list(map(int,input().split()))
    target=int(input())
    print(searchTriplet(li,target))

main()

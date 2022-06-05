"""
Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

Example 1:

Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted

Example 2:

Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted 

Time complexity #
The time complexity of the above algorithm will be O(N).

Space complexity #
The algorithm runs in constant space O(1).
"""

def shortwindow(li):
    lo,hi=0,len(li)-1
    #find the first number out of sorting order from the beginning
    while lo<len(li)-1 and li[lo]<=li[lo+1]:
        lo+=1
    if lo==len(li)-1:       #if the array is sorted
        return 0
    #find the first number out of sorting order from the end
    while hi>0 and li[hi]>=li[hi-1]:
        hi-=1
    #find the maximum and minimum of the subarray
    subarray_max=max(li[lo:hi+1])
    subarray_min=min(li[lo:hi+1])

    #extend the subarray to include any number which is bigger than the minimum of the subarray
    while lo>0 and li[lo-1]>subarray_min:
        lo-=1
    #extend the subarray to include any number which is bigger than the minimum of the subarray
    while hi<len(li)-1 and li[hi+1]<subarray_max:
        hi+=1
    return hi-lo+1


def main():
    li=list(map(int,input().split()))
    print(shortwindow(li))

main()
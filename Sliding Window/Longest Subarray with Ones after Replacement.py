"""
Problem Statement #
Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.

Example 1:

Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
Example 2:

Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9. 
"""

def replaceones(arr,k):
    start=maxlength=countones=0
    for i in range(len(arr)):
        if arr[i]==1:
            countones+=1
        if (i-start+1-countones)>k:
            if arr[start]==1:
                countones-=1
            start+=1
        maxlength=max(maxlength,i-start+1)
    return maxlength

def main():
    arr=list(map(int,input().split()))
    k=int(input())
    print(replaceones(arr,k))
main()
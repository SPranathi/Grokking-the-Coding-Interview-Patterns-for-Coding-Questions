"""
Problem Statement 
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

Example 2:

Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].

Time Complexity 
The time complexity of the above algorithm will be O(N)O(N). The outer for loop runs for all elements and the inner while loop processes each element only once, therefore the time complexity of the algorithm will be O(N+N)O(N+N) which is asymptotically equivalent to O(N)O(N).

Space Complexity 
The algorithm runs in constant space O(1)O(1).
"""
def findMinSubarray(S,arr):
    s=0
    minlength=999999 #taking max as 999999
    start=0
    for i in range(len(arr)):
        s+=arr[i]
        while(s>=S):
            minlength=min(minlength,i-start+1)
            s-=arr[start]
            start+=1
    if(minlength==999999):
        return 0
    return minlength

l=list(map(int,input().split()))
S=int(input())
res=findMinSubarray(S,l)
print("Smallest subarray length: ",res)
 

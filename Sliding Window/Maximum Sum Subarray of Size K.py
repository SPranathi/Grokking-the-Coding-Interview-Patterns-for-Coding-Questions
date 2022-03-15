"""
Problem Statement 
Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’. 

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].

Example 2:

Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4].

Time Complexity 
The time complexity of the above algorithm will be O(N)O(N).

Space Complexity 
The algorithm runs in constant space O(1)O(1).

"""
def findMaxSumSubArray(k,li):
        sum=maxsum=start=0
        for i in range(len(li)):
            sum+=li[i]
            if(i>=k-1):
                maxsum=max(maxsum,sum)
                sum-=li[start]
                start+=1
        return maxsum

def main():
    li=list(map(int,input().split()))
    k=int(input());
    print("Maximum sum of a subarray of size K:",findMaxSumSubArray(k,li))
main()

"""
Problem Statement #
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]

Example 2:

Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]

Time complexity #
Sorting the array will take O(N∗logN). The searchPair() will take O(N).
So, overall searchTriplets() will take O(N*logN+N^2), which is asymptotically equivalent to O(N^2).

Space complexity #
Ignoring the space required for the output array, the space complexity of the above algorithm will be O(N) 
which is required for sorting if we are not using an in-place sorting algorithm.
""" 

def search_pair(arr,targetsum,i):
    count,l=0,i+1
    r=len(arr)-1
    while(l<r):
        if(arr[l]+arr[r]<targetsum):
            #since arr[r]>=arr[l], therefore, we can replace r by any number between
            #l and r to get a sum less than the targetsum
            count+=r-l
            l+=1
        else:
            r-=1    #we need a pair with a smaller sum
    return count

def Triplet(arr,target):
    arr.sort()
    count=0
    for i in range(len(arr)-2):
        count+=search_pair(arr,target-arr[i],i)
    return count

def main():
    li=list(map(int,input().split()))
    target=int(input())
    print(Triplet(li,target))

main()

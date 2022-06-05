"""
Given an array of unsorted numbers and a target number, find all unique quadruplets in it,
whose sum is equal to the target number.

Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.

Example 2:

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.
 
Time complexity #
Sorting the array will take O(N*logN)O(N∗logN). Overall searchQuadruplets() will take O(N∗logN+N^3), which is asymptotically equivalent to O(N^3).

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for sorting.
"""


def search_pair(li,target,i,j,quadruples):
    l,r=j+1,len(li)-1
    while l<r:
        s=li[i]+li[j]+li[l]+li[r]
        if s==target:    #found
            quadruples.append([li[i],li[j],li[l],li[r]])
            l+=1
            r-=1
            while l<r and li[l]==li[l-1]:
                l+=1       #skip same elements to avoid duplicates
            while l<r and li[r]==li[r+1]:
                r-=1        #skip same elements to avoid duplicates
        elif target>s:
            l+=1    #we need a piar with bigger sum
        else:
            r-=1    #we need a piar with smaller sum

def quadruplets(li,target):
    li.sort()
    quadruples=[]
    for i in range(0,len(li)-3):
        if i>0 and li[i]==li[i-1]:    #skip same elements to avoid duplicates
            continue
        for j in range(i+1,len(li)-2):
            if j>i+1 and li[j]==li[j-1]:
                continue
            search_pair(li,target,i,j,quadruples)
    return quadruples

def main():
    li=list(map(int,input().split()))
    target=int(input())
    print(quadruplets(li,target))

main()
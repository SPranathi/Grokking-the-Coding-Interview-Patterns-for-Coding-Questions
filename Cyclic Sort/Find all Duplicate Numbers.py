"""
Problem Statement #
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array has some duplicates, find all the duplicate numbers without using any extra space.

Example 1:

Input: [3, 4, 4, 5, 5]
Output: [4, 5]
Example 2:

Input: [5, 4, 7, 2, 3, 5, 3]
Output: [3, 5]

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
Ignoring the space required for storing the duplicates, the algorithm runs in constant space O(1).

"""
def duplicate_numbers(l):
    i=0
    while i<len(l):
        j=l[i]-1
        if l[i]!=l[j]:
            l[i],l[j]=l[j],l[i]
        else:
            i+=1
    duplicatenumbers=[]
    for i in range(len(l)):
        if l[i]!=i+1:
            duplicatenumbers.append(l[i])
    return duplicatenumbers

def main():
    l=list(map(int,input().split()))
    print(duplicate_numbers(l))

main()

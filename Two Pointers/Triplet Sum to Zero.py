"""
Problem Statement #
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.

Example 2:

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.
 
Time complexity #
Sorting the array will take O(N∗logN). The searchPair() function will take O(N).
As we are calling searchPair() for every number in the input array, this means that overall searchTriplets() will take O(N*logN+N^2)
​which is asymptotically equivalent to O(N^2)

Space complexity #
Ignoring the space required for the output array, the space complexity of the above algorithm will be O(N) which is required for sorting.
"""
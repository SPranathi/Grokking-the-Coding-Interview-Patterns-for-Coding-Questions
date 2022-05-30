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


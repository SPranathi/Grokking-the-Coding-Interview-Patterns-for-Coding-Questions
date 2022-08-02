/*
Problem Statement #

Given a sorted number array and two integers ‘K’ and ‘X’, find ‘K’ closest numbers to ‘X’ in the array. Return the numbers in the sorted order. ‘X’ is not necessarily present in the array.

Example 1:

Input: [5, 6, 7, 8, 9], K = 3, X = 7
Output: [6, 7, 8]

Time complexity #

The time complexity of the above algorithm is O(logN + K*logK). We need O(logN) for Binary Search and O(K*logK) to insert the numbers in the Min Heap, as well as to sort the output array.
Space complexity #

The space complexity will be O(K), as we need to put a maximum of 2K numbers in the heap.
*/


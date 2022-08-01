/*
Problem Statement #

Given an unsorted array of numbers, find Kth smallest number in it.

Example 1:

Input: [1, 5, 12, 2, 11, 5], K = 3
Output: 5
Explanation: The 3rd smallest number is '5', as the first two smaller numbers are [1, 2]. 

Time complexity #

The time complexity of this algorithm is O(K*logK+(N-K)*logK), which is asymptotically equal to O(N*logK)
Space complexity #

The space complexity will be O(K) because we need to store ‘K’ smallest numbers in the heap.
An Alternate Approach #

Alternatively, we can use a Min Heap to find the Kth smallest number. We can insert all the numbers in the min-heap and then extract the top ‘K’ numbers from the heap to find the Kth smallest number. Initializing the min-heap with all numbers will take O(N)O(N)O(N) and extracting ‘K’ numbers will take O(KlogN)O(KlogN)O(KlogN). Overall, the time complexity of this algorithm will be O(N+KlogN)O(N+KlogN)O(N+KlogN) and the space complexity will be O(N)O(N)O(N).
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthsmallestnum(vector<int> arr,int k){
    priority_queue<int> maxheap;

    for(int i=0;i<k;i++)
        maxheap.push(arr[i]);
    
    for(int i=k;i<arr.size();i++){
        if(arr[i]<maxheap.top()){
            maxheap.pop();
            maxheap.push(arr[i]);
        }
    }
    return maxheap.top();
}

int main(){
    int res=kthsmallestnum(vector<int> {1,5,12,2,11,15},3);
    cout<<"Kth smallest number is: "<<res<<endl;
}
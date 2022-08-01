/*
Problem Statement #

Given ‘N’ ropes with different lengths, we need to connect these ropes into one big rope with minimum cost. The cost of connecting two ropes is equal to the sum of their lengths.

Example 1:

Input: [1, 3, 11, 5]
Output: 33
Explanation: First connect 1+3(=4), then 4+5(=9), and then 9+11(=20). So the total cost is 33 (4+9+20)

Time complexity #

Given ‘N’ ropes, we need O(N*logN) to insert all the ropes in the heap.
In each step, while processing the heap, we take out two elements from the heap and insert one.
This means we will have a total of ‘N’ steps, having a total time complexity of O(N*logN).
Space complexity #

The space complexity will be O(N) because we need to store all the ropes in the heap.
*/
#include<bits/stdc++.h>
using namespace std;

int mincost(vector<int> arr){
    priority_queue<int,vector<int>,greater<int>> minheap;

    for(int i=0;i<arr.size();i++)
        minheap.push(arr[i]);
    
    int temp=0,res=0;
    while(minheap.size()>1){
        temp=minheap.top();
        minheap.pop();
        temp+=minheap.top();
        minheap.pop();
        res+=temp;
        minheap.push(temp);
    }
    return res;
}

int main(){
    int result=mincost(vector<int> {1,3,11,5});
    cout<<result<<endl;
    result=mincost(vector<int> {3,4,5,6});
    cout<<result<<endl;
    result=mincost(vector<int> {1,3,11,5,2});
    cout<<result<<endl;
}

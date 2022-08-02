/*
Problem Statement #

Design a class to efficiently find the Kth largest element in a stream of numbers.

The class should have the following two things:

    The constructor of the class should accept an integer array containing initial numbers from the stream and an integer ‘K’.
    The class should expose a function add(int num) which will store the given number and return the Kth largest number.

Example 1:

Input: [3, 1, 5, 12, 2, 11], K = 4
1. Calling add(6) should return '5'.
2. Calling add(13) should return '6'.
2. Calling add(4) should still return '6'.

Time complexity #

The time complexity of the add() function will be O(logK)O(logK)O(logK) since we are inserting the new number in the heap.
Space complexity #

The space complexity will be O(K)O(K)O(K) for storing numbers in the heap.
*/
#include<bits/stdc++.h>
using namespace std;

class KthlargestNum{
    public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    int k;

    KthlargestNum(const vector<int> arr,int k){
        this->k=k;
        for(int i=0;i<arr.size();i++)
            add(arr[i]);
    }

    int add(int num){
        minheap.push(num);

        if(minheap.size()>this->k){
            minheap.pop();
        }
        return minheap.top();
    }
};

int main(){
    KthlargestNum lnum({3,1,5,12,2,11},4);
    cout<<lnum.add(6)<<endl;
    cout<<lnum.add(13)<<endl;
    cout<<lnum.add(4)<<endl;
}

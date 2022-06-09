/*
Cycle in a Circular Array  #
We are given an array containing positive and negative numbers. Suppose the array contains a number ‘M’ at a particular index. Now, if ‘M’ is positive we will move forward ‘M’ indices and if ‘M’ is negative move backwards ‘M’ indices. You should assume that the array is circular which means two things:

If, while moving forward, we reach the end of the array, we will jump to the first element to continue the movement.
If, while moving backward, we reach the beginning of the array, we will jump to the last element to continue the movement.
Write a method to determine if the array has a cycle. The cycle should have more than one element and should follow one direction which means the cycle should not contain both forward and backward movements.

Example 1:

Input: [1, 2, -1, 2, 2]
Output: true
Explanation: The array has a cycle among indices: 0 -> 1 -> 3 -> 0

Example 2:

Input: [2, 2, -1, 2]
Output: true
Explanation: The array has a cycle among indices: 1 -> 3 -> 1

Example 3:

Input: [2, 1, -1, -2]
Output: false
Explanation: The array does not have any cycle. 


Time Complexity #
The above algorithm will have a time complexity of O(N^2) where ‘N’ is the number of elements in the array.
This complexity is due to the fact that we are iterating all elements of the array and trying to find a cycle for each element.

Space Complexity #
The algorithm runs in constant space O(1).

*/
#include<bits/stdc++.h>
using namespace std;

int find_next_index(vector<int> arr,bool is_forward,int cur_idx){
    bool direction=arr[cur_idx]>=0;

    if (is_forward!=direction)
        return -1; //change in direction, return -1

    int next_idx=(cur_idx+arr[cur_idx])%arr.size();
    //one element cycle,return -1
    if (next_idx==cur_idx)
        next_idx=-1;
    return next_idx;
}

bool circular_loop(vector<int> arr){
    int slow,fast;
    bool is_forward;
    for(int i=0;i<arr.size();i++){
        is_forward=arr[i]>=0;    //if we are moving forward or not
        slow=i,fast=i;
    }
    
    //if slow or fast becomes '-1' this means we cant find cycle for this number
    while (true){
        //move one step for slow pointer
        slow=find_next_index(arr,is_forward,slow);
        //move one step for fast pointer
        fast=find_next_index(arr,is_forward,fast);
        if(fast!=-1)
            //move another step for fast pointer
            fast=find_next_index(arr,is_forward,fast);
        if (slow==-1 || fast==-1 || slow==fast)
            break;
    }
    if (slow!=-1 && slow==fast)
        return true;
    return false;
}


int main(){
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> arr;
    while(ss>>x){
        arr.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    if(circular_loop(arr))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}

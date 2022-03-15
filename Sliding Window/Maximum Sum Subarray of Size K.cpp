/*
Problem Statement 
Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’. 

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].

Example 2:

Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4].

Time Complexity 
The time complexity of the above algorithm will be O(N)O(N).

Space Complexity 
The algorithm runs in constant space O(1)O(1).

*/
#include<iostream>
#include<vector>
using namespace std;

class MaxSumSubArrayofSizeK{
    public:
    static int findMaxSumSubArray(int k,vector<int> v){
        int sum=0,maxsum=0,start=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(i>=k-1){
                maxsum=max(maxsum,sum);
                sum-=v[start];
                start++;
            }
        }
        return maxsum;
    }
};

int main(){
    int n,k;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    cout<<"Maximum sum of a subarray of size K: "<<MaxSumSubArrayofSizeK::findMaxSumSubArray(k,v)<<endl;
}
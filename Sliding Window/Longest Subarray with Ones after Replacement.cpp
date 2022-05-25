/*
Problem Statement #
Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s,
find the length of the longest contiguous subarray having all 1s.

Example 1:

Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
Example 2:

Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.
*/ 

#include<bits/stdc++.h>
using namespace std;

int replacezeros(vector<int> binary,int k){
    int start=0,maxlength=0,countones=0;
    for(int i=0;i<binary.size();i++){
        if(binary[i]==1)
            countones++;
        if(i-start+1-countones>k){
            if(binary[start]==1)
                countones--;
            start++;
        }
        maxlength=max(maxlength,i-start+1);
    }
    return maxlength;
}

int main(){
    vector<int> binary;
    int x,k;
    string str;
    getline(cin,str);
    stringstream ss(str);
    while(ss>>x){
        binary.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    cin>>k;
    cout<<replacezeros(binary,k);
}
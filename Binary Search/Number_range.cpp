/*
Problem Statement #

Given an array of numbers sorted in ascending order, find the range of a given number ‘key’. The range of the ‘key’ will be the first and last position of the ‘key’ in the array.

Write a function to return the range of the ‘key’. If the ‘key’ is not present return [-1, -1].

Example 1:

Input: [4, 6, 6, 6, 9], key = 6
Output: [1, 3] 
*/
#include<bits/stdc++.h>
using namespace std;

int search(vector<int> arr,int key,bool findmaxindex){
    int keyindex=-1;
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(key<arr[mid])
            end=mid-1;
        else if(key>arr[mid])
            start=mid+1;

        else{
            keyindex=mid;
            if(findmaxindex)
                start=mid+1;
            else
                end=mid-1;
        }
    }
    return keyindex;
}

pair<int,int> findrange(vector<int> arr,int key){
    pair<int,int> res(-1,-1);
    res.first=search(arr,key,false);
    if(res.first!=-1)
        res.second=search(arr,key,true);
    return res;
}


int main(){
    pair<int,int> res=findrange(vector<int> {4,6,6,6,9},6);
    cout<<"Range: "<<res.first<<","<<res.second<<endl;
    res=findrange(vector<int> {1,3,8,10,15},10);
    cout<<"Range: "<<res.first<<","<<res.second<<endl;
    res=findrange(vector<int> {1,3,8,10,15},12);
    cout<<"Range: "<<res.first<<","<<res.second<<endl;
}
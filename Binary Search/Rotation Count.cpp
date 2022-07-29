/*
Given an array of numbers which is sorted in ascending order and is rotated ‘k’ times around a pivot, find ‘k’.

*/
#include<bits/stdc++.h>
using namespace std;

int countrotations(vector<int> arr){
    int start=0,end=arr.size()-1;
    while(start<end){
        int mid=start+(end-start)/2;
        if(mid<end && arr[mid]>arr[mid+1])
            return mid+1;
        if(mid>start && arr[mid-1]>arr[mid])
            return mid;
        

        if(arr[start]==arr[mid] && arr[mid]==arr[end]){
            if(arr[start]>arr[start+1])
                return start+1;
            ++start;
            if(arr[end-1]>arr[end])
                return end;
            --end;
        }
        else if(arr[start]<arr[mid] || (arr[start]==arr[mid] && arr[mid]>arr[end]))
            start=mid+1;
        else
            end=mid-1;
    }
    return 0;
}

int main(){
    cout<<countrotations(vector<int> {10,15,1,3,8})<<endl;
    cout<<countrotations(vector<int> {4,5,7,9,10,-1,2})<<endl;
    cout<<countrotations(vector<int> {1,3,8,10})<<endl;
    cout<<countrotations(vector<int> {3,3,8,3})<<endl;
}
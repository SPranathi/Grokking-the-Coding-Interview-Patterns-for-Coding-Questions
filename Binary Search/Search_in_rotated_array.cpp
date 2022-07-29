/*
Search in Rotated Array (medium) #

Given an array of numbers which is sorted in ascending order and also rotated by some arbitrary number, find if a given ‘key’ is present in it.

Write a function to return the index of the ‘key’ in the rotated array. If the ‘key’ is not present, return -1. You can assume that the given array does not have any duplicates.

Example 1:

Input: [10, 15, 1, 3, 8], key = 15
Output: 1
Explanation: '15' is present in the array at index '1'.
*/
#include<bits/stdc++.h>
using namespace std;

int search(vector<int> arr,int key){
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
            return mid;

        //if there are duplicates
        if((arr[start]==arr[mid]) && (arr[end]==arr[mid])){
            ++start;
            --end;
        }

        else if(arr[start]<=arr[mid]){   //left side is sorted in ascending order
            if(key>=arr[start] && key<arr[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        else{   //right side is sorted in ascending order
            if(key>arr[mid] && key<=arr[end])
                start=mid+1;
            else
                end=mid-1;
        }
    }
    return -1;
}

int main(){
    cout<<search(vector<int>{10,15,1,3,8},15)<<endl;
    cout<<search(vector<int>{4,5,7,9,10,-1,2},10)<<endl;
    cout<<search(vector<int>{3,7,3,3,3},7)<<endl;
}

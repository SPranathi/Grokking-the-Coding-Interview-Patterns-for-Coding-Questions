 /*
Problem statement #

Given a Bitonic array, find if a given ‘key’ is present in it. An array is considered bitonic if it is monotonically increasing and then monotonically decreasing. Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].

Write a function to return the index of the ‘key’. If the ‘key’ is not present, return -1.

Example 1:

Input: [1, 3, 8, 4, 3], key=4
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

//find the index of the maximum value
int findmax(vector<int> arr){
    int start=0,end=arr.size()-1;
    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[mid+1])
            end=mid;
        else
            start=mid+1;
    }
    return start;
}

int binarysearch(vector<int> arr,int key,int start,int end){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[start]<arr[end]){    //ascending order
            if(key<arr[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        else{   //descending order
            if(key>arr[mid])
                end=mid-1;
            else 
                start=mid+1;
        }
    }
    return -1;
}

int search(vector<int> arr,int key){
    int maxindex=findmax(arr);
    int keyindex=binarysearch(arr,key,0,maxindex);
    if(keyindex!=-1)
        return keyindex;
    return binarysearch(arr,key,maxindex+1,arr.size()-1);
}

int main(){
    cout<<search(vector<int> {1,3,8,4,3},4)<<endl;
    cout<<search(vector<int> {3,8,3,1},8)<<endl;
    cout<<search(vector<int> {1,3,8,12},12)<<endl;
}
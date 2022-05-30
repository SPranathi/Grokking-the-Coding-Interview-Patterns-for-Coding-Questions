/*
Problem Statement #
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices.
Write a function to return the count of such triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]

Example 2:

Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3] 

Time complexity #
Sorting the array will take O(N∗logN). The searchPair() will take O(N).
So, overall searchTriplets() will take O(N*logN+N^2), which is asymptotically equivalent to O(N^2).

Space complexity #
Ignoring the space required for the output array, the space complexity of the above algorithm will be O(N) 
which is required for sorting if we are not using an in-place sorting algorithm.
*/
#include<bits/stdc++.h>
using namespace std;

int searchpair(vector<int> &arr,int targetsum,int i){
    int count=0,l=i+1,r=arr.size()-1;
    while(l<r){
        if(arr[l]+arr[r]<targetsum){
            //since arr[r]>=arr[l], therefore, we can replace r by any number between
            //l and r to get a sum less than the targetsum
            count+=r-l;
            l++;
        }
        else{
            r--;    //we need a pair with a smaller sum
        }
    }
    return count;
}

vector<vector<int>> searchtriplets(vector<int> &arr){
    sort(arr.begin(),arr.end());
    int count=0;
    for(int i=0;i<arr.size()-2;i++){
        count+=searchpair(arr,target-arr[i],i);
    }
    return count;
}

int main(){
    vector<int> arr;
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss>>x){
        arr.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    int target;
    cin>>target;
    cout<<searchtriplet(arr,target)<<endl;
}

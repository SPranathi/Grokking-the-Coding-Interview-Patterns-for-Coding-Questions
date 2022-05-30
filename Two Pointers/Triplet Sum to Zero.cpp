/*
Problem Statement #
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.

Example 2:

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.

Time complexity #
Sorting the array will take O(N∗logN). The searchPair() function will take O(N).
As we are calling searchPair() for every number in the input array, this means that overall searchTriplets() will take O(N*logN+N^2),
which is asymptotically equivalent to O(N^2).
​

Space complexity #
Ignoring the space required for the output array, the space complexity of the above algorithm will be O(N) which is required for sorting.
*/
#include<bits/stdc++.h>
using namespace std;

void searchpair(vector<int> &arr,int targetsum,int l,vector<vector<int>> &triplets){
    int r=arr.size()-1;
    while(l<r){
        int cursum=arr[l]+arr[r];
        if(cursum==targetsum){      //found the pair
            triplets.push_back({-targetsum,arr[l],arr[r]});
            l++;
            r--;
            while(l<r && arr[l]==arr[l-1])
                l++;    //skip same element to avoid duplicate triplets
            while(l<r && arr[r]==arr[r+1])
                r--;    //skip same element to avoid duplicate triplets
        }
        else if(targetsum>cursum){
            l++;    //we need a pair with a bigger sum
        }
        else
        {
            r--;    //we need a pair with a smaller sum
        }
    }
}

vector<vector<int>> searchtriplets(vector<int> &arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> triplets;
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i]==arr[i-1])     //skip same element to avoid duplicate triplets
            continue;
        searchpair(arr,-arr[i],i+1,triplets);
    }
    return triplets;
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
    vector<vector<int>> v=searchtriplets(arr);
    for(auto i:v){
        cout<<"[";
        for(auto j:i)
            cout<<j<<" ";
        cout<<"]";
    }
}

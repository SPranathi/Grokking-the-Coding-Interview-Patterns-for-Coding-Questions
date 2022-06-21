/*
Problem Statement
Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.

Example 1:

Input: [3, -1, 4, 5, 5], k=3
Output: [1, 2, 6]
Explanation: The smallest missing positive numbers are 1, 2 and 6.

Example 2:

Input: [2, 3, 4], k=3
Output: [1, 5, 6]
Explanation: The smallest missing positive numbers are 1, 5 and 6. 

Time complexity #
The time complexity of the above algorithm is O(n+k), as the last two for loops will run for O(n) and O(k) times respectively.

Space complexity #
The algorithm needs O(k) space to store the extraNumbers.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> missing_numbers(vector<int> v,int k){
    int i=0,n=v.size();
    while(i<n){
        int j=v[i]-1;
        if(v[i]>0 && v[i]<=n && v[i]!=v[j])
            swap(v[i],v[j]);
        else
            i++;
    }

    vector<int> nums;
    unordered_set<int> extranums;
    for(int i=0;i<n && nums.size()<k;i++){
        if(v[i]!=i+1){
            nums.push_back(i+1);
            extranums.insert(v[i]);
        }
    }

    //add the remaining numbers
    for(int i=1;nums.size()<k;i++){
        int l=i+n;
        //ignore if the array contains the number
        if(extranums.find(l)==extranums.end())
            nums.push_back(l);
    }
    return nums;
}

int main(){
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> v;
    while(ss>>x){
        v.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    int k;
    cin>>k;
    vector<int> ans=missing_numbers(v,k);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
}
/*
Problem Statement #

Given a set of numbers that might contain duplicates, find all of its distinct subsets.

Time complexity
O(2^N)

space complexity
O(2^N)
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findsubsets(vector<int> nums){
    vector<vector<int>> subsets;
    sort(nums.begin(),nums.end());
    subsets.push_back(vector<int> ());
    int start=0,end=0;
    for(int i=0;i<nums.size();i++){
        start=0;
        if(i>0 && nums[i]==nums[i-1])
            start=end;
        end=subsets.size();
        for(int j=start;j<end;j++){
            vector<int> set(subsets[j]);
            set.push_back(nums[i]);
            subsets.push_back(set);
        }
    }
    return subsets;
}


int main(){
    vector<vector<int>> res=findsubsets(vector<int> {1,3,3});
    cout<<"list of subsets: "<<endl;
    for(auto num:res){
        for(auto n:num)
            cout<<n<<" ";
        cout<<endl;
    }
    res=findsubsets(vector<int> {1,5,3,3});
    cout<<"list of subsets: "<<endl;
    for(auto num:res){
        for(auto n:num)
            cout<<n<<" ";
        cout<<endl;
    }
}
 

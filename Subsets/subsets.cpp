/*
Problem Statement #

Given a set with distinct elements, find all of its distinct subsets.

Time complexity
O(2^N)

space complexity
O(2^N)
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findsubsets(vector<int> nums){
    vector<vector<int>> subsets;

    subsets.push_back(vector<int> ());
    for(auto curnum:nums){
        int n=subsets.size();
        for(int i=0;i<n;i++){
            vector<int> set(subsets[i]);
            set.push_back(curnum);
            subsets.push_back(set);
        }
    }
    return subsets;
}


int main(){
    vector<vector<int>> res=findsubsets(vector<int> {1,3});
    cout<<"list of subsets: "<<endl;
    for(auto num:res){
        for(auto n:num)
            cout<<n<<" ";
        cout<<endl;
    }
    res=findsubsets(vector<int> {1,3,5});
    cout<<"list of subsets: "<<endl;
    for(auto num:res){
        for(auto n:num)
            cout<<n<<" ";
        cout<<endl;
    }
}

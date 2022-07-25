/*
Problem Statement #

Given a set of distinct numbers, find all of its permutations.

Permutation is defined as the re-arranging of the elements of the set. For example, {1, 2, 3} has the following six permutations:

    {1, 2, 3}
    {1, 3, 2}
    {2, 1, 3}
    {2, 3, 1}
    {3, 1, 2}
    {3, 2, 1}
If a set has ‘n’ distinct elements it will have n!n!n! permutations.

Example 1:

Input: [1,3,5]
Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]

Time complexity:
O(N*N!)

space complexity:
O(N*N!)
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findpermutations(vector<int> nums){
    vector<vector<int>> res;
    queue<vector<int>> permutations;
    permutations.push(vector<int> ());
    for(auto curnum:nums){
        int n=permutations.size();
        for(int i=0;i<n;i++){
            vector<int> old=permutations.front();
            permutations.pop();
            
            for(int j=0;j<=old.size();j++){
                vector<int> newpermutation(old);
                newpermutation.insert(newpermutation.begin()+j,curnum);
                if(newpermutation.size()==nums.size()){
                    res.push_back(newpermutation);
                }
                else{
                    permutations.push(newpermutation);
                }
            }
        }
    }
    return res;
}

void recursion(vector<int> nums,int index,vector<int> &curpermutation,vector<vector<int>> &res){
    if(index==nums.size()){
        res.push_back(curpermutation);
    }
    else{
        for(int i=0;i<=curpermutation.size();i++){
            vector<int> newpermutation(curpermutation);
            newpermutation.insert(newpermutation.begin()+i,nums[index]);
            recursion(nums,index+1,newpermutation,res);
        }
    }
}

vector<vector<int>> permutationsrecursion(vector<int> nums){
    vector<vector<int>> res;
    vector<int> curpermutation;
    recursion(nums,0,curpermutation,res);
    return res;
}

int main(){
    vector<vector<int>> res=findpermutations(vector<int> {1,3,5});
    cout<<"Permutations :"<<endl;
    for(auto vec:res){
        for(auto i:vec)
            cout<<i<<" ";
        cout<<endl;
    }
    res=permutationsrecursion(vector<int> {1,3,5});
    cout<<"Permutations :"<<endl;
    for(auto vec:res){
        for(auto i:vec)
            cout<<i<<" ";
        cout<<endl;
    }
}

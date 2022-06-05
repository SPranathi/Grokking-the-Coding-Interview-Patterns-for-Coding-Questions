/*
Given an array of unsorted numbers and a target number, find all unique quadruplets in it,
whose sum is equal to the target number.

Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.

Example 2:

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.
 
Time complexity #
Sorting the array will take O(N*logN)O(N∗logN). Overall searchQuadruplets() will take O(N∗logN+N^3), which is asymptotically equivalent to O(N^3).

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for sorting.
*/
#include<bits/stdc++.h>
using namespace std;

void search_pair(vector<int> v,int target,int i,int j,vector<vector<int>> &quadruples){
    int l=j+1,r=v.size()-1;
    while(l<r){
        int sum=v[i]+v[j]+v[l]+v[r];
        if(sum==target){    //found
            quadruples.push_back({v[i],v[j],v[l],v[r]});
            l++;
            r--;
            while(l<r && v[l]==v[l-1])
                l++;        //skip same elements to avoid duplicates
            while(l<r && v[r]==v[r+1])
                r--;        //skip same elements to avoid duplicates
        }
        else if(target>sum)
            l++;    //we need a piar with bigger sum
        else
            r--;    ////we need a piar with smaller sum
        
    }
}

vector<vector<int>> quadruplets(vector<int> v,int target){
    sort(v.begin(),v.end());
    vector<vector<int>> quadruples;
    for(int i=0;i<v.size()-3;i++){
        if(i>0 && v[i]==v[i-1])     //skip same elements to avoid duplicates
            continue;
        for(int j=i+1;j<v.size()-2;j++){
            if(j>i+1 && v[j]==v[j-1])
                continue;
            search_pair(v,target,i,j,quadruples);
        }
    }
    return quadruples;
}

int main(){
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> v;
    int target;
    while(ss>>x){
        v.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    cin>>target;
    vector<vector<int>> ans=quadruplets(v,target);
    for(auto i:ans){
        cout<<'[';
        for(auto j:i)
            cout<<j<<" ";
        cout<<']';
    }
}
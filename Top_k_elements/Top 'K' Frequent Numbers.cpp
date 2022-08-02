/*
Problem Statement #

Given an unsorted array of numbers, find the top ‘K’ frequently occurring numbers in it.

Example 1:

Input: [1, 3, 5, 12, 11, 12, 11], K = 2
Output: [12, 11]
Explanation: Both '11' and '12' apeared twice.

*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

vector<int> findKfrequent(vector<int> arr,int k){
    unordered_map<int,int> umap;
    for(auto n:arr)
        umap[n]++;
    vector<int> ans;
    priority_queue<pair<int,int>> maxheap;
    for(auto num:umap){
        maxheap.push(make_pair(num.second,num.first));
        if(maxheap.size()>umap.size()-k){
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
    }
    return ans;
}

int main(){
    vector<int> res=findKfrequent(vector<int>{1,3,5,12,11,12,11},3);
    for(auto n:res)
        cout<<n<<" ";
    cout<<endl;
}

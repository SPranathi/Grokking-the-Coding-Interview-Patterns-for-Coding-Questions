/*
Problem Statement #

Given a string, sort it based on the decreasing frequency of its characters.

Example 1:

Input: "Programming"
Output: "rrggmmPiano"
Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before any other character.
*/
#include<bits/stdc++.h>
using namespace std;

string  frequencysort(string str){
    unordered_map<char,int> umap;
    for(auto s:str){
        umap[s]++;
    }
    priority_queue<pair<int,char>> maxheap;
    for(auto st:umap)
        maxheap.push(make_pair(st.second,st.first));
    string ans="";

    while(!maxheap.empty()){
        auto t=maxheap.top();
        maxheap.pop();
        for(int i=0;i<t.first;i++)
            ans+=t.second;
    }
    return ans;
} 

int main(){
    string res=frequencysort("Programming");
    cout<<res<<endl ;
    res=frequencysort("aabbbc");
    cout<<res<<endl ;
}

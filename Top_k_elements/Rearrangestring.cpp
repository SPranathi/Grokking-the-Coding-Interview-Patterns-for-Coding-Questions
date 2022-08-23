/*
Problem Statement #

Given a string, find if its letters can be rearranged in such a way that no two same characters come next to each other.

Example 1:

Input: "aappp"
Output: "papap"
Explanation: In "papap", none of the repeating characters come next to each other.

Time complexity #

The time complexity of the above algorithm is O(N*logN) where ‘N’ is the number of characters in the input string.
Space complexity #

The space complexity will be O(N), as in the worst case, we need to store all the ‘N’ characters in the HashMap.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
struct compare{
    char operator()(const pair<int,int> &x,const pair<int,int> &y){
    return y.second>x.second;
    }
};
string rearranged(string s){
    unordered_map<char,int> umap;
    for(char c:s)
        umap[c]++;

    priority_queue<pair<char,int>,vector<pair<char,int>>,compare> maxheap;

    for(auto p:umap)
        maxheap.push(p);

    pair<char,int> prev(-1,-1);
    string res="";
    while(!maxheap.empty()){
        pair<char,int> cur=maxheap.top();
        maxheap.pop();

        if(prev.second>0)
            maxheap.push(prev);

        res+=cur.first;
        cur.second--;
        prev=cur;
    }
    return res.length()==s.length()? res:"";
}
int main(){
    cout<<rearranged("aappp")<<endl;
    cout<<rearranged("programming")<<endl;
    cout<<rearranged("aapa")<<endl;
}
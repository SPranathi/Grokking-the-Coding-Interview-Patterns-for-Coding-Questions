/*
Problem Statement #

Given a string and a pattern, find all anagrams of the pattern in the given string.

Anagram is actually a Permutation of a string. For example, “abc” has the following six anagrams:
abc
acb
bac
bca
cab
cba
Write a function to return a list of starting indices of the anagrams of the pattern in the given string.

Example 1:

Input: String="ppqp", Pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".
Example 2:

Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc". 

Time Complexity #
The time complexity of the above algorithm will be O(N+M) where ‘N’ and ‘M’ are the number of characters in the input string and the pattern respectively.

Space Complexity #
The space complexity of the algorithm is O(M) since in the worst case, the whole pattern can have distinct characters which will go into the HashMap.
In the worst case, we also need O(N)O(N) space for the result list, this will happen when the pattern has only one character and the string contains only that character.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p){
    int start=0,matched=0;
    unordered_map<char,int> freqmap;
    vector<int> res;
    for(auto i:p)
        freqmap[i]++;
    for(int i=0;i<s.size();i++){
        if(freqmap.find(s[i])!=freqmap.end()){
            freqmap[s[i]]--;
            if(freqmap[s[i]]==0)
                matched+=1;
        }
        if(matched==freqmap.size())
            res.push_back(start);
        if(i>=p.size()-1){
            if(freqmap.find(s[start])!=freqmap.end()){
                if(freqmap[s[start]]==0)
                    matched--;
                freqmap[s[start]]++;
        }
        start++;
        }
    }
    return res;
}

int main(){
    string s,p;
    cin>>s>>p;
    vector<int> res=findAnagrams(s,p);
    for(auto i:res)
        cout<<i<<" ";
}
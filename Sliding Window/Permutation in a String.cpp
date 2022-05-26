/*
Problem Statement #

Given a string and a pattern, find out if the string contains any permutation of the pattern.

Permutation is defined as the re-arranging of the characters of the string.
For example, “abc” has the following six permutations:
abc
acb
bac
bca
cab
cba
If a string has ‘n’ distinct characters it will have n!n! permutations.

Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.

Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.

Example 3:

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.

Time Complexity #
The time complexity of the above algorithm will be O(N+M) where ‘N’ and ‘M’ are the number of characters in the input string and the pattern respectively.

Space Complexity #
The space complexity of the algorithm is O(M) since in the worst case, the whole pattern can have distinct characters which will go into the HashMap.
*/

#include<bits/stdc++.h>
using namespace std;

bool findpermutation(string s,string p){
    int start=0,matched=0;
    unordered_map<char,int> freqmap;
    for(auto i:p)
        freqmap[i]++;
    for(int i=0;i<s.length();i++){
        if(freqmap.find(s[i])!=freqmap.end()){
            freqmap[s[i]]--;   //decrement thr frequency of the matched character
            if(freqmap[s[i]]==0)        //character is completely matched
                matched++;
        }

        if(matched==freqmap.size())
            return true;

        if(i>=p.size()-1){  //shrink the window
            if(freqmap.find(s[start])!=freqmap.end()){
                if(freqmap[s[start]]==0)
                    matched--;          //before putting the character back, decrement the matched count
                freqmap[s[start]]++;
            }
            start++;
        }
    }
    return false;
}


int main(){
    string s,p;
    cin>>s>>p;
    if(findpermutation(s,p))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

}
/*
Problem Statement #

Given a string and a pattern, find the smallest substring in the given string which has all the characters of the given pattern.

Example 1:

Input: String="aabdec", Pattern="abc"
Output: "abdec"
Explanation: The smallest substring having all characters of the pattern is "abdec"

Example 2:

Input: String="abdabca", Pattern="abc"
Output: "abc"
Explanation: The smallest substring having all characters of the pattern is "abc".

Example 3:

Input: String="adcad", Pattern="abc"
Output: ""
Explanation: No substring in the given string has all characters of the pattern. 

Time Complexity #
The time complexity of the above algorithm will be O(N+M) where ‘N’ and ‘M’ are the number of characters in the input string and the pattern respectively.

Space Complexity #
The space complexity of the algorithm is O(M) since in the worst case, the whole pattern can have distinct characters which will go into the HashMap. In the worst case,
we also need O(N) space for the resulting substring, which will happen when the input string is a permutation of the pattern.

*/

#include<bits/stdc++.h>
using namespace std;

string MinWindowSubstring(string s,string p){
    int start=0,matched=0,minlength=s.length()+1,substrstart=0;
    unordered_map<char,int> freqmap;
    for(auto i:p)
        freqmap[i]++;

    for(int i=0;i<s.size();i++){
        if(freqmap.find(s[i])!=freqmap.end()){
            freqmap[s[i]]--;
            if(freqmap[s[i]]>=0)
                matched++;      //count every matching of a character
        }

        //shrink the window if we can,finish as soon as we remove a matched character
        while(matched==p.length()){
            if(minlength>i-start+1){
                minlength=i-start+1;
                substrstart=start;
            }
            
            if(freqmap.find(s[start])!=freqmap.end()){
                if(freqmap[s[start]]==0)
                    matched--;
                freqmap[s[start]]++;
            }
            start++;
        }
    }
    return minlength>s.length()?"":s.substr(substrstart,minlength);
}

int main(){
    string s,p;
    cin>>s>>p;
    cout<<MinWindowSubstring(s,p)<<endl;
}
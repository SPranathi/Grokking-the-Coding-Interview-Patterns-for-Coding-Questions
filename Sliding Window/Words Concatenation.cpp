/*
Problem Statement #
Given a string and a list of words, find all the starting indices of substrings in the given string that are a concatenation of all the given words exactly once without any overlapping of words.
It is given that all words are of the same length.

Example 1:

Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" & "foxcat".

Example 2:

Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3]
Explanation: The only substring containing both the words is "catfox".

Here are the set of steps for our algorithm:

1.Keep the frequency of every word in a HashMap.
2.Starting from every index in the string, try to match all the words.
3.In each iteration, keep track of all the words that we have already seen in another HashMap.
4.If a word is not found or has a higher frequency than required, we can move on to the next character in the string.
5.Store the index if we have found all the words.

Time Complexity #
The time complexity of the above algorithm will be O(N∗M∗Len) where ‘N’ is the number of characters in the given string, ‘M’ is the total number of words, and ‘Len’ is the length of a word.

Space Complexity #
The space complexity of the algorithm is O(M) since at most, we will be storing all the words in the two HashMaps. In the worst case, we also need O(N) space for the resulting list.
So, the overall space complexity of the algorithm will be O(M+N).
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findwordConcatenation(string s,vector<string> words){
    unordered_map<string,int> freqmap;
    for(auto i:words)
        freqmap[i]++;
    
    vector<int> res;
    int wordcount=words.size(),wordlen=words[0].length();

    for(int i=0;i<=s.length()-wordcount*wordlen;i++){
        unordered_map<string,int> seen;
        for(int j=0;j<wordcount;j++){
            int nextindex=i+j*wordlen;
            //get the next word from the string
            string word=s.substr(nextindex,wordlen);
            if(freqmap.find(word)==freqmap.end())   //break if we don't need this word
                break;

            seen[word]++;       //add the word to seen map

            //no need to process further if the word has higher frequency than required
            if(seen[word]>freqmap[word])
                break;

            if(j+1==wordcount)      //store index if we have found all the words
                res.push_back(i);
        }
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    vector<string> words;
    string str,st;
    getline(cin,str);
    stringstream ss(str);
    while(ss>>st){
        words.push_back(st);
        if(ss.peek()==' ')
            ss.ignore();
    }
    vector<int> res=findwordConcatenation(s,words);
    for(auto i:res)
        cout<<i<<" ";
}
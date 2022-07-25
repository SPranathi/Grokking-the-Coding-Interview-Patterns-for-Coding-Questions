/*
Problem Statement #

Given a string, find all of its permutations preserving the character sequence but changing case.

example:
"ad52"
"ad52","Ad52","aD52","AD52"

Time complexity:
O(N*2^N)

space complexity:
O(N*2^N)
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> lettercasepermutation(string str){
    vector<string> res;
    if(str=="")
        return res;

    res.push_back(str);
    for(int i=0;i<str.length();i++){
        if(isalpha(str[i])){
            int n=res.size();
            for(int j=0;j<n;j++){
                vector<char> chs(res[j].begin(),res[j].end());
                if(isupper(chs[i]))
                    chs[i]=tolower(chs[i]);
                else
                    chs[i]=toupper(chs[i]);
                res.push_back(string(chs.begin(),chs.end()));
            }

        }
    }
    return res;
}

int main(){
    vector<string> res=lettercasepermutation("ab7c");
    for(auto i:res)
        cout<<i<<" ";
    cout<<endl;
}
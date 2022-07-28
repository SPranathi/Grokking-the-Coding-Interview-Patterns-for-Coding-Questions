/*
Problem Statement #

For a given number ‘N’, write a function to generate all combination of ‘N’ pairs of balanced parentheses.

Example 1:

Input: N=2
Output: (()), ()()

Time complexity:
O(N*2^N)

Space complexity:
O(N*2^N)
*/
#include<bits/stdc++.h>
using namespace std;

class parenthesesString{
    public:
    string str;
    int openbrkt=0,closebrkt=0;

    parenthesesString(const string &s,int openbrkt,int closebrkt){
        this->str=s;
        this->openbrkt=openbrkt;
        this->closebrkt=closebrkt;
    }
};


vector<string> balancedparentheses(int n){
    vector<string> res;
    queue<parenthesesString> q;
    q.push({"",0,0});
    while(!q.empty()){
        parenthesesString s=q.front();
        q.pop();

        if(s.openbrkt==n && s.closebrkt==n){
            res.push_back(s.str);
        }
        else{
            if(s.openbrkt<n){
                q.push({s.str+"(",s.openbrkt+1,s.closebrkt});
            }
            if(s.openbrkt>s.closebrkt){
                q.push({s.str+")",s.openbrkt,s.closebrkt+1});
            }
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<string> res=balancedparentheses(n);
    for(auto i:res)
        cout<<i<<endl;
}

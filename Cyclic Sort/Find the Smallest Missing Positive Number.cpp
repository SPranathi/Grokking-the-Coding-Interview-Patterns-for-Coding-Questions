/*
Problem statement
Given an unsorted array containing numbers, find the smallest missing positive number in it.

Example 1:

Input: [-3, 1, 5, 4, 2]
Output: 3
Explanation: The smallest missing positive number is '3'

Example 2:

Input: [3, -2, 0, 1, 2]
Output: 4 

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1).
*/
#include<bits/stdc++.h>
using namespace std;

int first_missing_num(vector<int> v){
    int i=0,n=v.size();
    while(i<n){
        int j=v[i]-1;
        if( v[i]>0 && v[i]<=n && v[i]!=v[j])
            swap(v[i],v[j]);
        else
            i++;
    }
    for(int k=0;k<n;k++){
        if(v[k]!=k+1)
            return k+1;
    }
    return v.size()+1;
}

int main(){
    vector<int> v;
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss>>x){
        v.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    cout<<first_missing_num(v)<<endl;
}

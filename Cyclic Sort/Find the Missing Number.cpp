/*
Problem Statement #
We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.

Example 1:

Input: [4, 0, 3, 1]
Output: 2
Example 2:

Input: [8, 3, 5, 2, 4, 6, 0, 1]
Output: 7

Time complexity #
The time complexity of the above algorithm is O(n). 

Space complexity #
The algorithm runs in constant space O(1).
*/

#include<bits/stdc++.h>
using namespace std;

int missing_num(vector<int> v){
    int i=0,n=v.size();
    while(i<n){
        int j=v[i];
        if(v[i]<n && v[i]!=v[j])
            swap(v[i],v[j]);
        else
            i++;
    }

    for(int k=0;k<n;k++){
        if(v[k]!=k)
            return k;
    }
    return n;
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
    cout<<missing_num(v)<<endl;
}
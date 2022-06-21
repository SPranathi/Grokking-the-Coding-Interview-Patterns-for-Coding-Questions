/*
Problem Statement #
We are given an unsorted array containing numbers taken from the range 1 to ‘n’. The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.

Example 1:

Input: [2, 3, 1, 8, 2, 3, 5, 1]
Output: 4, 6, 7
Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
Example 2:

Input: [2, 4, 1, 2]
Output: 3

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
Ignoring the space required for the output array, the algorithm runs in constant space O(1).
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> missing_numbers(vector<int> v){
    int i=0,n=v.size();
    while(i<n){
        int j=v[i]-1;
        if(v[i]!=v[j])
            swap(v[i],v[j]);
        else
            i++;
    }
    vector<int> ans;
    for(int k=0;k<n;k++){
        if(v[k]!=k+1)
            ans.push_back(k+1);
    }
    return ans;
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
    vector<int> ans=missing_numbers(v);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
}

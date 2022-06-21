/*
Problem statement#
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’.
The array originally contained all the numbers from 1 to ‘n’, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing.
Find both these numbers.

Example 1:

Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.
Example 2:

Input: [3, 1, 2, 3, 6, 4]
Output: [3, 5]
Explanation: '3' is duplicated and '5' is missing. 

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1).
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> corrupt_numbers(vector<int> v){
    int i=0,n=v.size();
    while(i<n){
        int j=v[i]-1;
        if(v[i]!=v[j])
            swap(v[i],v[j]);
        else
            i++;
    }
    for(int k=0;k<n;k++){
        if(v[k]!=k+1)
            return {v[k],k+1};
    }
    return {-1,-1};
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
    vector<int> ans=corrupt_numbers(v);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
}

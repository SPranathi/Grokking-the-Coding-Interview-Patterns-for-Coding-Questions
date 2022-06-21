/*
Problem Statement #
We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’. The array has only one duplicate but it can be repeated multiple times. Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.

Example 1:

Input: [1, 4, 4, 3, 2]
Output: 4
Example 2:

Input: [2, 1, 3, 3, 5, 4]
Output: 3

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1) but modifies the input array.

*/

#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int> v){
    int i=0,n=v.size();
    while(i<n){
        if(v[i]!=i+1){
            int j=v[i]-1;
            if(v[i]!=v[j])
                swap(v[i],v[j]);
            else
                return v[i];
        }
        else
            i++;
    }
    return -1;
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
    cout<<duplicate(v)<<endl;
}
 

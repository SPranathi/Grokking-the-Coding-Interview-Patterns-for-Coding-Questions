/*
Problem Statement #
Given an array of sorted numbers, remove all duplicates from it.
You should not use any extra space; after removing the duplicates in-place return the new length of the array.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].

Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].

Time Complexity #
The time complexity of the above algorithm will be O(N), where ‘N’ is the total number of elements in the given array.

Space Complexity #
The algorithm runs in constant space O(1).
*/

#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int> v){
    //index of the next non-duplicate element
    int next_non_duplicate=1;

    int i=1;
    while(i<v.size()){
        if(v[next_non_duplicate-1]!=v[i]){
            v[next_non_duplicate]=v[i];
            next_non_duplicate++;
        }
        i++;
    }
    return next_non_duplicate;
}

int main(){
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> v;
    while(ss>>x){
        v.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    cout<<remove_duplicates(v)<<endl;
}

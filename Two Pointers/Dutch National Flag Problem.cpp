/*
Problem Statement #
Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects,
hence, we can’t count 0s, 1s, and 2s to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; and
since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.

Example 1:

Input: [1, 0, 2, 1, 0]
Output: [0 0 1 1 2]

Example 2:

Input: [2, 2, 0, 1, 2, 0]
Output: [0 0 1 2 2 2 ] 

Time complexity #
The time complexity of the above algorithm will be O(N)O(N) as we are iterating the input array only once.

Space complexity #
The algorithm runs in constant space O(1)O(1).
*/
#include<bits/stdc++.h>
using namespace std;

void dutch_flag(vector<int> &v){
    int lo=0,hi=v.size()-1,i=0;
    while(i<=hi){
        if(v[i]==0){
            int temp=v[i];
            v[i]=v[lo];
            v[lo]=temp;
            i++;
            lo++;
        }
        else if(v[i]==1)
            i++;
        else{
            int temp=v[i];
            v[i]=v[hi];
            v[hi]=temp;
            //decrement 'high' only, after the swap the number at index i could be 0 or 1 or 2
            hi--;  
        }
    }
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
    dutch_flag(v);
    for(auto i:v)
        cout<<i<<" ";
}
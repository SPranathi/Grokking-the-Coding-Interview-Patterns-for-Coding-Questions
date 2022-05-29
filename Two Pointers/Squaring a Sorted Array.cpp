/*
Problem Statement #
Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]

Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9]

Time complexity #
The time complexity of the above algorithm will be O(N)O(N) as we are iterating the input array only once.

Space complexity #
The space complexity of the above algorithm will also be O(N)O(N); this space will be used for the output array.

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> makesquares(vector<int> v){
    int n=v.size();
    vector<int> sq(n);
    int highestsquareidx=n-1,l=0,r=n-1;
    while(l<=r){
        int lsquare=v[l]*v[l];
        int rsquare=v[r]*v[r];
        if(lsquare>rsquare){
            sq[highestsquareidx--]=lsquare;
            l++;
        }
        else{
            sq[highestsquareidx--]=rsquare;
            r--;
        }
    }
    return sq;
}

int main(){
    vector<int> v,res;
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss>>x){
        v.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    res=makesquares(v);
    for(auto i:res)
        cout<<i<<' ';
}
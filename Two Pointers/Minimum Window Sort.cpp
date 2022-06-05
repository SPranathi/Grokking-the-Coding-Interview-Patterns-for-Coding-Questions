/*
Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

Example 1:

Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted

Example 2:

Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted 

Time complexity #
The time complexity of the above algorithm will be O(N).

Space complexity #
The algorithm runs in constant space O(1).
*/
#include<bits/stdc++.h>
using namespace std;

int shortwindow(vector<int> &v){
    int lo=0,hi=v.size()-1;
    //find the first number out of sorting order from the beginning
    while (lo<v.size()-1 && v[lo]<=v[lo+1])
        lo++;
    if (lo==v.size()-1)       //if the array is sorted
        return 0;
    //find the first number out of sorting order from the end
    while (hi>0 && v[hi]>=v[hi-1])
        hi--;
    //find the maximum and minimum of the subarray
    int subarray_max=INT_MIN;
    int subarray_min=INT_MAX;
    for(int x=lo;x<=hi;x++){
        subarray_max=max(subarray_max,v[x]);
        subarray_min=min(subarray_min,v[x]);
    }

    //extend the subarray to include any number which is bigger than the minimum of the subarray
    while (lo>0 && v[lo-1]>subarray_min)
        lo--;
    //extend the subarray to include any number which is bigger than the minimum of the subarray
    while (hi<v.size()-1 && v[hi+1]<subarray_max)
        hi++;
    return hi-lo+1;
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
    cout<<shortwindow(v)<<endl;
}
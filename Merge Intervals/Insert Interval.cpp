/*
Problem Statement #
Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.

Example 1:

Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
Output: [[1,3], [4,7], [8,12]]
Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].

Example 2:

Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,10]
Output: [[1,3], [4,12]]
Explanation: After insertion, since [4,10] overlaps with [5,7] & [8,12], we merged them into [4,12]. 

Time complexity #
As we are iterating through all the intervals only once, the time complexity of the above algorithm is O(N), where ‘N’ is the total number of intervals.

Space complexity #
The space complexity of the above algorithm will be O(N)O(N) as we need to return a list containing all the merged intervals.
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>  insert(vector<vector<int>> intervals,vector<int> new_interval){
    vector<vector<int>> merged;
    int i=0,start=0,end=1;

    //skip (and add to output) all intervals that come before the 'new_interval'
    while (i<intervals.size() && intervals[i][end]<new_interval[start]){
        merged.push_back(intervals[i]);
        i++;
    }
    
    //merge all intervals that overlap with 'new_interval'
    while (i<intervals.size() && intervals[i][start]<=new_interval[end]){
        new_interval[start]=min(intervals[i][start],new_interval[start]);
        new_interval[end]=max(intervals[i][end],new_interval[end]);
        i++;
    }
    //insert the new_interval
    merged.push_back(new_interval);

    //add all the remaining intervals to the output
    while (i<intervals.size()){
        merged.push_back(intervals[i]);
        i++;
    }
    return merged;
}

int main(){
    cout<<"Intervals after inserting the new interval: ";
    vector<vector<int>> output=insert({{1,3},{5,7},{8,12}},{4,6});
    for(auto i:output)
        cout<<"["<<i[0]<<","<<i[1]<<"]";
    cout<<endl;
    cout<<"Intervals after inserting the new interval: ";
    output=insert({{1,3},{5,7},{8,12}},{4,10});
    for(auto i:output)
        cout<<"["<<i[0]<<","<<i[1]<<"]";
    cout<<endl;
    cout<<"Intervals after inserting the new interval: ";
    output=insert({{1,3},{5,7}},{1,4});
    for(auto i:output)
        cout<<"["<<i[0]<<","<<i[1]<<"]";
    cout<<endl;
}

    
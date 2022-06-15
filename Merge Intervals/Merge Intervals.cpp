/*
Problem Statement #
Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.

Example 1:

Intervals: [[1,4], [2,5], [7,9]]
Output: [[1,5], [7,9]]
Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into 
one [1,5].

Example 2:

Intervals: [[6,7], [2,4], [5,9]]
Output: [[2,4], [5,9]]
Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].
 
Example 3:

Intervals: [[1,4], [2,6], [3,5]]
Output: [[1,6]]
Explanation: Since all the given intervals overlap, we merged them into one.
 
Time complexity #
The time complexity of the above algorithm is O(N∗logN), where ‘N’ is the total number of intervals.
We are iterating the intervals only once which will take O(N), in the beginning though, since we need to sort the intervals, our algorithm will take O(N∗logN).

Space complexity #
The space complexity of the above algorithm will be O(N) as we need to return a list containing all the merged intervals.
We will also need O(N) space for sorting.
*/ 

#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
    int start=0;
    int end=0;

    Interval(int start,int end){
        this->start=start;
        this->end=end;
    }
};

vector<Interval> merge(vector<Interval> &intervals){
    if(intervals.size()<2)
        return intervals;

    //sort the intervals by start time
    sort(intervals.begin(),intervals.end(),
    [](const Interval &x,const Interval &y){return x.start<y.start;});

    vector<Interval> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);
    int j=0;
    for(int i=0;i<intervals.size();i++){
        if(intervals[i].start<=mergedIntervals[j].end){
            mergedIntervals[j].end=max(intervals[i].end,mergedIntervals[j].end);
        }
        else{
            mergedIntervals.push_back(intervals[i]);
            j++;
        }
    }
    return mergedIntervals;
}


int main(){
    vector<Interval> input={{1,3},{2,5},{7,9}};
    cout<<"Merged intervals: ";
    for(auto i:merge(input))
        cout<<"["<<i.start<<","<<i.end<<"]";
    cout<<endl;

    input={{6,7},{2,4},{5,9}};
    cout<<"Merged intervals: ";
    for(auto i:merge(input))
        cout<<"["<<i.start<<","<<i.end<<"]";
    cout<<endl;

    input={{1,4},{2,6},{3,5}};
    cout<<"Merged intervals: ";
    for(auto i:merge(input))
        cout<<"["<<i.start<<","<<i.end<<"]";
    cout<<endl;

}
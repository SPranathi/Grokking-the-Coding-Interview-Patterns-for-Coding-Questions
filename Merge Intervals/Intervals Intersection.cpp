/*
Problem Statement #
Given two lists of intervals, find the intersection of these two lists.
Each list consists of disjoint intervals sorted on their start time.

Example 1:

Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
Output: [2, 3], [5, 6], [7, 7]
Explanation: The output list contains the common intervals between the two lists.

Example 2:

Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
Output: [5, 7], [9, 10]
Explanation: The output list contains the common intervals between the two lists.

Time complexity #
As we are iterating through both the lists once, the time complexity of the above algorithm is O(N+M), where ‘N’ and ‘M’ are the total number of intervals in the input arrays respectively.

Space complexity #
Ignoring the space needed for the result list, the algorithm runs in constant space O(1).
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

vector<Interval> merge(vector<Interval> &arr1,vector<Interval> &arr2){
    vector<Interval> res;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        //check if the interval arr[i] intersects with arr2[j]
        //check if one of the intervals start tiem lies within the other interval
        if((arr1[i].start>=arr2[j].start && arr1[i].start<=arr2[j].end)||(arr2[j].start>=arr1[i].start && arr2[j].start<=arr1[i].end)){
            //store the intersection part
            res.push_back({max(arr1[i].start,arr2[j].start),min(arr1[i].end,arr2[j].end)});
        }

        //move next from the interval which is finishing first
        if(arr1[i].end<arr2[j].end)
            i++;
        else
            j++;
    }
    return res;
}

int main(){
    vector<Interval> in1={{1,3},{5,6},{7,9}};
    vector<Interval> in2={{2,3},{5,7}};
    vector<Interval> res=merge(in1,in2);
    cout<<"Interval Intersection: ";
    for(auto i:res)
        cout<<"["<<i.start<<","<<i.end<<"]";
    cout<<endl;
    in1={{1,3},{5,7},{9,12}};
    in2={{5,10}};
    res=merge(in1,in2);
    cout<<"Interval Intersection: ";
    for(auto i:res)
        cout<<"["<<i.start<<","<<i.end<<"]";
    cout<<endl;
}

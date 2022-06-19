/*
Problem Statement #
Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.

Example 1:

Appointments: [[1,4], [2,5], [7,9]]
Output: false
Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.

Example 2:

Appointments: [[6,7], [2,4], [8,12]]
Output: true
Explanation: None of the appointments overlap, therefore a person can attend all of them.

Time complexity #
The time complexity of the above algorithm is O(N∗logN), where ‘N’ is the total number of appointments.
Though we are iterating the intervals only once, our algorithm will take O(N∗logN) since we need to sort them in the beginning.

Space complexity #
The space complexity of the above algorithm will be O(N), which we need for sorting.  
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

bool can_attend(vector<Interval> arr){
    sort(arr.begin(),arr.end(),
    [](const Interval &x,const Interval &y){return x.start<y.start;});
    for(int i=1;i<arr.size();i++){
        if(arr[i].start<arr[i-1].end){
            return false;
        }
    }
    return true;
}

int main(){
    vector<Interval> arr={{1,4},{2,5},{7,9}};
    bool res=can_attend(arr);
    cout<<"Can attend all appointments: "<<res<<endl;
    
    arr={{6,7},{2,4},{8,12}};
    res=can_attend(arr);
    cout<<"Can attend all appointments: "<<res<<endl;
    
    arr={{4,5},{2,3},{3,6}};
    res=can_attend(arr);
    cout<<"Can attend all appointments: "<<res<<endl;
    
}


/*
Problem Statement#
Given a list of intervals representing the start and end time of ‘N’ meetings, find the minimum number of rooms required to hold all the meetings.

Example 1:

Meetings: [[1,4], [2,5], [7,9]]
Output: 2
Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these two meetings.[7,9] can occur in any of the two rooms later.

Example 2:

Meetings: [[6,7], [2,4], [8,12]]
Output: 1
Explanation: None of the meetings overlap, therefore we only need one room to hold all meetings. 

Time complexity #
The time complexity of the above algorithm is O(N∗logN), where ‘N’ is the total number of meetings.
This is due to the sorting that we did in the beginning. Also, while iterating the meetings we might need to poll/offer meeting to the priority queue.
Each of these operations can take O(logN). Overall our algorithm will take O(NlogN).

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for sorting.
Also, in the worst case scenario, we’ll have to insert all the meetings into the Min Heap (when all meetings overlap) which will also take O(N) space.
The overall space complexity of our algorithm is O(N).
*/
#include<bits/stdc++.h>
using namespace std;

class Meeting{
    public:
    int start=0,end=0;
    Meeting(int start,int end){
        this->start=start;
        this->end=end;
    }
};

struct endcompare{
    bool operator()(const Meeting &x,const Meeting &y){return x.end>y.end;}
};

int min_rooms(vector<Meeting> &meetings){
    if(meetings.empty())
        return 0;

    //sort the meetings by start time
    sort(meetings.begin(),meetings.end(),
        [](const Meeting &x,const Meeting &y){return x.start<y.start;});

    int minRooms=0;
    priority_queue<Meeting,vector<Meeting>,endcompare>  minHeap;
    for (auto meeting:meetings){
        //remove all teh meetings that have ended
        while(!minHeap.empty() && meeting.start>=minHeap.top().end)
            minHeap.pop();
        //add the current meeting into min_heap
        minHeap.push(meeting);
        //all active meetings are in the min_heap,so we need rooms for all of them
        minRooms=max(minRooms,(int)minHeap.size());
    }
    return minRooms;
}

int main(){
    vector<Meeting> arr={{4,5},{2,3},{2,4},{3,5}};
    int res=min_rooms(arr);
    cout<<"Minimum meeting rooms required: "<<res<<endl;
    
    arr={{1,4},{2,5},{7,9}};
    res=min_rooms(arr);
    cout<<"Minimum meeting rooms required: "<<res<<endl;
    
    arr={{6,7},{2,4},{8,12}};
    res=min_rooms(arr);
    cout<<"Minimum meeting rooms required: "<<res<<endl;
    
}

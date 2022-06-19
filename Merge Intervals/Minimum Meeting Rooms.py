"""
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
"""

from heapq import heappop,heappush

class Meeting:
    def __init__(self,start,end):
        self.start=start
        self.end=end

    def __lt__(self,other):
        #min heap based on meeting.end
        return self.end<other.end


def min_rooms(meetings):
    #sort the meetings by start time
    meetings.sort(key=lambda x:x.start)

    minRooms=0
    minheap=[]
    for meeting in meetings:
        #remove all teh meetings that have ended
        while len(minheap)>0 and meeting.start>=minheap[0].end:
            heappop(minheap)
        #add the current meeting into min_heap
        heappush(minheap,meeting)
        #all active meetings are in the min_heap,so we need rooms for all of them
        minRooms=max(minRooms,len(minheap))
    return minRooms
def main():
    print("Minimum meeting rooms required: "+
        str(min_rooms([Meeting(4,5),Meeting(2,3),Meeting(2,4),Meeting(3,5)])))
    print("Minimum meeting rooms required: "+
        str(min_rooms([Meeting(1,4),Meeting(2,5),Meeting(7,9)])))
    print("Minimum meeting rooms required: "+
        str(min_rooms([Meeting(6,7),Meeting(2,4),Meeting(8,12)])))
    print("Minimum meeting rooms required: "+
        str(min_rooms([Meeting(1,4),Meeting(2,3),Meeting(3,6)])))


main()
"""
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
"""

class Interval:
    def __init__(self,start,end):
        self.start=start
        self.end=end
    
    def print_interval(self):
        print("["+str(self.start)+","+str(self.end)+"]",end=" ")

def  merge(intervals):
    if(len(intervals)<2):
        return intervals

    #sort the intervals by start time
    intervals.sort(key=lambda x:x.start)

    mergedIntervals=[]
    mergedIntervals.append(Interval(intervals[0].start,intervals[0].end))
    j=0
    for i in range(1,len(intervals)):
        if(intervals[i].start<=mergedIntervals[j].end):     #overlapping interval
            mergedIntervals[j].end=max(intervals[i].end,mergedIntervals[j].end)
        
        else:
            mergedIntervals.append(Interval(intervals[i].start,intervals[i].end))
            j+=1
        
    return mergedIntervals


def main():
    print("Merged intervals: ",end='')
    for i in merge([Interval(1,4),Interval(2,5),Interval(7,9)]):
        i.print_interval()
    print()

    print("Merged intervals: ",end='')
    for i in merge([Interval(6,7),Interval(2,4),Interval(5,9)]):
        i.print_interval()
    print()

    print("Merged intervals: ",end='')
    for i in merge([Interval(1,4),Interval(2,6),Interval(3,5)]):
        i.print_interval()
    print()

main()
    
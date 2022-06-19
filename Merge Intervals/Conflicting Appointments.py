"""
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
"""

def attend_all(intervals):
    intervals.sort(key=lambda x:x[0])
    start,end=0,1
    for i in range(1,len(intervals)):
        if intervals[i][start]<intervals[i-1][end]:
            return False
    return True

def main():
    print(str(attend_all([[1,4],[2,5],[7,9]])))
    print(str(attend_all([[6,7],[2,4],[8,12]])))
    print(str(attend_all([[4,5],[2,3],[3,6]])))

main()
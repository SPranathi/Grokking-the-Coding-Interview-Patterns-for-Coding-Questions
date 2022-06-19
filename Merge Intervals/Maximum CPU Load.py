"""
Problem Statement#
We are given a list of Jobs.Each job has a Start time, an End time, and a CPU load when it is running.
Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.

Example 1:

Jobs: [[1,4,3], [2,5,4], [7,9,6]]
Output: 7
Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the 
jobs are running at the same time i.e., during the time interval (2,4).

Example 2:

Jobs: [[6,7,10], [2,4,11], [8,12,15]]
Output: 15
Explanation: None of the jobs overlap, therefore we will take the maximum load of any job which is 15. 

Time complexity #
The time complexity of the above algorithm is O(N∗logN), where ‘N’ is the total number of jobs. This is due to the sorting that we did in the beginning.
Also, while iterating the jobs, we might need to poll/offer jobs to the priority queue. Each of these operations can take O(logN). Overall our algorithm will take O(NlogN).

Space complexity #
The space complexity of the above algorithm will be O(N), which is required for sorting. Also, in the worst case, we have to insert all the jobs into the priority queue (when all jobs overlap) which will also take O(N) space.
The overall space complexity of our algorithm is O(N).
""" 
from heapq import heappop,heappush

class Job:
    def __init__(self,start,end,load):
        self.start=start
        self.end=end
        self.load=load

    def __lt__(self,other):
        #min heap based on meeting.end
        return self.end<other.end


def maxCPUload(jobs):
    #sort the meetings by start time
    jobs.sort(key=lambda x:x.start)

    maxcpuload,curcpuload=0,0
    minheap=[]
    for job in jobs:
        #remove all jobs that have ended
        while len(minheap)>0 and job.start>=minheap[0].end:
            curcpuload-=minheap[0].load
            heappop(minheap)
        #add the current job into min_heap
        heappush(minheap,job)
        curcpuload+=job.load
        maxcpuload=max(maxcpuload,curcpuload)
    return maxcpuload

def main():
    print("Minimum cpu load at any time: "+
        str(maxCPUload([Job(1,4,3),Job(7,9,6),Job(2,5,4)])))
    print("Minimum cpu load at any time: "+
        str(maxCPUload([Job(6,7,10),Job(8,12,15),Job(2,4,11)])))
    print("Minimum cpu load at any time: "+
        str(maxCPUload([Job(1,4,2),Job(3,6,5),Job(2,4,1)])))
    

main()

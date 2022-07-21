/*Problem Statement #

Design a class to calculate the median of a number stream. The class should have the following two methods:

    insertNum(int num): stores the number in the class
    findMedian(): returns the median of all numbers inserted in the class

If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers. 

Time complexity #

The time complexity of the insertNum() will be O(logN) due to the insertion in the heap. The time complexity of the findMedian() will be O(1) as we can find the median from the top elements of the heaps.

Space complexity #

The space complexity will be O(N) because, as at any time, we will be storing all the numbers.
*/
#include<bits/stdc++.h>
using namespace std;

class Median{
    public:
    priority_queue<int> maxheap;    //contains first half
    priority_queue<int,vector<int>,greater<int>> minheap;   //contains second half

    void insertNum(int val){
        if(maxheap.empty() || maxheap.top()>=val)
            maxheap.push(val);
        else
            minheap.push(val);

        if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(maxheap.size()<minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian(){
        if(minheap.size()==maxheap.size()){
            return minheap.top()/2.0+maxheap.top()/2.0;
        }
        return maxheap.top();
    }
    
};


int main(){
    Median m;
    m.insertNum(3);
    m.insertNum(1);
    cout<<"The median is:"<<m.findMedian()<<endl;
    m.insertNum(5);
    cout<<"The median is:"<<m.findMedian()<<endl;
    m.insertNum(4);
    cout<<"The median is:"<<m.findMedian()<<endl;
}

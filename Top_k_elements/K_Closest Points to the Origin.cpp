/*
Problem Statement #

Given an array of points in the a 2D2D2D plane, find ‘K’ closest points to the origin.

Example 1:

Input: points = [[1,2],[1,3]], K = 1
Output: [[1,2]]
Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
The Euclidean distance between (1, 3) and the origin is sqrt(10).
Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.

Time complexity #

The time complexity of this algorithm is (N*logK) as we iterating all points and pushing them into the heap.
Space complexity #

The space complexity will be O(K) because we need to store ‘K’ point in the heap.
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Point{
    public:
    int x=0,y=0;

    Point(int x,int y){
        this->x=x;
        this->y=y;
    }

    int distFromOrigin() const{
        return (x*x)+(y*y);
    }

    const bool operator<(const Point &p){
        return p.distFromOrigin()>this->distFromOrigin();
    }
};

vector<Point>  KPointsFromOrigin(vector<Point> points,int k){
    vector<Point> maxheap(points.begin(),points.begin()+k);
    make_heap(maxheap.begin(),maxheap.end());

    for(int i=0;i<points.size();i++){
        if(points[i].distFromOrigin()<maxheap.front().distFromOrigin()){
            pop_heap(maxheap.begin(),maxheap.end());
            maxheap.pop_back();
            maxheap.push_back(points[i]);
            push_heap(maxheap.begin(),maxheap.end());

        }
    }
    return maxheap;
}

int main(){
    vector<Point> maxheap=KPointsFromOrigin({{1,3},{3,4},{2,-1}},2);
    for(auto p:maxheap)
        cout<<"["<<p.x<<","<<p.y<<"]"<<endl;
}
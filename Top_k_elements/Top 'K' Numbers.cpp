/*
Problem Statement #

Given an unsorted array of numbers, find the ‘K’ largest numbers in it.

Example 1:

Input: [3, 1, 5, 12, 2, 11], K = 3
Output: [5, 12, 11] 

Time complexity #

As discussed above, the time complexity of this algorithm is O(K*logK+(N-K)*logK), which is asymptotically equal to O(N*logK)
Space complexity #

The space complexity will be O(K) since we need to store the top ‘K’ numbers in the heap.
*/
#include<bits/stdc++.h>
using namespace std;

class KLargestNumbers{
    public:
    // comparator function to make min heap
    struct greater{
    bool operator()(const int& a,const int& b) const{
    return a>b;
    }
    };

    vector<int> findKLargestelements(vector<int> arr,int k){
        //first k elements in minheap
        vector<int> minheap(arr.begin(),arr.begin()+k);
        make_heap(minheap.begin(),minheap.end(),greater());

        //go through remaining elements
        for(int i=k;i<arr.size();i++){
            if(arr[i]>minheap.front()){
                pop_heap(minheap.begin(),minheap.end(),greater());
                minheap.pop_back();
                minheap.push_back(arr[i]);
                push_heap(minheap.begin(),minheap.end(),greater());
            }
        }
        return minheap;
    }
};

int main(){
    KLargestNumbers k;
    vector<int> res=k.findKLargestelements(vector<int> {3,1,5,12,2,11},3);
    cout<<"Top k elements: ";
    for(auto i:res)
        cout<<i<<" ";
    cout<<endl;
    res=k.findKLargestelements(vector<int> {5,12,-1,11,12},3);
    cout<<"Top k elements: ";
    for(auto i:res)
        cout<<i<<" ";
    cout<<endl;
}

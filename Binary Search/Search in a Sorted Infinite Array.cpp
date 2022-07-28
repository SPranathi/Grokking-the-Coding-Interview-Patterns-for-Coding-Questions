/*
Problem Statement #

Given an infinite sorted array (or an array with unknown size), find if a given number ‘key’ is present in the array. Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.

Since it is not possible to define an array with infinite (unknown) size, you will be provided with an interface ArrayReader to read elements of the array.
ArrayReader.get(index) will return the number at index; if the array’s size is smaller than the index, it will return Integer.MAX_VALUE.

Example 1:

Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
Output: 6
Explanation: The key is present at index '6' in the array.

Example 2:

Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 11
Output: -1
Explanation: The key is not present in the array.

Time complexity #

There are two parts of the algorithm.In the first part, we keep increasing the bound’s size exponentially (double it every time) while searching for the proper bounds.
Therefore, this step will take O(logN) assuming that the array will have maximum ‘N’ numbers. In the second step, we perform the binary search which will take O(logN),
so the overall time complexity of our algorithm will be O(logN+logN) which is asymptotically equivalent to O(logN).
Space complexity #

The algorithm runs in constant space O(1).

*/
#include<bits/stdc++.h>
using namespace std;

class ArrayReader{
    public:
    vector<int> arr;
    ArrayReader(const vector<int> &arr){
        this->arr=arr;
    }

    int get(int index){
        if(index>=arr.size()){
            return numeric_limits<int>::max();
        }
        return arr[index];
    }
};

int binarysearch(ArrayReader *reader,int key,int start,int end){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(key<reader->get(mid)){
            end=mid-1;
        }
        else if(key>reader->get(mid)){
            start=mid+1;
        }
        else
            return mid;
    }
    return -1;
}

int search(ArrayReader *reader,int key){
    int start=0,end=1;
    while(reader->get(end)<key){
        int newstart=end+1;
        end+=(end-start+1)*2; //increase to double bounds
        start=newstart;
    }
    return binarysearch(reader,key,start,end);
}


int main(){
    ArrayReader *reader=new ArrayReader(vector<int> 
    {4,6,8,10,12,14,16,18,20,22,24,26,28,30});
    cout<<search(reader,16)<<endl;
    cout<<search(reader,11)<<endl;
}

/*
Problem Statement #
We are given an array containing ‘n’ objects. Each object, when created, was assigned a unique number from 1 to ‘n’ based on their creation sequence. This means that the object with sequence number ‘3’ was created just before the object with sequence number ‘4’.

Write a function to sort the objects in-place on their creation sequence number in O(n)O(n) and without any extra space. For simplicity, let’s assume we are passed an integer array containing only the sequence numbers, though each number is actually an object.

Example 1:

Input: [3, 1, 5, 4, 2]
Output: [1, 2, 3, 4, 5]
Example 2:

Input: [2, 6, 4, 3, 1, 5]
Output: [1, 2, 3, 4, 5, 6]

Time complexity #
The time complexity of the above algorithm is O(n).
Although we are not incrementing the index i when swapping the numbers, this will result in more than ‘n’ iterations of the loop, but in the worst-case scenario, the while loop will swap a total of ‘n-1’ numbers and once a number is at its correct index, we will move on to the next number by incrementing i.
So overall, our algorithm will take O(n)+O(n-1) which is asymptotically equivalent to O(n).

Space complexity #
The algorithm runs in constant space O(1). 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> v;
    while(ss>>x){
        v.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }

    int i=0;
    while(i<v.size()){
        int j=v[i]-1;
        if(v[i]!=v[j])
            swap(v[i],v[j]);
        else
            i++;
    }
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
}
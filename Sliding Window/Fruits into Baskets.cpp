/*
Problem Statement #
Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. 
The only restriction is that each basket can have only one type of fruit.
You can start with any tree, but once you have started you can’t skip a tree.
You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.

Write a function to return the maximum number of fruits in both the baskets.

Example 1:

Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
Example 2:

Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket. 
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']

Time Complexity #
The time complexity of the above algorithm will be O(N)O(N) where ‘N’ is the number of characters in the input array. The outer for loop runs for all characters and the inner while loop processes each character only once, therefore the time complexity of the algorithm will be O(N+N)O(N+N) which is asymptotically equivalent to O(N)O(N).

Space Complexity #
The algorithm runs in constant space O(1)O(1) as there can be a maximum of three types of fruits stored in the frequency map.
*/

#include<bits/stdc++.h>
using namespace std;

int MaxFruitCount(vector<char> v){
    unordered_map<char,int> umap; //for character frequency
    int start=0,maxlength=0;
    for(int i=0;i<v.size();i++){
        umap[v[i]]++;
        //shrink the sliding window ,until we are left with 2 fruits in the frequency map
        while(umap.size()>2){
            umap[v[start]]-=1;
            if(umap[v[start]]==0)
                umap.erase(v[start]);
            start+=1;
        }
        maxlength=max(maxlength,i-start+1);
    }
    return maxlength;
}

int main(){
    string input;
    getline(cin,input);
    istringstream is(input);
    vector<char> v((istream_iterator<char>(is)),istream_iterator<char>());
    cout<<"Maximum number of Fruits: "<<MaxFruitCount(v)<<endl;
} 

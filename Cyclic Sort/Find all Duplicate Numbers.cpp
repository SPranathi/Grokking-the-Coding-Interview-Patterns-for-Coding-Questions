 /*
Problem Statement #
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array has some duplicates, find all the duplicate numbers without using any extra space.

Example 1:

Input: [3, 4, 4, 5, 5]
Output: [4, 5]
Example 2:

Input: [5, 4, 7, 2, 3, 5, 3]
Output: [3, 5]

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
Ignoring the space required for storing the duplicates, the algorithm runs in constant space O(1).
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> duplicate_numbers(vector<int> v){
    int i=0,n=v.size();
    while(i<n){
        int j=v[i]-1;
        if(v[i]!=v[j])
            swap(v[i],v[j]);
        else
            i++;
    }
    vector<int> ans;
    for(int k=0;k<n;k++){
        if(v[k]!=k+1)
            ans.push_back(v[k]);
    }
    return ans;
}

int main(){
    vector<int> v;
    int x;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss>>x){
        v.push_back(x);
        if(ss.peek()==' ')
            ss.ignore();
    }
    vector<int> ans=duplicate_numbers(v);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
}


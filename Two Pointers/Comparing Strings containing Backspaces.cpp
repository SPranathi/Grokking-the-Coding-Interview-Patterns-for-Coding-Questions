/*
Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.

Example 1:

Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.

Example 2:

Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively. 

Time complexity #
The time complexity of the above algorithm will be O(M+N) where ‘M’ and ‘N’ are the lengths of the two input strings respectively.

Space complexity #
The algorithm runs in constant space O(1).

*/
#include<bits/stdc++.h>
using namespace std;

int NextvalidIndex(string s,int index){
    int backspacecount=0;
    while(index>=0){
        if(s[index]=='#')       //found a backspace character
            backspacecount++;
        else if(backspacecount>0)   //a non backspace character
            backspacecount--;
        else
            break;
        index--;    //skip a backspace or a valid character
    }
    return index;
}

bool compare(string s1,string s2){
    int index1=s1.length()-1,index2=s2.length()-1;
    while(index1>=0 || index2>=0){
        //use two pointer approach to compare the strings
        int i1=NextvalidIndex(s1,index1);
        int i2=NextvalidIndex(s2,index2);

        if(i1<0 && i2<0){ //reached the end of both the strings
            return true;
        }
        if(i1<0 || i2<0){ //reached the end of one the  string
            return false;
        }

        if(s1[i1]!=s2[i2])      //check if the characters are equal
            return false;

        index1=i1-1;
        index2=i2-1;
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(compare(s1,s2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}
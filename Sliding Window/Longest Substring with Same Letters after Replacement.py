"""
Problem Statement #
Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter, find the length of the longest substring having the same letters after replacement.

Example 1:

Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
Example 2:

Input: String="abbcb", k=1
Output: 4
Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".

Time Complexity #
The time complexity of the above algorithm will be O(N) where ‘N’ is the number of letters in the input string.

Space Complexity #
As we are expecting only the lower case letters in the input string, we can conclude that the space complexity will be O(26), to store each letter’s frequency in the HashMap, which is asymptotically equal to O(1).

""" 
def characterReplacement(s,k):
    start,maxlength,maxrepeatchar=0,0,0
    freqmap={}
    for i in range(len(s)):
        curstr=s[i]
        if curstr not in freqmap:
            freqmap[curstr]=0
        freqmap[curstr]+=1
        maxrepeatchar=max(maxrepeatchar,freqmap[curstr])

        if(i-start+1-maxrepeatchar)>k:
            freqmap[s[start]]-=1
            start+=1

        maxlength=max(maxlength,i-start+1)

    return maxlength

def main():
    s=input()
    k=int(input())
    print(characterReplacement(s,k))
main()
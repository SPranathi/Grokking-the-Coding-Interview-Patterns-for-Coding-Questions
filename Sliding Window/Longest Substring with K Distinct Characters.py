"""
Problem Statement #
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
Example 2:

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

Time Complexity #
The time complexity of the above algorithm will be O(N)O(N) where ‘N’ is the number of characters in the input string.
The outer for loop runs for all characters and the inner while loop processes each character only once, therefore the time complexity of the algorithm will be O(N+N)O(N+N) which is asymptotically equivalent to O(N)O(N).

Space Complexity #
The space complexity of the algorithm is O(K)O(K), as we will be storing a maximum of ‘K+1’ characters in the HashMap.
"""
def longest_substring(k,st):
    d={} #for character frequency
    start,maxsubstring=0,0
    for i in range(len(st)):
        s=st[i]
        if s not in d:
            d[s]=0
        d[s]+=1
        #shrink the sliding window ,until we are left with k distinct characters in the d
        while len(d)>k:
            d[st[start]]-=1
            if d[st[start]]==0:
                del d[st[start]]
            start+=1
        maxsubstring=max(maxsubstring,i-start+1)
    return maxsubstring


def main():
    st=input()
    k=int(input())
    print("Length of the longest substring: ",longest_substring(k,st))
main()
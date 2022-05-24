"""
Problem Statement #
Given a string, find the length of the longest substring which has no repeating characters.

Example 1:

Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".
Example 2:

Input: String="abbbb"
Output: 2
Explanation: The longest substring without any repeating characters is "ab".

Time Complexity #
The time complexity of the above algorithm will be O(N) where ‘N’ is the number of characters in the input string.

Space Complexity #
The space complexity of the algorithm will be O(K) where K is the number of distinct characters in the input string.
This also means K<=N, because in the worst case, the whole string might not have any repeating character so the entire string will be added to the HashMap. Having said that,
since we can expect a fixed set of characters in the input string (e.g.,26 for English letters), we can say that the algorithm runs in fixed space O(1);
in this case, we can use a fixed-size array instead of the HashMap.
"""
def non_repeat_substring(s):
    start,maxlength=0,0
    charindex={}
    for i in range(len(s)):
        ch=s[i]
        #if the map already contains the char, shrink the window from the begining so that we have only one occurrence of char
        if ch in charindex:
            start=max(start,charindex[ch]+1)
        charindex[ch]=i
        maxlength=max(maxlength,i-start+1)
    return maxlength

def main():
    s=input()
    print(non_repeat_substring(s))

main()
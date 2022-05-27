"""
Problem Statement #

Given a string and a pattern, find all anagrams of the pattern in the given string.

Anagram is actually a Permutation of a string. For example, “abc” has the following six anagrams:
abc
acb
bac
bca
cab
cba
Write a function to return a list of starting indices of the anagrams of the pattern in the given string.

Example 1:

Input: String="ppqp", Pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".
Example 2:

Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc". 

Time Complexity #
The time complexity of the above algorithm will be O(N+M) where ‘N’ and ‘M’ are the number of characters in the input string and the pattern respectively.

Space Complexity #
The space complexity of the algorithm is O(M) since in the worst case, the whole pattern can have distinct characters which will go into the HashMap.
In the worst case, we also need O(N)O(N) space for the result list, this will happen when the pattern has only one character and the string contains only that character.
"""

def stringanagrams(s,p):
    start=matched=0
    freqmap={}

    for i in p:
        if i not in freqmap:
            freqmap[i]=0
        freqmap[i]+=1

    res=[]
    for i in range(len(s)):
        if s[i] in freqmap:
            freqmap[s[i]]-=1   #decrement the frequency of the matched character
            if(freqmap[s[i]]==0):        #character is completely matched
                matched+=1

        if(matched==len(freqmap)):
            res.append(start)

        if(i>=len(p)-1):           #shrink the window
            if s[start] in freqmap:
                if(freqmap[s[start]]==0):
                    matched-=1          #before putting the character back, decrement the matched count
                freqmap[s[start]]+=1
            start+=1
    return res

def main():
    s,p=input().split()
    res=stringanagrams(s,p)
    print(res)

main()
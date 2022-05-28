"""
Problem Statement #
Given a string and a list of words, find all the starting indices of substrings in the given string that are a concatenation of all the given words exactly once without any overlapping of words. It is given that all words are of the same length.

Example 1:

Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" & "foxcat".

Example 2:

Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3]
Explanation: The only substring containing both the words is "catfox".

Time Complexity #
The time complexity of the above algorithm will be O(N∗M∗Len) where ‘N’ is the number of characters in the given string, ‘M’ is the total number of words, and ‘Len’ is the length of a word.

Space Complexity #
The space complexity of the algorithm is O(M) since at most, we will be storing all the words in the two HashMaps.In the worst case, we also need O(N) space for the resulting list.
So, the overall space complexity of the algorithm will be O(M+N).
"""

def findwordConcatenation(s,words):
    if len(words)==0 or len(words[0])==0:
        return []
    word_freq={}
    for i in words:
        if i not in word_freq:
            word_freq[i]=0
        word_freq[i]+=1
    
    res=[]
    words_count=len(words)
    word_len=len(words[0])

    for i in range((len(s)-words_count*word_len)+1):
        words_seen={}
        for j in range(0,words_count):
            next_index=i+j*word_len
            #Get the next word from the string
            word=s[next_index:next_index+word_len]
            if word not in word_freq:   #Break if we don't need this word
                break
            #Add the word to the words_seen map
            if word not in words_seen:
                words_seen[word]=0
            words_seen[word]+=1

            #No need to process further if the word has higher frequency than required
            if words_seen[word]>word_freq.get(word,0):
                break

            if j+1==words_count:    #Store index if we have found all the words 
                res.append(i)
    return res

def main():
    s=input()
    words=list(input().split())
    print(findwordConcatenation(s,words))

main()

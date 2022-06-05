"""
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
"""

def NextvalidIndex(s,index):
    backspacecount=0
    while(index>=0):
        if s[index]=='#':       #found a backspace character
            backspacecount+=1
        elif backspacecount>0:   #a non backspace character
            backspacecount-=1
        else:
            break
        index-=1    #skip a backspace or a valid character
    return index

def compare(s1,s2):
    index1=len(s1)-1
    index2=len(s2)-1
    while index1>=0 or index2>=0:
        #use two pointer approach to compare the strings
        i1=NextvalidIndex(s1,index1)
        i2=NextvalidIndex(s2,index2)

        if i1<0 and i2<0:   #reached the end of both the strings
            return True
        
        if i1<0 or i2<0:   #reached the end of one the  string
            return False

        if s1[i1]!=s2[i2]:      #check if the characters are equal
            return False

        index1=i1-1
        index2=i2-1
    return True

def main():
    s1,s2=input().split()
    print(compare(s1,s2))

main()
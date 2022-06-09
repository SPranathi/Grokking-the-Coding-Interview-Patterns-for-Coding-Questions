"""
Palindrome LinkedList #
Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.

Your algorithm should use constant space and the input LinkedList should be in the original form once the algorithm is finished. The algorithm should have O(N)O(N) time complexity where ‘N’ is the number of nodes in the LinkedList.

Example 1:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true
Example 2:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
Output: false

Time complexity #
The above algorithm will have a time complexity of O(N) where ‘N’ is the number of nodes in the LinkedList.

Space complexity #
The algorithm runs in constant space O(1).
"""

class Node:
    def __init__(self,value,next=None):
        self.value=value
        self.next=next

def reverse(head):
    prev=None
    while head:
        next=head.next
        head.next=prev
        prev=head
        head=next
    return prev

def palindrome(head):
    if head==None or head.next==None:
        return True

    #find the middle of the linkedlist
    slow=fast=head
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next

    secondhalf=reverse(slow)     #reverse the second half
    secondheadcopy=secondhalf    #store the head of reversed part to revert back later

    #compare the first and second half
    while head and secondhalf:
        if head.value!=secondhalf.value :
            break  #not a palindrome
        head=head.next
        secondhalf=secondhalf.next
    reverse(secondheadcopy)
    if head==None or secondhalf==None:
        return True
    return False

def main():
    head=Node(2)
    head.next=Node(4)
    head.next.next=Node(6)
    head.next.next.next=Node(4)
    head.next.next.next.next=Node(2)
    print(str(palindrome(head)))
    head.next.next.next.next.next=Node(2)
    print(str(palindrome(head)))


main()
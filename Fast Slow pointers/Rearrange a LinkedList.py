"""
Rearrange a LinkedList  #
Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order. So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.

Your algorithm should not use any extra space and the input LinkedList should be modified in-place.

Example 1:

Input: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> null
Output: 2 -> 12 -> 4 -> 10 -> 6 -> 8 -> null 
Example 2:

Input: 2 -> 4 -> 6 -> 8 -> 10 -> null
Output: 2 -> 10 -> 4 -> 8 -> 6 -> null

Time Complexity #
The above algorithm will have a time complexity of OO(N) where ‘N’ is the number of nodes in the LinkedList.

Space Complexity #
The algorithm runs in constant space O(1).
"""

class Node:
    def __init__(self,value,next=None):
        self.value=value
        self.next=next

    def print_list(self):
        temp=self
        while temp:
            print(str(temp.value)+" ",end='')
            temp=temp.next
        print()

def reverse(head):
    prev=None
    while head:
        next=head.next
        head.next=prev
        prev=head
        head=next
    return prev

def reorder(head):
    if head==None or head.next==None:
        return
    #find the middle of the linkedlist
    slow=fast=head
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next
    #slow is now pointing to the middle node
    rhead=reverse(slow)     #reverse the second half
    fhead=head
    #rearrange to produce the linkedlist in the required order
    while fhead and rhead:
        temp=fhead.next
        fhead.next=rhead
        fhead=temp

        temp=rhead.next
        rhead.next=fhead
        rhead=temp
    
    #set the next of the last node to 'None'
    if fhead:
        fhead.next=None

def main():
    head=Node(2)
    head.next=Node(4)
    head.next.next=Node(6)
    head.next.next.next=Node(8)
    head.next.next.next.next=Node(10)
    head.next.next.next.next.next=Node(12)
    reorder(head)
    head.print_list()

main()
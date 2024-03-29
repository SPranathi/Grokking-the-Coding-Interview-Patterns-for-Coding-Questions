""" 
Problem Statement #
Given the head of a Singly LinkedList, write a method to return the middle node of the LinkedList.

If the total number of nodes in the LinkedList is even, return the second middle node.

Example 1:

Input: 1 -> 2 -> 3 -> 4 -> 5 -> null
Output: 3
Example 2:

Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
Output: 4

Time complexity #
The above algorithm will have a time complexity of O(N) where ‘N’ is the number of nodes in the LinkedList.

Space complexity #
The algorithm runs in constant space O(1).
"""
class Node:
    def __init__(self,value,next=None):
        self.value=value
        self.next=next

def find_middle(head):
    slow=fast=head
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next
    return slow

def main():
    head=Node(1)
    head.next=Node(2)
    head.next.next=Node(3)
    head.next.next.next=Node(4)
    head.next.next.next.next=Node(5)

    print(str(find_middle(head).value))
    head.next.next.next.next.next=Node(6)
    print(str(find_middle(head).value))

main()

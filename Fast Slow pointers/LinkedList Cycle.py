"""
Problem Statement #
Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.
Given the head of a LinkedList with a cycle, find the length of the cycle.
Example: 
head 
Following LinkedList has a cycle: head->1->2->3->4->5->6
                                               ^        |
                                               |________|   
Following LinkedList doesn't have a cycle: 
head->2->4->6->8->10->null 

Time and Space Complexity: The above algorithm runs in O(N)O(N) time complexity and O(1)O(1) space complexity.
"""
class Node:
    def __init__(self,value,next=None):
        self.value=value
        self.next=next

def has_cycle(head):
    slow=fast=head
    while fast is not None and fast.next is not None:
        fast=fast.next.next
        slow=slow.next
        if fast==slow:
            return cycle_length(slow)
    return 0

def cycle_length(slow):
    current=slow
    cycle_len=0
    while True:
        current=current.next
        cycle_len+=1
        if current==slow:
            break
    return cycle_len

def main():
    head=Node(1)
    head.next=Node(2)
    head.next.next=Node(3)
    head.next.next.next=Node(4)
    head.next.next.next.next=Node(5)
    head.next.next.next.next.next=Node(6)
    head.next.next.next.next.next.next=head.next.next
    print(has_cycle(head))


main()
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

Time and Space Complexity: The above algorithm runs in O(N) time complexity and O(1) space complexity.
"""
class Node:
    def __init__(self,value,next=None):
        self.value=value
        self.next=next

def find_cycle_start(head):
    cycle_len=0
    slow=fast=head
    while fast is not None and fast.next is not None:
        fast=fast.next.next
        slow=slow.next
        if fast==slow:
            cycle_len=cycle_length(slow)
            break
    return find_start(head,cycle_len)

def cycle_length(slow):
    current=slow
    cycle_len=0
    while True:
        current=current.next
        cycle_len+=1
        if current==slow:
            break
    return cycle_len

def find_start(head,cycle_len):
    ptr1=ptr2=head
    #move ptr2 ahead 'cycle_length' nodes
    while cycle_len>0:
        ptr2=ptr2.next
        cycle_len-=1
    while ptr1!=ptr2:
        ptr1=ptr1.next
        ptr2=ptr2.next
    return ptr1

def main():
    head=Node(1)
    head.next=Node(2)
    head.next.next=Node(3)
    head.next.next.next=Node(4)
    head.next.next.next.next=Node(5)
    head.next.next.next.next.next=Node(6)
    head.next.next.next.next.next.next=head.next.next
    print(str(find_cycle_start(head).value))


main()
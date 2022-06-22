"""
Problem Statement #
Given the head of a Singly LinkedList, reverse the LinkedList. Write a function to return the new head of the reversed LinkedList.

Example:
input: 2->4->6->8>10
output:10->8->6->4->2

Time complexity #
The time complexity of our algorithm will be O(N) where ‘N’ is the total number of nodes in the LinkedList.

Space complexity #
We only used constant space, therefore, the space complexity of our algorithm is O(1).
"""

class Node:
    def __init__(self,value,next=None):
        self.value=value
        self.next=next
    
    def print_list(self):
        temp=self
        while temp:
            print(temp.value,end=" ")
            temp=temp.next
        print()

def reverse(head):
    prev,cur,next=None,head,None
    while cur:
        next=cur.next
        cur.next=prev
        prev=cur
        cur=next
    return prev

def main():
    head=Node(2)
    head.next=Node(4)
    head.next.next=Node(6)
    head.next.next.next=Node(8)
    head.next.next.next.next=Node(10)
    print("Nodes of original LinkedList are: ",end=' ')
    head.print_list()
    result=reverse(head)
    print("Nodes of reversed LinkedList are: ",end=' ')
    result.print_list()

main()
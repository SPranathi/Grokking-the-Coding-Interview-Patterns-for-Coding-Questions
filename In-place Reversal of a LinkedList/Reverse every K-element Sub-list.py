"""
Problem Statement #
Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ sized sub-list starting from the head.

If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.

Example:
input:1 2 3 4 5 6 7 8
k=3
output:3 2 1 6 5 4 8 7

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
        while temp is not None:
            print(temp.value,end=" ")
            temp=temp.next
        print()

def reverse_k_elements(head,k):
    if k<=1 or head is None:
        return head

    prev,cur=None,head
    while True:
        last_node_of_prev_part=prev
        #after reversing the LinkedList 'cur' will become the last node
        last_node_of_sub_list=cur
        next=None
        i=0
    
        #reverse nodes 
        while cur and i<k:
            next=cur.next
            cur.next=prev
            prev=cur
            cur=next
            i+=1

        #connect with previous part
        if last_node_of_prev_part is not None:
            last_node_of_prev_part.next=prev
        else:
            head=prev
        #connect with the next part
        last_node_of_sub_list.next=cur

        if cur is None:
            break
        prev=last_node_of_sub_list
    return head

def main():
    head=Node(1)
    head.next=Node(2)
    head.next.next=Node(3)
    head.next.next.next=Node(4)
    head.next.next.next.next=Node(5)
    head.next.next.next.next.next=Node(6)
    head.next.next.next.next.next.next=Node(7)
    head.next.next.next.next.next.next.next=Node(8)
    print("Nodes of original LinkedList are: ",end=' ')
    head.print_list()
    result=reverse_k_elements(head,3)
    print("Nodes of reversed LinkedList are: ",end=' ')
    result.print_list()

main()
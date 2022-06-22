"""
Problem Statement #
Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.

Example:
input: 1->2->3->4->5
p=2
q=4
output:
1->4->3->2->5

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

def reverse_sub_list(head,p,q):
    if p==q:
        return head

    #after skipping 'p-1' nodes, current will point to pth node
    prev,cur=None,head
    i=0
    while cur and i<p-1:
        prev=cur
        cur=cur.next
        i+=1

    last_node_of_first_part=prev
    last_node_of_sub_list=cur

    next=None
    #reverse nodes between p and q
    while cur and i<q:
        next=cur.next
        cur.next=prev
        prev=cur
        cur=next
        i+=1

    #connect with first part
    if last_node_of_first_part is not None:
        last_node_of_first_part.next=prev
    else:
        head=prev
    #connect with the last part
    last_node_of_sub_list.next=cur
    return head

def main():
    head=Node(1)
    head.next=Node(2)
    head.next.next=Node(3)
    head.next.next.next=Node(4)
    head.next.next.next.next=Node(5)
    print("Nodes of original LinkedList are: ",end=' ')
    head.print_list()
    result=reverse_sub_list(head,2,4)
    print("Nodes of reversed LinkedList are: ",end=' ')
    result.print_list()

main()
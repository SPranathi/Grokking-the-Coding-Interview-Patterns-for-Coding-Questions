"""
Problem Statement
Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.

Example:
input:1 2 3 4 5
k=8
output:3 4 5 1 2 

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

def rotate(head,k):
    if k<=0 or head is None or head.next is None:
        return head

    #find length and last node of the linked list
    last_node=head
    length=1
    while last_node.next:
        last_node=last_node.next
        length+=1

    last_node.next=head #connect last node to head
    rotations=k%length
    skip_len=length-rotations
    last_node_of_rotated_list=head
    for _ in range(skip_len-1):
        last_node_of_rotated_list=last_node_of_rotated_list.next
    
    #last_node_of_rotated_list is pointing to the k ending nodes
    head=last_node_of_rotated_list.next
    last_node_of_rotated_list.next=None
    return head

def main():
    head=Node(1)
    head.next=Node(2)
    head.next.next=Node(3)
    head.next.next.next=Node(4)
    head.next.next.next.next=Node(5)
    #head.next.next.next.next.next=Node(6)
    print("Nodes of original LinkedList are: ",end=' ')
    head.print_list()
    result=rotate(head,8)
    print("Nodes of rotated LinkedList are: ",end=' ')
    result.print_list()

main()
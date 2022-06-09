/*
Rearrange a LinkedList  #
Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order.
So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.

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
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node *next;
    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};

Node *reverse(Node *head){
    Node *prev=nullptr;
    while(head){
        Node *next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}

void reorder(Node *head){
    if(head==nullptr || head->next==nullptr)
        return;

    //find the middle of the linkedlist
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    //slow is now pointing to the middle node
    Node *rhead=reverse(slow);     //reverse the second half
    Node *fhead=head;    
    //rearrange to produce the linkedlist in the required order
    while(fhead && rhead){
        Node *temp=fhead->next;
        fhead->next=rhead;
        fhead=temp;

        temp=rhead->next;
        rhead->next=fhead;
        rhead=temp;
    }
    //set the next of the  last node to null
    if(fhead!=nullptr)
        fhead->next=NULL;
}

int main(){
    Node *head=new Node(2);
    head->next=new Node(4);
    head->next->next=new Node(6);
    head->next->next->next=new Node(8);
    head->next->next->next->next=new Node(10);
    head->next->next->next->next->next=new Node(12);
    reorder(head);
    while(head){
        cout<<head->value<<" ";
        head=head->next;
    }
}
/*
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
*/ 
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int value;
    ListNode *next;

    ListNode(int value){
        this->value=value;
        this->next=NULL;
    }
};

int cycle_length(ListNode *slow){
    ListNode *current=slow;
    int cycle_len=0;
    while(true){
        current=current->next;
        cycle_len++;
        if(current==slow)
            return cycle_len;
    }
    return 0;
}
int findcyclelength(ListNode *head){
    ListNode *fast=head;
    ListNode *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
            return cycle_length(slow);
    }
    return 0;
}

int main(){
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next=new ListNode(6);
    head->next->next->next->next->next->next=head->next->next;
    cout<<findcyclelength(head)<<endl;
    
}
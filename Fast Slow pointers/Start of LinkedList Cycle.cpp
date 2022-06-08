/*
Problem Statement #
Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.

Example: 
head 
Following LinkedList has a cycle: head->1->2->3->4->5->6
                                               ^        |
                                               |________|   


Time and Space Complexity: The above algorithm runs in O(N) time complexity and O(1) space complexity.
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

ListNode *find_start(ListNode *head,int cycle_len){
    ListNode *ptr1=head;
    ListNode *ptr2=head;
    while(cycle_len>0){
        ptr2=ptr2->next;
        cycle_len--;
    }
    while(ptr1!=ptr2){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr1;
}

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
ListNode *findcyclestart(ListNode *head){
    ListNode *fast=head;
    ListNode *slow=head;
    int cycle_len=0;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            cycle_len=cycle_length(slow);
            break;
        }
    }
    return find_start(head,cycle_len);
}

int main(){
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next=new ListNode(6);
    head->next->next->next->next->next->next=head->next->next;
    ListNode *res=findcyclestart(head);
    cout<<res->value<<endl;
    
}
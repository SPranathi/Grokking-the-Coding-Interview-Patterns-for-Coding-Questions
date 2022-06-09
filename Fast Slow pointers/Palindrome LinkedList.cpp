/*
Palindrome LinkedList #
Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.

Your algorithm should use constant space and the input LinkedList should be in the original form once the algorithm is finished. The algorithm should have O(N)O(N) time complexity where ‘N’ is the number of nodes in the LinkedList.

Example 1:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true
Example 2:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
Output: false

Time complexity #
The above algorithm will have a time complexity of O(N) where ‘N’ is the number of nodes in the LinkedList.

Space complexity #
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

bool palindrome(Node *head){
    if(head==nullptr || head->next==nullptr)
        return true;

    //find the middle of the linkedlist
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node *secondhalf=reverse(slow);     //reverse the second half
    Node *secondheadcopy=secondhalf;    //store the head of reversed part to revert back later

    //compare the first and second half
    while(head && secondhalf){
        if(head->value!=secondhalf->value)
            break;  //not a palindrome
        head=head->next;
        secondhalf=secondhalf->next;
    }
    secondheadcopy=reverse(secondheadcopy);
    if(head==nullptr || secondhalf==nullptr)
        return true;
    return false;
}

int main(){
    Node *head=new Node(2);
    head->next=new Node(4);
    head->next->next=new Node(6);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(2);
    cout<<palindrome(head)<<endl;
    head->next->next->next->next->next=new Node(2);
    cout<<palindrome(head)<<endl;
}
/*
Problem Statement #
Given the head of a Singly LinkedList, reverse the LinkedList. Write a function to return the new head of the reversed LinkedList.

Example:
input: 2->4->6->8>10
output:10->8->6->4->2

Time complexity #
The time complexity of our algorithm will be O(N) where ‘N’ is the total number of nodes in the LinkedList.

Space complexity #
We only used constant space, therefore, the space complexity of our algorithm is O(1).
*/ 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value=0;
    Node *next;
    Node(int value){
        this->value=value;
        next=NULL;
    }
};

Node *reverse(Node *head){
    Node *prev=NULL,*cur=head,*next=NULL;
    while(cur){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

int main(){
    Node *head=new Node(2);
    head->next=new Node(4);
    head->next->next=new Node(6);
    head->next->next->next=new Node(8);
    head->next->next->next->next=new Node(10);

    Node *res=reverse(head);
    cout<<"Nodes of the reversed LinkedList are:";
    while(res){
        cout<<res->value<<" ";
        res=res->next;
    }
}
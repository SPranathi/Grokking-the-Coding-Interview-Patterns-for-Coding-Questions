/*
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

Node *reverse_k_elements(Node *head,int k){
    if(k<=1 || !head)
        return head;
    
    Node *prev=NULL,*cur=head;
    while(true){
        Node *lastNode_prev=prev;
        Node *lastNode_sublist=cur;
        int i=0;
        Node *next=NULL;
        while(cur && i<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            i++;
        }
        //connect with previous part 
        if(lastNode_prev)
            lastNode_prev->next=prev;
        else
            head=prev;
        //connect with next part
        lastNode_sublist->next=cur;
        if(cur==NULL)
            break;
        prev=lastNode_sublist;
    }
    return head;
}

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next=new Node(8);

    Node *res=reverse_k_elements(head,3);
    cout<<"Nodes of the reversed LinkedList are:";
    while(res){
        cout<<res->value<<" ";
        res=res->next;
    }
}
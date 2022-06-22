/*
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

Node *reverse_sub_list(Node *head,int p,int q){
    if(p==q)
        return head;
    
    Node *prev=NULL,*cur=head,*next=NULL;
    int i=0;
    //skip 'p-1' nodes
    while(cur && i<p-1){
        prev=cur;
        cur=cur->next;
        i++;
    }

    Node *lastNode_first=prev;
    Node *lastNode_sublist=cur;
    while(cur && i<q){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        i++;
    }
    if(lastNode_first)
        lastNode_first->next=prev;
    else
        head=prev;
    lastNode_sublist->next=cur;
    return head;
}

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);

    Node *res=reverse_sub_list(head,2,4);
    cout<<"Nodes of the reversed LinkedList are:";
    while(res){
        cout<<res->value<<" ";
        res=res->next;
    }
}
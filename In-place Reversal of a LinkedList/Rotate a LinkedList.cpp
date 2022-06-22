/*
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

Node *rotate(Node *head,int k){
    if(k<=1 || !head || !head->next)
        return head;
    
    Node *last_node=head;
    int len=1;
    while(last_node->next){
        last_node=last_node->next;
        len++;
    }
    last_node->next=head; //connect the last node to head
    int rotations=k%len;
    int skip_len=len-rotations;
    Node *last_node_of_rotated_list=head;
    for(int i=0;i<skip_len-1;i++)
        last_node_of_rotated_list=last_node_of_rotated_list->next;
    
    head=last_node_of_rotated_list->next;
    last_node_of_rotated_list->next=NULL;

    return head;
}

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    //head->next->next->next->next->next=new Node(6);
    
    Node *res=rotate(head,8);
    cout<<"Nodes of the rotated LinkedList are:";
    while(res){
        cout<<res->value<<" ";
        res=res->next;
    }
}

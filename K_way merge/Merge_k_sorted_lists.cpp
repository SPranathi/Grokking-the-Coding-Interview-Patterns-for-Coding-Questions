/*
Problem Statement #

Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]

Example 2:

Input: L1=[5, 8, 9], L2=[1, 7]
Output: [1, 5, 7, 8, 9]

Time complexity #
O(N*logK)

Space complexity #

O(K)
*/
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val=0;
    ListNode *next;

    ListNode(int val){
        this->val=val;
        this->next=nullptr;
    }
};

struct compare{
    bool operator()(const ListNode *x,const ListNode *y){
        return x->val>y->val;
    }
};

ListNode *MergeLists(vector<ListNode *> lists){
    priority_queue<ListNode *,vector<ListNode *>,compare> minheap;

    for(auto root:lists){
        if(root!=nullptr){
            minheap.push(root);
        }
    }

    ListNode *reshead=nullptr,*restail=nullptr;
    while(!minheap.empty()){
        ListNode *node=minheap.top();
        minheap.pop();
        if(reshead==nullptr){
            reshead=restail=node;
        }
        else{
            restail->next=node;
            restail=restail->next;
        }
        if(node->next!=nullptr){
            minheap.push(node->next);
        }
    }
    return reshead;
}

int main(){
    ListNode *l1=new ListNode(2);
    l1->next=new ListNode(6);
    l1->next->next=new ListNode(8);

    ListNode *l2=new ListNode(3);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(7);

    ListNode *l3=new ListNode(1);
    l3->next=new ListNode(3);
    l3->next->next=new ListNode(4);

    ListNode *res=MergeLists(vector<ListNode *>{l1,l2,l3});
    while(res!=nullptr){
        cout<<res->val<<" ";
        res=res->next;
    }
}

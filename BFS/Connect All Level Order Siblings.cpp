/*
Problem Statement
Given a binary tree, connect each node with its level order successor. The last node of each level should point to the first node of the next level.

Time complexity #
The time complexity of the above algorithm is O(N).

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for the queue.
*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val=0;
    TreeNode *left,*right,*next;

    TreeNode(int val){
        this->val=val;
        left=right=next=nullptr;
    }

    virtual void printTree(){
        TreeNode *cur=this;
        cout<<"Traversal using 'next' pointer: ";
        while(cur!=nullptr){
            cout<<cur->val<< " ";
            cur=cur->next;
        }
    }
};


void connect(TreeNode *root){
    if(root==nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);
    TreeNode *curnode=nullptr,*prev=nullptr;
    while(!q.empty()){
        curnode=q.front();
        q.pop();
        if(prev!=nullptr)
            prev->next=curnode;
        prev=curnode;

        if(curnode->left!=nullptr)
            q.push(curnode->left);
        if(curnode->right!=nullptr)
            q.push(curnode->right);
    }
}


int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(9);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    connect(root);
    root->printTree();
}

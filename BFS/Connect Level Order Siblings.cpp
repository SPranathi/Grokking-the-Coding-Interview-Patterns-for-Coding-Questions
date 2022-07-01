/*
Problem Statement #
Given a binary tree, connect each node with its level order successor. The last node of each level should point to a null node.

Time complexity #
The time complexity of the above algorithm is O(N).

Space complexity #
The space complexity of the above algorithm will be O(N).
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

    virtual void printlevelorder(){
        TreeNode *nextlevelroot=this;
        while(nextlevelroot!=nullptr){
            TreeNode *cur=nextlevelroot;
            nextlevelroot=nullptr;
            while(cur!=nullptr){
                cout<<cur->val<<" ";
                if(nextlevelroot==nullptr){
                    if(cur->left!=nullptr)
                        nextlevelroot=cur->left;
                    else if(cur->right!=nullptr)
                        nextlevelroot=cur->right;
                }
                cur=cur->next;
            }
            cout<<endl;
        }
    }
};


void connect(TreeNode *root){
    if(root==nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int levelsize=q.size();
        TreeNode *prev=nullptr;
        for(int i=0;i<levelsize;i++){
            TreeNode *curnode=q.front();
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
}


int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(9);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    connect(root);
    cout<<"Level order traversal using 'next' pointer: "<<endl;
    root->printlevelorder();
}

/*
Problem Statement #
Given a binary tree and a node, find the level order successor of the given node in the tree. The level order successor is the node that appears right after the given node in the level order traversal.

12 7 1 9 10 5
Given Node: 
 9 
 Level Order Successor: 
 10 

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
    TreeNode *left,*right;

    TreeNode(int val){
        this->val=val;
        left=right=nullptr;
    }
};


TreeNode *successor(TreeNode *root,int key){
    if(root==nullptr)
        return nullptr;

    queue<TreeNode *> q;
    q.push(root);
    bool left_right=true;
    while(!q.empty()){
        TreeNode *curnode=q.front();
        q.pop();
            
        if(curnode->left!=nullptr)
            q.push(curnode->left);
        if(curnode->right!=nullptr)
            q.push(curnode->right);
        
        if(curnode->val==key)
            break;
    }
    return q.front();
}


int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(9);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    TreeNode *res=successor(root,12);
    if(res!=nullptr)
        cout<<res->val<<" "<<endl;
    res=successor(root,9);
    if(res!=nullptr)
        cout<<res->val<<" "<<endl;
}

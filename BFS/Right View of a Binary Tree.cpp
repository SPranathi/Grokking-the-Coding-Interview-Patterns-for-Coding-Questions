/*
Problem Statement
Given a binary tree, return an array containing nodes in its right view. The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.

Time complexity #
The time complexity of the above algorithm is OO(N), where ‘N’ is the total number of nodes in the tree. 

Space complexity #
The space complexity of the above algorithm will be O(N) as we need to return a list containing the level order traversal.
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


vector<TreeNode*> rightview(TreeNode *root){
    vector<TreeNode *> res;
    if(root==nullptr)
        return res;

    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int levelsize=q.size();
        for(int i=0;i<levelsize;i++){
            TreeNode *curnode=q.front();
            q.pop();

            if(i==levelsize-1)
                res.push_back(curnode);
            
            if(curnode->left!=nullptr)
                q.push(curnode->left);
            if(curnode->right!=nullptr)
                q.push(curnode->right);
        }
    }
    return res;
}


int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(9);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    root->left->left->left=new TreeNode(3);
    vector<TreeNode *> res=rightview(root);
    for(auto n:res)
        cout<<n->val<<" "; 
}

/*
Problem Statement #

Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ‘S’.

Example:  12 7 1 9 -1 10 5
 
S: 23
Output: true
Explaination: The path with sum '23' is there 
S: 16
Output: false
Explaination: There is no root-to-leaf path with sum '16'.

Time complexity #

The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.
Space complexity #

The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack.
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

bool hasPath(TreeNode *root,int s){
    if(root==nullptr)
    return false;

    if(root->val==s && root->left==nullptr && root->right==nullptr)
        return true;
    
    return hasPath(root->left,s-root->val) || hasPath(root->right,s-root->val);
}

int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(9);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    cout<<hasPath(root,23)<<endl;
    cout<<hasPath(root,10)<<endl;
}
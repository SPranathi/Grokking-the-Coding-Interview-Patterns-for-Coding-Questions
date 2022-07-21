/*
Tree Diameter (medium) #

Given a binary tree, find the length of its diameter.The diameter of a tree is the number of nodes on the longest path between any two leaf nodes.
The diameter of a tree may or may not pass through the root.

Note: You can always assume that there are at least two leaf nodes in the given tree.

Time complexity #

The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #

The space complexity of the above algorithm will be O(N) in the worst case.This space will be used to store the recursion stack.
The worst case will happen when the given tree is a linked list (i.e., every node has only one child).
*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left,*right;

    TreeNode(int val){
        this->val=val;
        left=right=nullptr;
    }
};

int calculateHeight(TreeNode *root,int &treediameter){
    if(root==nullptr)
        return 0;

    int leftTreeHeight=calculateHeight(root->left,treediameter);
    int rightTreeHeight=calculateHeight(root->right,treediameter);

    //diameter at the current node will be equal to height of left+right subtrees for current node
    int diameter=leftTreeHeight+rightTreeHeight;

    //update the global tree diameter
    treediameter=max(treediameter,diameter);

    return 1+max(leftTreeHeight,rightTreeHeight);
}

int treeDiameter(TreeNode *root){
    int treediameter=0;
    calculateHeight(root,treediameter);
    return treediameter;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(6);
    cout<<treeDiameter(root)<<endl;

    root->left->left=nullptr;
    root->right->left->left=new TreeNode(7);
    root->right->left->right=new TreeNode(8);
    root->right->right->left=new TreeNode(9);
    root->right->left->right->left=new TreeNode(10);
    root->right->right->left->left=new TreeNode(11);
    cout<<treeDiameter(root)<<endl;
}

/*
Path with Maximum Sum (hard) #

Find the path with the maximum sum in a given binary tree. Write a function that returns the maximum sum.
A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root.

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

int pathsum(TreeNode *root,int &maxsum){
    if(root==nullptr)
        return 0;

    int leftTreesum=root->val+pathsum(root->left,maxsum);
    int rightTreesum=root->val+pathsum(root->right,maxsum);

    maxsum=max({maxsum,root->val,leftTreesum,rightTreesum,leftTreesum+rightTreesum-root->val});
    return max({leftTreesum,rightTreesum,root->val});
}

int MaxPathsum(TreeNode *root){
    int maxsum=INT_MIN;
    pathsum(root,maxsum);
    return maxsum;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    cout<<MaxPathsum(root)<<endl;

    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(6);
    root->right->left->left=new TreeNode(7);
    root->right->left->right=new TreeNode(8);
    root->right->right->left=new TreeNode(9);
    cout<<MaxPathsum(root)<<endl;

    root=new TreeNode(-1);
    root->left=new TreeNode(-3);
    cout<<MaxPathsum(root)<<endl;
}
 

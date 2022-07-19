/*
Problem Statement #

Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path will represent a number.
Find the total sum of all the numbers represented by all paths.

1 7 9 -1 2 9
output:408
17+192+199

Time complexity #

The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #

The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack.
The worst case will happen when the given tree is a linked list (i.e., every node has only one child).
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

int findsum(TreeNode *root,int pathsum){
    if(root==nullptr)
        return 0;

    //calculate the path number of the node
    pathsum=10*pathsum+root->val;

    //if the root node is a leaf, return the current pathsum
    if(root->left==nullptr && root->right==nullptr)
        return pathsum;
    
    return findsum(root->left,pathsum)+findsum(root->right,pathsum);
}

int sumofallpaths(TreeNode *root){
    return findsum(root,0);
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(7);
    root->right=new TreeNode(9);
    root->right->left=new TreeNode(2);
    root->right->right=new TreeNode(9);
    cout<<sumofallpaths(root)<<endl;
}

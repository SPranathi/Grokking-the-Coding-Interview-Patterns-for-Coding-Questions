/*
Problem Statement #

Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.

Time complexity #

The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree.
This is due to the fact that we traverse each node once.

Space complexity #

The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack.
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

bool haspath(TreeNode *root,vector<int> sequence,int index){
    if(root==nullptr)
        return false;

    if(index>=sequence.size() || root->val!=sequence[index])
        return false;
    
    //if the current node is a leaf,and end of the sequence
    if(root->left==nullptr && root->right==nullptr && index==sequence.size()-1)
        return true;

    //recursively call to traverse the left and right
    return haspath(root->left,sequence,index+1) || haspath(root->right,sequence,index+1);
}

bool findpath(TreeNode *root,vector<int> sequence){
    if(root==nullptr)
        return sequence.empty();
    return haspath(root,sequence,0);
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(0);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(1);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(5);
    cout<<findpath(root,vector<int> {1,0,7})<<endl;
    cout<<findpath(root,vector<int> {1,1,6})<<endl;
}
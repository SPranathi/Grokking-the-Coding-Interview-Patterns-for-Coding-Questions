/*
Problem Statement #

Given a binary tree and a number ‘S’, find all paths in the tree such that the sum of all the node values of each path equals ‘S’. Please note that the paths can start or end at any node but all paths must follow direction from parent to child (top to bottom).

Time complexity #

The time complexity of the above algorithm is O(N^2) in the worst case, where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once, but for every node, we iterate the current path. The current path, in the worst case, can be O(N) (in the case of a skewed tree).
But, if the tree is balanced, then the current path will be equal to the height of the tree, i.e.,O(logN).So the best case of our algorithm will be O(NlogN).

Space complexity #

The space complexity of the above algorithm will be O(N).This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child). We also need O(N) space for storing the currentPath in the worst case.

Overall space complexity of our algorithm is O(N).
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

int countpathsrecursive(TreeNode *root,int sum,vector<int> &curpath){
    if(root==nullptr)
        return 0;

    //add the node to path
    curpath.push_back(root->val);
    int pathcount=0,pathsum=0;
    for(int i=curpath.size()-1;i>=0;i--){
        pathsum+=curpath[i];
        //if sub-path sum is equal to sum increment pathcount
        if(pathsum==sum)
            pathcount++;
    }

    //traverse the tree
    pathcount+=countpathsrecursive(root->left,sum,curpath);
    pathcount+=countpathsrecursive(root->right,sum,curpath);

    //remove the node from curpath
    curpath.pop_back();

    return pathcount;
}

int countpaths(TreeNode *root,int sum){
    vector<int> curpath;
    return countpathsrecursive(root,sum,curpath);
}

int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(4);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    cout<<countpaths(root,11)<<endl;
} 

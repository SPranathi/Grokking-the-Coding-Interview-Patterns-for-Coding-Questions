/*
Problem Statement #

Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the sum of all the node values of each path equals ‘S’.

Example:
1 7 9 4 5 2 7
input:12
output:2

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

void findPaths(TreeNode *root,int sum,vector<int> &curpath,vector<vector<int>> &paths){
    if(root==nullptr)
        return;

    //add the current node to the path
    curpath.push_back(root->val);

    //if the current node is a leaf and its value is equal to sum
    if(root->val==sum && root->left==nullptr && root->right==nullptr){
        paths.push_back(curpath);
    }
    else{
        //traverse the left subtree
        findPaths(root->left,sum-root->val,curpath,paths);
        //traverse the right subtree
        findPaths(root->right,sum-root->val,curpath,paths);
    }

    //remove the current node from the path to backtrack
    curpath.pop_back();
}

vector<vector<int>> findallpaths(TreeNode *root,int sum){
    vector<vector<int>> paths;
    vector<int> curpath;
    findPaths(root,sum,curpath,paths);
    return paths;
}

int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(4);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    int sum=23;
    vector<vector<int>> res=findallpaths(root,sum);
    cout<<"Tree paths with sum "<<sum<<": ";
    for(auto vec:res){
        for(auto i:vec)
            cout<<i<<" ";
        cout<<endl;
    }
} 

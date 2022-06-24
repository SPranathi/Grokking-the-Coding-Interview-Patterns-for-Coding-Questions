/*
Problem Statement #
Given a binary tree, populate an array to represent its level-by-level traversal. You should populate the values of all nodes of each level from left to right in separate sub-arrays.
*/ 
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val=0;
    TreeNode *left,*right;

    TreeNode(int x){
        val=x;
        left=right=nullptr;
    }
};

vector<vector<int>> LevelOrderTraversal(TreeNode *root){
    vector<vector<int>> res;
    if(root==nullptr)
        return res;

    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int levelsize=q.size();
        vector<int> curlevel;
        for(int i=0;i<levelsize;i++){
            TreeNode *curnode=q.front();
            q.pop();
            //add the node to the current level
            curlevel.push_back(curnode->val);
            //insert the children of currnt node in the queue
            if(curnode->left!=nullptr)
                q.push(curnode->left);
            if(curnode->right!=nullptr)
                q.push(curnode->right);
        }
        res.push_back(curlevel);
    }
    return res;
}


int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(9);
    root->left->right=new TreeNode(10);
    root->right->right=new TreeNode(5);
    vector<vector<int>> res=LevelOrderTraversal(root);
    cout<<"Level order Traversal: ";
    for(auto v:res){
        for(auto n:v)
            cout<<n<<" ";
        cout<<endl;
    }
}
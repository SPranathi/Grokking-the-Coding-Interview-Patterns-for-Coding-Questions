/*
Problem Statement #
Find the minimum depth of a binary tree. The minimum depth is the number of nodes along the shortest path from the root node to the nearest leaf node.

Time complexity #
The time complexity of the above algorithm is O(N).

Space complexity #
The space complexity of the above algorithm will be O(N) .
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


int mindepth(TreeNode *root){
    if(root==nullptr)
        return 0;

    queue<TreeNode *> q;
    q.push(root);
    int mindepth=0;
    while(!q.empty()){
        mindepth++;
        int levelsize=q.size();
        for(int i=0;i<levelsize;i++){
            TreeNode *curnode=q.front();
            q.pop();

            //check if this is a leaf node
            if(curnode->left==nullptr && curnode->right==nullptr)
                return mindepth;
            
            if(curnode->left!=nullptr)
                q.push(curnode->left);
            if(curnode->right!=nullptr)
                q.push(curnode->right);
        }
    }
    return mindepth;
}


int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    cout<<"Tree Minimum  Depth: "<<mindepth(root)<<endl;
    root->left->left=new TreeNode(9);
    root->right->left->left=new TreeNode(11);
    cout<<"Tree Minimum  Depth: "<<mindepth(root)<<endl;

}
 

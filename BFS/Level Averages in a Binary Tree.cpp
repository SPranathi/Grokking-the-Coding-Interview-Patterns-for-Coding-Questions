/*
Problem Statement #
Given a binary tree, populate an array to represent the averages of all of its levels.

Example :
12 7 1 9 2 10 5
12.0 4.0 6.5

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for the queue.
Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N) space to store them in the queue.
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


vector<double> levelaverage(TreeNode *root){
    vector<double> res;
    if(root==nullptr)
        return res;

    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int levelsize=q.size();
        double sum=0;
        for(int i=0;i<levelsize;i++){
            TreeNode *curnode=q.front();
            q.pop();

            sum+=curnode->val;
            
            if(curnode->left!=nullptr)
                q.push(curnode->left);
            if(curnode->right!=nullptr)
                q.push(curnode->right);
        }
        res.push_back(sum/levelsize);
    }
    return res;
}


int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(9);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    vector<double> res=levelaverage(root);
    cout<<"Level averages are: ";
    for(auto ans:res){
        cout<<ans<<" ";
    }

}


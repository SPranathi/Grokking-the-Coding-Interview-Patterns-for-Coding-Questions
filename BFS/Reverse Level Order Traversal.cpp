/*
Problem Statement #
Given a binary tree, populate an array to represent its level-by-level traversal in reverse order, i.e., the lowest level comes first.
You should populate the values of all nodes in each level from left to right in separate sub-arrays. 

Example:
1 2 3 4 5 6 7
[[4,5,6,7][2,3][1]]

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) as we need to return a list containing the level order traversal.
We will also need O(N) space for the queue. Since we can have a maximum of N/2 nodes at any level(this could happen only at the lowest level),therefore we will need O(N) space to store them in the queue.
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

deque<vector<int>> ReverseLevelOrderTraversal(TreeNode *root){
    deque<vector<int>> res;
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
            curlevel.push_back(curnode->val);
            if(curnode->left)
                q.push(curnode->left);
            if(curnode->right)
                q.push(curnode->right);
        }
        res.push_front(curlevel);
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
    auto res=ReverseLevelOrderTraversal(root);
    cout<<"ReverseLevel order Traversal: ";
    for(auto v:res){
        for(auto n:v)
            cout<<n<<" ";
        cout<<endl;
    }
}
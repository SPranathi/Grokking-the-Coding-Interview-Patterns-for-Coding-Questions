/*Problem Statement #
Given a binary tree, populate an array to represent its zigzag level order traversal. You should populate the values of all nodes of the first level from left to right, then right to left for the next level and keep alternating in the same manner for the following levels.

Example : 
12 7 1 9 10 5 20 17
output:
12 1 7 9 10 5 17 20

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) as we need to return a list containing the level order traversal. We will also need O(N) space for the queue.
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


vector<vector<int>> zigzag(TreeNode *root){
    vector<vector<int>> res;
    if(root==nullptr)
        return res;

    queue<TreeNode *> q;
    q.push(root);
    bool left_right=true;
    while(!q.empty()){
        int levelsize=q.size();
        vector<int> v(levelsize);
        for(int i=0;i<levelsize;i++){
            TreeNode *curnode=q.front();
            q.pop();

            //add the node to the current level based on traverse direction
            if(left_right){
                v[i]=curnode->val;
            }
            else{
                v[levelsize-i-1]=curnode->val;
            }
            
            if(curnode->left!=nullptr)
                q.push(curnode->left);
            if(curnode->right!=nullptr)
                q.push(curnode->right);
        }
        res.push_back(v);
        //reverse the traverse direction
        left_right=!left_right;
    }
    return res;
}


int main(){
    TreeNode *root=new TreeNode(12);
    root->left=new TreeNode(7);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(9);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(5);
    root->right->left->left=new TreeNode(20);
    root->right->left->right=new TreeNode(17);
    vector<vector<int>> res=zigzag(root);
    cout<<"ZigZag Traversal: ";
    for(auto r:res){
        for(auto ans:r)
            cout<<ans<<" ";
        cout<<endl;
    }

}

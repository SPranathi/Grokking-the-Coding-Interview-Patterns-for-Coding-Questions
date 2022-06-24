"""
Problem Statement #
Given a binary tree, populate an array to represent its level-by-level traversal. You should populate the values of all nodes of each level from left to right in separate sub-arrays.
"""
from collections import deque

class TreeNode:
    def __init__(self,val):
        self.val=val
        self.left=self.right=None

def traverse(root):
    res=[]
    if root is None:
        return res
    
    queue=deque()
    queue.append(root)
    while queue:
        levelsize=len(queue)
        curlevel=[]
        for _ in range(levelsize):
            curnode=queue.popleft()
            #add the node to the current level
            curlevel.append(curnode.val)
            #insert the children of currnt node in the queue
            if curnode.left:
                queue.append(curnode.left)
            if curnode.right:
                queue.append(curnode.right)
        res.append(curlevel)
    return res

def main():
    root=TreeNode(12)
    root.left=TreeNode(7)    
    root.right=TreeNode(1)    
    root.left.left=TreeNode(9)    
    root.right.left=TreeNode(10)    
    root.right.right=TreeNode(5)
    print("Level order Traversal: "+str(traverse(root)))    

main()

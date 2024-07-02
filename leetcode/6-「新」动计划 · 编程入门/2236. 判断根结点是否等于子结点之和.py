'''
 @file 2236. 判断根结点是否等于子结点之和.py
 @author horiki
 @version 0.1
 @date 2024-07-02
 @copyright Copyright (c) 2024
 
 @brief 
 
'''
 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkTree(self, root: Optional[TreeNode]) -> bool:
        return root.val == root.left.val + root.right.val
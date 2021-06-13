# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        num_arr = []
        self.add_val_to_num_arr(root, num_arr)
        for i in range(len(num_arr)):
            if i > 0 and (num_arr[i] <= num_arr[i-1]):
                return False
        return True
        
    def add_val_to_num_arr(self, root, num_arr):
        if root.left:
            self.add_val_to_num_arr(root.left, num_arr)
        if root:
            num_arr.append(root.val)
        if root.right:
            self.add_val_to_num_arr(root.right, num_arr)

        

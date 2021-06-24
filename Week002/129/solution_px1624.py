# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0
    def sumNumbers(self, root: TreeNode) -> int:
        # iterative dfs using stack
        #return self.dfs_iterative(root)
        # recursive dfs
        self.sum = 0
        self.dfs_recursive(root, 0)
        return self.sum
    
    def dfs_iterative(self, root: TreeNode) -> int:
        q = [root]
        sum = 0
        while q:
            cur_node = q.pop()
            if not cur_node.left and not cur_node.right:
                sum += cur_node.val
                continue
            for node in [cur_node.left, cur_node.right]:
                if node:
                    node.val += cur_node.val * 10
                    q.append(node)
        return sum

    def dfs_recursive(self, root, cur_sum):
        if not root:
            return
        if not root.left and not root.right:
            self.sum += cur_sum * 10 + root.val
            return
        self.dfs_recursive(root.left, cur_sum * 10 + root.val)
        self.dfs_recursive(root.right, cur_sum * 10 + root.val)

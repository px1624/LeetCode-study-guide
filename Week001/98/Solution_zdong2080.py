class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.helper(root, float("-inf"), float("inf"))

    def helper(self, node, left, right):
        if not node:
            return True
        if not left < node.val < right:
            return False
        return self.helper(node.left, left, node.val) and self.helper(node.right, node.val, right)
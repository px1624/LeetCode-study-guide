# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.n_FBT = {}
        self.n_FBT[1] = [TreeNode(0)]
    def allPossibleFBT(self, n: int) -> List[TreeNode]:
        
        if n in self.n_FBT:
            return self.n_FBT[n]
        
        all_trees = []
        
        # FBTs can only have odd number of nodes
        for i in range(1, n, 2):
            # Distribute i nodes in the left
            left_trees = self.allPossibleFBT(i)
            # and N-i-1 nodes on the right
            right_trees = self.allPossibleFBT(n-i-1)
            
            # for every possible left tree, combine it with a right tree to
            # form a valid FBT of size N
            for l_tree in left_trees:
                for r_tree in right_trees:
                    root = TreeNode(0)
                    root.left = l_tree
                    root.right = r_tree
                    all_trees.append(root)
        self.n_FBT[n] = all_trees
        return all_trees

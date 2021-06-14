/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return recursivelyTraverse(root, INT_MIN, INT_MAX);
    }
    bool recursivelyTraverse(TreeNode* root, int leftNodeValue, int rightNodeValue){
        if(root == nullptr){
            return ture;
        }
        if((root -> val <= leftNodeValue)||( root -> val >= rightNodeValue)){
            return flase;
        }
        return  recursivelyTraverse( root -> left, leftNodeValue,  root ->val) && recursivelyTraverse( root -> right, root -> val,  rightNodeValue)
        
    }
};

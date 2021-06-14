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
        return recursivelyTraverse(root, LONG_MIN, LONG_MAX);
    }
    
    // leftNodeValue < root < rightNodeValue
    // Using long long for the cases that values >= 2147483647
    bool recursivelyTraverse(TreeNode* root, long long leftNodeValue, long long rightNodeValue){
        if(root == nullptr){
            return true;
        }
        // return false if any subtree not satisfies
        if((root -> val <= leftNodeValue)||( root -> val >= rightNodeValue)){
            return false;
        }
        // recursively traverse:
        return  recursivelyTraverse( root -> left, leftNodeValue,  root ->val) && recursivelyTraverse( root -> right, root -> val,  rightNodeValue);
        
    }
};

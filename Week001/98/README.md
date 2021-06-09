## Question 98.   Validate Binary Search Tree
**(Medium)**  

Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.<br>
The right subtree of a node contains only nodes with keys greater than the node's key.<br>
Both the left and right subtrees must also be binary search trees.<br>

#### Example 1:
<img src="https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg">
<pre>
<b>Input:</b> root = [2,1,3]
<b>Output:</b> true 
</pre>

#### Example 2:
<img src="https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg">
<pre>
<b>Input:</b> root = [5,1,4,null,null,3,6]
<b>Output:</b> false
</pre>

#### Constraints:

* The number of nodes in the tree is in the range [1, 104].
* -2^31 <= Node.val <= 2^31 - 1


## Solution Details

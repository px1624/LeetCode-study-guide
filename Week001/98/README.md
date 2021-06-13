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

#### px1624:
A valid BST is sorted in the `inorder` traversal order. That is if we add all the values in the BST to an empty array using `inorder` traversal, the array will be a sorted sequence. The problem states that left child is strictly less than the parent node, and the right child is strictly greater than the parent node, we can conclude that if the BST is valid, the resulting array must be in strictly increasing order. Thus we can solve the problem in two steps, first create an empty array and add all the numbers in the BST to the array using `inorder` traversal. Then we can verify that the populated array is sorted in increasing order by looping through the array once.

#### hcao10:
For a <b>valid BST</b>,
<pre>
if its left subtree is not empty, then the value of all the nodes in the left subtree is less than the value of its root node;  </br>
if its right subtree is not empty, then the value of all nodes in the right subtree is greater than the value of its root node;  </br>
its left and right subtrees are also valid BSTs.  </br>
</pre>
By understanding these three properties, we only need to recursively traverse the BST to test if all the nodes in the subtree are in the range of the leftmost and rightmost nodes' values to ensure that the tree satisfies the BST properties. 

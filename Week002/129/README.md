## Question 129.   Sum Root to Leaf Numbers
**(Medium)**  

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

#### Example 1:
<img src="https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg">
<pre>
<b>Input:</b> root = [1,2,3]
<b>Output:</b> 25
<b>Explanation:</b>
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
</pre>

#### Example 2:
<img src="https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg">
<pre>
<b>Input:</b> root = [4,9,0,5,1]
<b>Output:</b> 1026
<b>Explanation:</b>
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
</pre>

#### Constraints:

* The number of nodes in the tree is in the range [1, 1000].
* 0 <= Node.val <= 9
* The depth of the tree will not exceed 10.


## Solution Details

#### zdong7:
In this question, it requires us to sum all the numbers that from root to leaf. 
So we can recursively call itself to time 10 to its own value and add to the value to its two children node.
In the end, what we do is sum the left subtree and right subtree value for each node and return it.

#### px1624:
We can simply use either bfs and dfs to traverse through the tree and adding parent nodes value (times 10) to both children. When reaching the leaf node, add its value to the total sum. We can do this iteratively using stack or queue, or recursively.

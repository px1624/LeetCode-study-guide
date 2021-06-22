## Question 894. All Possible Full Binary Trees
**(medium)**

Given an integer `n`, return a *list of all possible **full binary trees** with `n` nodes*. Each node of each tree in the answer must have `Node.val == 0`.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in `any order`.

A **full binary tree** is a binary tree where each node has exactly `0` or `2` children.

#### Example 1:
<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png">
<pre>
<b>Input:</b> n = 7
<b>Output:</b> [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],
[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
</pre>

#### Example 2:
<pre>
<b>Input:</b> n = 3
<b>Output:</b> [[0,0,0]]
</pre>

#### Constraints:
* `1 <= n <= 20`

## Solution Details
#### px1624:
When dealing with trees, an immediate intuition is to use recursion. We can think about the recursion relationship as follows. Let's say `N=7`, we need a root node, and we can arrange the rest of the nodes into left subtree and right subtree. For `N=7`, we can have `1, 3, 5` nodes on the left subtree, and `5, 3, 1` nodes on the right subtree respectively. Notice that a full binary tree must have odd number of nodes. And for every possible left subtree, we can combine it with every possible right subtree to construct all possible full binary trees. See [here](https://www.youtube.com/watch?v=F0dUVxzzg_M) for a great explaination.
#### hcao10:😰🤔ing

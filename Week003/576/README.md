## Question 576. Out of Boundary Paths

**(Medium)**

There is an `m x n` grid with a ball. The ball is initially at the position `[startRow, startColumn]`. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply **at most** `maxMove` moves to the ball.

Given the five integers `m`, `n`, `maxMove`, `startRow`, `startColumn`, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it **modulo** <code>10<sup>9</sup> + 7</code>.

#### Example 1:

<img src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png">
<pre>
<b>Input:</b> m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
<b>Output:</b> 4
</pre>

#### Example 2:

<img src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png">
<pre>
<b>Input:</b> m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
<b>Output:</b> 12
</pre>

#### Constraints:

* `1 <= m, n <= 50`
* `0 <= maxMove <= 50`
* `0 <= startRow < m`
* `0 <= startColumn < n`

## Solution Details

#### px1624:
At each cell, we only have 4 choices for paths, we can recursively add paths in each direction while decrementing the `maxMove`. Using memoization, we can further decrease the time complexity

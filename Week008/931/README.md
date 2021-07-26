## Question 931. Minimum Falling Path Sum
**(Medium)**

Given an `n x n` array of integers `matrix`, return *the **minimum sum** of any **falling path** through* `matrix`.

A **falling path** starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position `(row, col)` will be `(row + 1, col - 1)`, `(row + 1, col)`, or `(row + 1, col + 1)`.

#### Example 1:

<pre>
<b>Input:</b> matrix = [[2,1,3],[6,5,4],[7,8,9]]
<b>Output:</b> 13
<b>Explanation:</b> There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]
</pre>

#### Example 2:

<pre>
<b>Input:</b> matrix = [[-19,57],[-40,-5]]
<b>Output:</b> -59
<b>Explanation:</b> The falling path with a minimum sum is underlined below:
[[-19,57],
 [-40,-5]]
</pre>

#### Example 3:

<pre>
<b>Input:</b> matrix = [[-48]]
<b>Output:</b> -48
<b>Explanation:</b>
</pre>

#### Constraints:

* `n == matrix.length`
* `n == matrix[i].length`
* `1 <= n <= 100`
* `-100 <= matrix[i][j] <= 100`

## Solution Details

#### px1624:

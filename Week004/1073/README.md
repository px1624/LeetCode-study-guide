## Question 1073. Adding Two Negabinary Numbers

**(Medium)**

Given two numbers `arr1` and `arr2` in base **-2**, return the result of adding them together.

Each number is given in *array format*:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, `arr = [1,1,0,1]` represents the number `(-2)^3 + (-2)^2 + (-2)^0 = -3`.  A number `arr` in *array*, format is also guaranteed to have no leading zeros: either `arr == [0]` or `arr[0] == 1`.

Return the result of adding `arr1` and `arr2` in the same format: as an array of 0s and 1s with no leading zeros.


#### Example 1:
<pre>
<b>Input:</b> arr1 = [1,1,1,1,1], arr2 = [1,0,1]
<b>Output:</b> [1,0,0,0,0]
<b>Explanation:</b> arr1 represents 11, arr2 represents 5, the output represents 16.
</pre>
#### Example 2:
<pre>
<b>Input:</b> arr1 = [0], arr2 = [0]
<b>Output:</b> [0]
</pre>
#### Example 3:
<pre>
<b>Input:</b> arr1 = [0], arr2 = [1]
<b>Output:</b> [1]
</pre>
 
 #### Constraints:

* `1 <= arr1.length, arr2.length <= 1000`
* `arr1[i]` and `arr2[i]` are `0` or `1`
* `arr1` and `arr2` have no leading zeros

## Solution Details
#### hcao10:🤔ing

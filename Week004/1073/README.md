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

#### px1624
Adding two negabinary number is similar to normal binary addition except we need to carry over two digits. Here is an example:
```
    1
+   1
------
  110
```
for `1+1=2`, we write `0` in the first ditgit (the right-most digit) and carry over `1` to the second digit. We need to remember that `1` in second digit represents <code>-2<sup>1</sup>=-2</code>, but what we want is positive `2`, thus we need to carry over another `1` in the third digit to cancel out the negativity. Therefore, we get <code>(-2)<sup>2</sup>+(-2)<sup>1</sup>=4-2=2</code>.
If a digit has carry over of `2`, and the next digit has carry-over of `1`, then they can be canceled out since the value of carry over at <code>i<sup>th</code> place is </code><code>1*(-2)<sup>i</sup></code>, and the value at <code>(i-1)<sup>th</code> place is <code>2*(-2)<sup>i-1</sup></code>, which is identical in value but different in sign, therefore they can be cancelled out. An example will be:
```
leading zeros added for demo purpose

   011
+  001
   11  (carry over, add 1 to second and third digit)
------
     0

   011
+  001
  12   (carry over, add 1 to third and fourth digit)
------
    00

   011
+  001
       (carry over can be cancelled as described previously)
------
    00

removing leading zeros, the result is 0
```

We can then use these rules to do negabinary number additions starting from the end of both arrays.
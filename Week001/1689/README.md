## Question 1689.  Partitioning Into Minimum Number Of Deci-Binary Number
**(Medium???)**  

 A decimal number is called **deci-binary** if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are **deci-binary**, while 112 and 3001 are not.

 Given a string n that represents a positive decimal integer, return the **minimum** number of positive **deci-binary** numbers needed so that they sum up to n.

#### Example 1:

**Input:** n = "32"  
**Output:** 3  
**Explanation:** 10 + 11 + 11 = 32  

#### Example 2:

**Input:** n = "82734"  
**Output:** 8  

#### Example 3:  

**Input:** n = "27346209830709182346"  
**Output:** 9  
 

#### Constraints:

- 1 <= n.length <= 10^5^  
- n consists of only digits.  
- n does not contain any leading zeros and represents a positive integer.  

<hr>

## Solution Details
#### hcao10:
The essence of this problem is to find the largest single number in a string of numbers.  
After reading the question, we know that Deci-Binary Number only contains zeros or ones, and cannot start with zero. The definition of Deci-Binary Number means that a single number **x** in a string of numbers requires **x** deci-binary Numbers(each of these is a 1) to form it.  
#### e.g.
<pre>
 <b>2:</b>
      1
+     1
----------( <b>2</b> requires  <b>2</b> single-Deci-Binary numbers)
=     2
</pre>

<pre>
<b>26:</b>
      11
      11
       1
       1
       1
+      1
----------( <b>2</b> requires  <b>2</b> single-Deci-Binary numbers;  <b>6</b> requires <b>6</b> ones )
      26
</pre>
So the **largest Number** in the string determines the Number of deci-binary numbers we need.

#### px1624:

Since we can only use Deci-Binary numbers, the mininum number of Deci-Binary numbers we need is bounded by the largest digit in `n`. This is because we can only add `1` to that digit each time for every Deci-Binary number. The largest digit in `n` cannot be larger than `9`, since `n` is a decimal number in string representation. Thus we've obtained a lower bound and an upper bound for the solution. The solution is straight forward, looping over string `n` to find the largest digit, if we encounter a `9`, we can simply return `9` and end the loop early. We can further optimize the memory usage by using a char (1 byte) variable instead of a int (4 byte) for storing the maximum digit.

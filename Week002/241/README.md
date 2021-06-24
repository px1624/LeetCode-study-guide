## Question 241.  Different Ways to Add Parentheses
**(Medium)**  

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in **any order**.

#### Example 1:
<pre>
<b>Input:</b> expression = "2-1-1"
<b>Output:</b> [0,2]
<b>Explanation:</b>
((2-1)-1) = 0 
(2-(1-1)) = 2
</pre>

#### Example 2:
<pre>
<b>Input:</b> expression = "2*3-4*5"
<b>Output:</b> [-34,-14,-10,-10,10]
<b>Explanation:</b>
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 </pre>

#### Constraints:

- 1 <= expression.length <= 20
- expression consists of digits and the operator '+', '-', and '*'.



## Solution Details

#### hcao10:
The expression can be recursively divided at the operators' positions until there is no operator in the expression. We don't need to think about exactly where to put the parentheses, because we already did the parentheses job by splitting the expression into two parts:
<pre>
 2 * 3 - 4 * 5
 2 | 3 <b>|</b> 4 | 5  
 ->  2 | <b>(3 - 4 * 5)</b>
   => 3 | 4 | 5 
   => 3 - (4 * 5) OR (3 - 4) * 5 
   
 -> (2 * 3) <b>|</b> (4 * 5)
 
 -> <b>(2 * 3 - 4)</b> | 5
   => 2 | 3 | 4 
   => 2 * (3 - 4) OR (2 * 3) - 4
</pre>
Start calculation when the expression doesn't have any operator.

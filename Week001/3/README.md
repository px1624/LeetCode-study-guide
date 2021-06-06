## Question 3.  Longest Substring Without Repeating Characters
**(Medium)**  

Given a string `s` , find the length of the **longest substring** without repeating characters.

#### Example 1:
<pre>
<b>Input:</b> s = "abcabcbb"
<b>Output:</b> 3  
<b>Explanation:</b> The answer is "abc", with the length of 3.
</pre>

#### Example 2:
<pre>
<b>Input:</b> s = "bbbbb"
<b>Output:</b> 1
<b>Explanation:</b> The answer is "b", with the length of 1.
</pre>
#### Example 3:
<pre>
<b>Input:</b> s = "pwwkew"
<b>Output:</b> 3
<b>Explanation:</b> The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
</pre>
#### Example 4:
<pre>
<b>Input:</b> s = ""
<b>Output:</b> 0
</pre>

#### Constraints:

* `0 <= s.length <= 5 * 104`
* `s` consists of English letters, digits, symbols and spaces.


## Solution Details
#### px1624:
In this problem, a valid substring is a substring without any repeating character. Suppose we have a `begin` variable to mark the beginning of the substring while looping through the string character by character. If we encounter a character we've visited before, we only need to update the `begin` variable if the character we've seen before appears within the substring. A character is within the substring if it appears after the `begin`, thus we need to update the substring to start from 1 after the position of the character we last seen. Within each iteration, we only need to update the `max_len` if the current length of substring is greater than `max_len`.

#### zdong2080:
This sequence is for keep tracking the longest subsequence without repeating. Thus, it needs an data structure to fast search if the current element is already in the subsequence. Hash table would be the best one due to the fast insert and search. For the key, it would be the element since it is unique. For the value, it would be the index since we need to find the index of the element same as the current element if it was already in the subsequence. We then goes back to the previous element + 1. We keep tracking if the size of the subsequence is largest. And we return the max size.

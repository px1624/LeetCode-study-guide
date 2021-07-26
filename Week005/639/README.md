## Question 639. Decode Ways II

**(Hard)**

A message containing letters from `A-Z` can be **encoded** into numbers using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```
To **decode** an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, `"11106"` can be mapped into:

* `"AAJF"` with the grouping `(1 1 10 6)`
* `"KJF"` with the grouping `(11 10 6)`

Note that the grouping `(1 11 06)` is invalid because `"06"` cannot be mapped into `'F'` since `"6"` is different from `"06"`.

**In addition** to the mapping above, an encoded message may contain the `'*'` character, which can represent any digit from `'1'` to `'9'` (`'0'` is excluded). For example, the encoded message `"1*"` may represent any of the encoded messages `"11"`, `"12"`, `"13"`, `"14"`, `"15"`, `"16"`, `"17"`, `"18"`, or `"19"`. Decoding `"1*"` is equivalent to decoding `any` of the encoded messages it can represent.

Given a string `s` containing only digits, return *the **number** of ways to **decode** it*.

Since the answer may be very large, return it **modulo** <code>10<sup>9</sup> + 7</code>.
#### Example 1:

<pre>
<b>Input:</b> s = "*"
<b>Output:</b> 9
<b>Explanation:</b> The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
Each of these can be decoded to the strings "A", "B", "C", "D", "E", "F", "G", "H", and "I" respectively.
Hence, there are a total of 9 ways to decode "*".
</pre>

#### Example 2:

<pre>
<b>Input:</b> s = "1*"
<b>Output:</b> 18
<b>Explanation:</b> The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
Hence, there are a total of 9 * 2 = 18 ways to decode "1*".
</pre>

#### Example 3:

<pre>
<b>Input:</b> s = "2*"
<b>Output:</b> 15
<b>Explanation:</b> The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
"21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".
</pre>

#### Constraints:

* <code>1 <= s.length <= 10<sup>5</sup></code>
* `s[i]` is a digit or `'*'`.

## Solution Details

#### px1624:
The logic is similar to that of [Problem 91](/Week004/91). We need to add logic to handle the `*` character. If we encounter a `*`, we need to multiply the number of ways to encode by `9` since it can take any value from `1-9`. That is the case when `*` is encoded on its own. When combining it with the previous character we have the following cases:

* Both digits are `*`'s, i.e. `**`
    * There are `15` ways to decode `**`, `11-19` and `21-26`
    * Note that `*` cannot be `0`
* First digit is `*`, i.e. `*[0-9]`
    * Second digit is `[7-9]`
        * Then `*` must be `1`
        * The number of encodings stays the same
    * Second digit is `[0-6]`
        * Then `*` can be `1` or `2`
        * Doubling the number of encodings
* Second digit is `*`, i.e. `[1-2]*`
    * First digit is `1`
        * There are `9` possible values for `*`
    * First digit is `2`
        * There are `6` possible values for `*`
* Both digits are not `*`, i.e. `[1-2][0-9]`
    * The number of encodings stays the same if two digits are within range `[10-26]`

Using the above rules, we can calculate the total number of encodings for a given string.
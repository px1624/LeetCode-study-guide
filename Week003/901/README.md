## Question 901. Online Stock Span

**(Medium)**   

Write a class `StockSpanner` which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were `[100, 80, 60, 70, 60, 75, 85]`, then the stock spans would be `[1, 1, 1, 2, 1, 4, 6]`.

#### Example 1:
<pre>
<b>Input:</b> ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
<b>Output:</b> [null,1,1,1,2,1,4,6]
<b>Explanation:</b> 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
 </pre>

#### Note:

  1. Calls to `StockSpanner.next(int price)` will have `1 <= price <= 10^5`.
  2. There will be at most `10000` calls to `StockSpanner.next` per test case.
  3. There will be at most `150000` calls to `StockSpanner.next` across all test cases.
  4. The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.


## Solution Details
#### hcao10:
To find the maximum number of consecutive days for which the price of the stock was less than or equal to today's price, we can compare the price of the day with the previous price and record the number of consecutive days. Since "today's price is greater than yesterday's price" means that "the days that were previously less than yesterday's price are also less than today's price", it is not necessary to compare all the previous data each time, just fetching the prices of the previous days that are not within the current span value record:

![Example](https://github.com/px1624/LeetCode-study-guide/blob/282d5213319a7036008e7642533b4b6a5526c701/Week003/901/SD901.png "[100, 80, 60, 70, 60, 75, 85]")

[Corresponding Solution](https://github.com/px1624/LeetCode-study-guide/blob/282d5213319a7036008e7642533b4b6a5526c701/Week003/901/solution_hcao10.cpp)

### px1624:

The brute force solution would be to check every previous day's price until the price is higher than the current day. We can do better if we remember the all the previous days' span too. If current day's price is greater than the previous, we can then skip number of days equal to previous day's span because previous day's span must be within the current day's span. Thus we can greately reduce the number of times we check the previous days.
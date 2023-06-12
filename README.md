# Longest Increasing Subsequence (LIS)
Problem: Given a sequence of ${n}$ positive integers, $X = x_1, x_2, ..., x_n$, find the longest increasing subsequence of $X$. The program should read input from a "incseq.txt" file, one per line.

## Example
>Input: $X$ = {6, 3, 10, 12, 8, 7, 14, 9, 5}<br>
>Output: LIS Length = 4, LIS = {3, 10, 12, 14}<br>

## Approach
This is a dynamic programming approach, where the sub-problem is to compute $L[j]$, the length of the longest increasing subsequence that ends with index $j$. This requires some ${x}_{j}$ to be greater than all elements in a previously identified longest increasing subsequence.<br>
We will compute the length of the longest increasing subsequence for each progressively longer prefix of $x[ ]$. $L[j]$ will store the length of the longest increasing subsequence ending with $x[j]$. The base case is that a single integer prefix of $x[ ]$ will have a LIS length of 1. For each $x[i]$ we consider every $x[j]$, $(j < i)$ that is a predecessor of $x[i]$, $(x[j] < x[i])$ and set the $L[i]$ equal to the max of any such $L[j]+1$. We then determine the max value of $L$ to be the length of the longest increasing subsequence.
|    i|1|2|3|4|5|6|7|8|9|
|----:|-|-|-|-|-|-|-|-|-|
|Input|6|3|10|12|8|7|14|9|5|
|$L[i]$ |1|1|2|3|2|2|4|3|2|

In the example above, $L[i]$ keeps track of the longest increasing subsequence that ends with ${x}_{i}$. Taking the max we will find the longest increasing subsequence ends with $x[6]$, as $L[6]$ has the highest value. We can then use the other values of $L$ to print the previous elements, where for each $LIS[i-1], L[i-1] = L[i]-1$. In this example we will print the elements of $x$ whose elements increase in $L$.

* _Time Complexity_: _O(N<sup>2</sup>)_
* _Space Complexity_: _O(N)_

# 1085. Perfect Sequence (25)

## 题目

Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 105) is the number of integers in the sequence, and p (<= 109) is the parameter. In the second line there are N positive integers, each is no greater than 109.

Output Specification:

For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:

```
10 8
2 3 20 4 5 1 6 7 8 9
```
Sample Output:

```
8
```
## 分析

题目要求找出一些这样的序列，他的最大值小于最小值的n倍。找到则输出这些序列中元素最多可以为多少个。

故先给序列从小到达排序，这样前后组成的序列的头尾就是最小最大值，在给出序列中从第一个值开始，找出比这个值的n倍大的第一个数则为这个序列的最大值，然后比较每个序列中元素的个数，输出最大值即可

在这道题中学会了low_bound()和upper_bound()函数，表示找出某序列中第一个大于等于某个值的位置，和找出某序列中第一个大于某个值的位置。

题目中要求P<=1000000000，则最小值乘以p时会超出int的表示范围故要改成long long。


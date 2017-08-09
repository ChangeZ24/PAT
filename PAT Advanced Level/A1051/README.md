# 1051. Pop Sequence (25)

## 题目

Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:

```
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
```
Sample Output:

```
YES
NO
NO
YES
NO
```
## 分析

题目要求模拟入栈出栈验证所输入的出栈序列是否可行。

验证是否可行一是看当前栈内元素的数目是否大于栈的大小，超过则不可行，标志置为false。

二是模拟入栈，验证刚入栈的数是否与出栈序列的第一个元素相同，若相同则出栈，依次进行。当结束时检查栈是否空，标志是否为true即没有超出栈的情况

整个过程要保证pop或取值时栈不能为空。

写的过程中没有大问题，有很多小错，粗心造成。要改正

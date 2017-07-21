# 1031. Hello World for U (20)

## 题目

Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:

```
h  d
e  l
l  r
lowo
```
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

Sample Input:

helloworld!

Sample Output:

```
h   !
e   d
l   l
lowor
```
## 分析

题目中n1表示U型左边的字符数，n3表示U型右边的字符数，n2表示U型的底边的字符数，通过公式n1+n2+n3-2=n表示之间的关系，要求n2>=3且小于n，且n1=n3

由题意，n1取小于n2的最大值。

在做这道题，用了和题意不同的n1，n2，n3表示，n1表示U型除底边左边的字符数，n3亦同，n2表示U型底边的字符数，由于n2>=3，则通过观察，奇数的底永远是奇数，偶数底永远是偶数，则偶数的n2>=4。

在编码时，选择n2分成奇数偶数两种，分别从3,4开始，通过比较n1和n2的值确定n1和n2。

确定后完成打印。

在做时，比较n1和n2的判断有些疏忽，导致9个字符出现问题。最后改正后完成。

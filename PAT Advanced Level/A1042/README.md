# 1042. Shuffling Machine (20)

## 题目

Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines. Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. It is assumed that the initial status of a card deck is in the following order:

S1, S2, ..., S13, H1, H2, ..., H13, C1, C2, ..., C13, D1, D2, ..., D13, J1, J2

where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker". A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer K (<= 20) which is the number of repeat times. Then the next line contains the given order. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the shuffling results in one line. All the cards are separated by a space, and there must be no extra space at the end of the line.

Sample Input:

```
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
```

Sample Output:

```
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
```

## 思路

题意：

```
54张牌初始按编号从大到小排列，分别为13张S，13张H，13张C，13张D，2张J，即S1，S2，S3，...，H1，H2，H3，...，C1，C2，C3，...，D1，D2，D3，...，J1，J2，执行一种操作，将牌的位置改变为指定位置，例如有{S1，H9，C1，D2，J1}，给定指定位置为{4,2,1,3,5}，则变换后序列为{C1，H9，D2，S1，J1}。现在需要将此操作执行K次，例如上述执行两次则到{D2，H9，S1，C1，J1}
```

思路：

```
起初的思路是使用二维数组，使一列为顺序，一列为牌面值，改变一次就改变一次顺序，然后交换，然后发现很麻烦，二维数组操作起来错误也很多。
然后选择使用多个数组，代码中：
a[]为初始数组，当有多次变换时，也可作中间转换数组，即第二次转换时，a[]中存放第一次转换后的数组。
b[]保存规定的操作序列。
c[]为牌面字符值的数组，起初没有设置此数组，但最后输出选用“%d ”的形式，最后会多出一个空格，于是采用了c[]数组，最后一个值不参与循环输出，单独输出，采用求除数和余数的方式在c[]中寻找对应花色。
n[]保存最后的结果数组，并通过对13取余的余数和除数确定花色与数字。

转换方法：以一个变量x保存当前位置i规定的操作序列的位置，将初始数组中第i个位置的值，存入结果数组的第x-1个位置中（数组从0开始，牌面从1开始）。形成一个交换，即将原来位置i上的值，交换到x-1的位置（即逻辑上的第x个位置）。
```
## 总结

此方法虽然一次通过了，但仔细考虑还是有一些时间，空间的浪费，还有待改进。

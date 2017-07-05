# 1065. A+B and C (64bit) (20)

## 题目

Given three integers A, B and C in [-2^63, 2^63], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1).

Sample Input:

```
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
```

Sample Output:

```
Case #1: false
Case #2: true
Case #3: false
```

## 分析

题目不难，但ABC分别为[-2^63, 2^63]，可能会出现数的溢出。

A,B,C定为long long。long long的最大值为2^63-1。

1）若A,B均为最大值，则A+B大于long long能表示的最大值，产生溢出，在计算机组成原理中可学到，此溢出为正溢出，即A+B的值小于0。当A+B正溢出时，其和肯定大于C。

且正溢出后值的范围为[-2^63,-2]。

```
-2的计算:
A,B取的最大值为2^63-1，则A+B最大值为2^64-2。由long long有64bit，则A+B溢出后值最大为(2^63-1)%(2^64)=-2
```

2）若A,B均为最小值，则A+B小于long long的最小值，产生溢出，此溢出为负溢出，即A+B的值大于等于0。当A+B溢出负溢出时，其和肯定小于C

且负溢出后值的范围为[0,2^63]

```
0的计算：
A,B最小值为-2^63，则A+B=-2^64。则溢出后最小值为(-2^64)%(2^64)=0
```

若不产生溢出，则直接通过比较A+B和C进行输出即可。

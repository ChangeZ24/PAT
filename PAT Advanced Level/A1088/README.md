# 1088. Rational Arithmetic (20)

## 题目

For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:

```
2/3 -4/2
```
Sample Output 1:

```
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
```
Sample Input 2:

```
5/3 0/6
```
Sample Output 2:

```
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
```

## 分析

题目要求，给出两个分数，进行分数的四则运算并输出

题目不难，比较繁琐。题目给出分数的大小为long int，则结果为long long的范围。分母为0时除法输出Inf，负数的负号紧挨分子，最后的输出需要化简成假分数或最简分数。

学会了最大公约数的函数写法，和数学函数绝对值abs()的使用，很有收获

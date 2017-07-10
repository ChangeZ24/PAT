# 1009. Product of Polynomials (25)

## 题目

This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input

```
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

Sample Output

```
3 3 3.6 2 6.0 1 1.6
```

## 题意

多项式相乘

## 思路

和多项式相加类似，先将第一个多项式存入一个数组中，再输入第二个多项式时，与第一个多项式的每一项进行乘法运算，然后存入结果数组中，最后输出

## 错误点

1、结果数组的大小至少为2001，一个多项式的大小题目限定为1000，则两个多项式相乘最多有2000项

2、第一次完成后只有两个点答案正确，对照书后发现书中不是使用普通数组而是使用结构体数组来存多项式的每一项，仔细研究后发现，当使用普通数组进行循环相乘时，一般循环次数采用第一个多项式的项数，在此基础上循环相乘若从0开始循环，第一个多项式的前两项都为0的话，则并没有乘到第一个多项式的项上，故需要判断第一个多项式的项是否为0，此时则需要两个判断变量，若等于0则将数组1的次数加1，判断下一项是否为0，此时的循环次数的判断变量不能增加，仅当多项式的项不为0时，则两个判断条件都相加，指向下一项，并循环次数的判断变量加1，与循环次数相比判断是否次数已够。时

第2个错误点自己的解决，总觉得有一些浪费和复杂，但最终的结果是全部AC，随着以后水平增加，或许能想到更好的方法。

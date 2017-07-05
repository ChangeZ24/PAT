# 1002. A+B for Polynomials (25)

## 题目

This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input

```
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

Sample Output

```
3 2 1.5 1 2.9 0 3.2
```

## 分析

题目要求算多项式相加。

通过第一行输入，按指数将系数保存在数组中，第二行输入时，按指数将系数加到之前的数组中。最后通过遍历数组来确定项数，并将其输出。

## 错误

此题目陷阱很多，问题也很多。

1）整个思路最开始想的过于复杂，但考虑的十分不全面，导致将近一半的数据都答案错误，最终纠正了思路解决

2）起初使用边读入边计算项数count，但没有考虑到当系数为相反数时，相加为0，此时的项数需要-1

3）起初采用在输入第二行数据时，先按第二个多项式进行和第一个多项式同项相加，然后再通过遍历第一个多项式将与第二个多项式不同指数的项加上去。但这个问题在系数为相反数时，也存在很大问题，在相反数时相加此指数的系数为0，在遍历第一个多项式时，此时结果数组的此指数系数为0，会让计算机以为没有加入这一项，则又把第一个多项式的这个指数的项加入了结果数组，产生错误

4）在相加后结果为0时，只需要输出项数0即可

5）由于此问题数组大小规定为1000，则在遍历时，最大值要取到1000，则数组大小的定义也要大于1000。

这道题问题很多，有几次提交的显示答案错误，也没有想明白，看了书换了种思路解决了不少，之前的思路的问题有的也没有想明白，时间紧迫，先留个印象。

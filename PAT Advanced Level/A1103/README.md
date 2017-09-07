#  1103. Integer Factorization (30)

## 题目

The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K-P factorization of N for any positive integers N, K and P.

Input Specification:

Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.

Output Specification:

For each case, if the solution exists, output in the format:

N = n1^P + ... nK^P

where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122 + 42 + 22 + 22 + 12, or 112 + 62 + 22 + 22 + 22, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such that ai=bi for i<L and aL>bL
If there is no solution, simple output "Impossible".

Sample Input 1:

169 5 2

Sample Output 1:

169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2

Sample Input 2:

169 167 3

Sample Output 2:

Impossible

## 分析

### 题目分析

题目要求给出一个数，将他用指定的次数，不同或相同的指数相加的和表示，且保证最后的式子是指数和最大的排列选择。

若还有多种方案则使最后输出的的式子，指数降序排列，即在循环查询时采用按从大到小的顺序查询，此时保存的指数则为降序排列。

使用DFS来进行编码。

题目要求以指数和表示，且都是不同底数的相同次方，则建一个vector来保存指定次数的各个次方值，以便于在DFS选择时，直接选择次方的结果进行和运算，不再单独计算每个次方的值。

### 对于DFS搜索

即从保存的次方vector中选择若干个数（可重复）来进行加法。故存在选与不选两个分支，必要的参数有，当前所在的次方值在vector的位置index，便于取值，当前已经选择的数的个数nowK，与题目给出的K相比较，若大于K则不符合题意；当前的选择的数的和，以检查是否超出要求的N；与当前的底数和maxsum以便于和全局的max比较，是否当前是底数和最大的序列

```
DFS(int index,int nowK,int sum,int maxsum)
```

1、选

若选择，则nowK,sum,maxsum进行相应的更新，因为可以重复选择，则index不用更新，便于再次选择

```
DFS(index,nowK+1,sum+fas[index],maxsum+index)
```
2、不选

若不选择，则index指向下一个，由于降序排列，则index指向比他小的值，即index-1，其他参数不变

```
DFS(index-1,nowK,sum,maxsum)
```
3、DFS实现需要用到栈来存储

模板如下：

```
DFS(int index,int nowK,int sum,int maxsum){
    if(满足条件){
        ...//见下个递归的分析
    }
    不满足条件 return ;
    
    //开始选择判断，此时有条件限制要加if限制，如本题0的任何次方都是0，故当前位置为0时不参与选择搜索
    
    栈.pushback(index);                               //将当前选择的位置入栈
    DFS(index,nowK+1,sum+fas[index],maxsum+index);    //进行选择的分支
    栈.popback();                                     //选择的分支结束，进入不选的分支前需要把栈顶当前选择的位置出栈，保证当前不选的位置不在最后的队列中
    DFS(index-1,nowK,sum,maxsum);                     //不选的分支
}

```
###关于DFS递归的结束条件

由于题目要求最后的指数和=N，且选择数的个数要小于等于K，则退出条件如下，若满足条件，需要输出底数和最大的排列，则需要起初设置两个vector，一个保存当前的序列，一个保存此次之前底数和最大的排列，进行比较更新，模板如下：

```
if(sum==N&&nowK<=K){
    if(maxsum>max){//max代表此次之前的最大底数和
        vector最优=vector当前
        max=maxsum;
    }
}
```

# 1046. Shortest Distance (20)

## 题目

The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (in [3, 100000]), followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:

```
5 1 2 4 14 9
3
1 3
2 5
4 1
```

Sample Output:

```
3
10
7
```

## 分析

### 题意

有N个出口组成一个环，求任意两个出口之间的最短距离。出口数N的范围为[3, 100000]。相邻两出口之间的距离用Di表示，Di即Di与Di+1之间的距离，Dn表示Dn与D1之间的距离

输入第一行为，出口数N，D1~DN

第二行为，要计算最短路径的出口对的个数

之后每行：各个出口对

输出为：每行为相应出口对间的最短距离（可以不用最后一次性输出所有出口对的最短路径，可以输入一个出口对，则输出一个最短路径）

### 思路

原思路为：

在起初输入出口数与D1-DN时，计算出总路径，因为最后比较的最短路径其实是一半对一半，即若在5个出口中求1-3之间的最短路径，其比较D1+D2与D3+D4+D5，则在比较时，得到D1+D2，在用总路径减去此路径，则为另一半的路径，然后求最小值。

此方法由于在比较前需要计算其中一半的路径，所以需要两个循环，第一次提交的时候出现运行超时。

查书后找到原因：

因为在极端情况下，每次查询都需要遍历整个数组，即有100000次操作，两次循环则出线10000000000次操作，在100ms内无法承受，则运行超时。

书上思路为：

在计算总路径时，用一个数组dis保存1号出口到当前出口的总路径，则在比较时，不用循环求出两出口间的路径和，仅需要计算dis[e2-1]-dis[e1-1]，即为两出口间在一个方向上的路径和，用总路径sum-此路径和则为另一个方向上的路径和，比较即可，但也要注意在计算总路径sum时即将此数组累加计算完毕，否则再用一个循环则还是会有运行超时的问题

### 易错点

1、当两出口e1，e2出现e1>e2时，须先将两出口序号交换，否则在求差时出现问题

2、N的最大值为100000，但不能将数组的大小设置为100000。因为当数组定义a[N]，则其允许访问的只有0~N-1，无法访问a[N]。初学很容易错，比如我QAQ，第二次提交的时候就出现了答案错误，应该就是边界值100000的问题，改正了即AC。

### 学到的东西

在书上看发现这个题，作者并没有将swap函数和求min的函数写在代码里，而是include一个文件algorithm，查询后发现<algorithm>是c++特有的STL模板的算法头文件，包含了一些特定的算法函数，包括sort(),stable_sort(),partical_sort(),nth_element()等常用的算法函数，若用C语言写代码，在使用此文件时，需要加using namespace std;，以后基本的函数就可以直接用，省出代码量。

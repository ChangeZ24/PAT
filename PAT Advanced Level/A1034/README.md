# 1034. Head of a Gang (30)

## 题目

One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:

```
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
```
Sample Output 1:

```
2
AAA 3
GGG 3
```
Sample Input 2:

```
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
```
Sample Output 2:

```
0
```

## 分析

给出几条通信记录，通过遍历找出每个连通子图中每个点权最大的的点称为这个子图的头，若子图中点的个数大于2且总边权比输入的权值大时，称子图为一个帮派。

输出这样的帮派的个数，即每个帮派的头的名字和帮派中的人数。

在输入每条通信记录时，记录每个点的点权与边权。通过DFS遍历找出每个连通子图及子图中点权最大的点，并将其保存。最后通过遍历整个图找出满足帮派要求的各个帮派，保存所需要的信息并将其输出。

由于通信记录给出字符姓名，要用姓名来做索引，数组不可行且结构太复杂，故使用map<string,int>索引来建立姓名与编号的关系，对于图的索引有很大帮助。

整道题目学到很多知识，虽然不算自己独立完成的题目，但很有收获。

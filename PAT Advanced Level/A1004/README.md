# 1004. Counting Leaves (30)

##　题目

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input

```
2 1
01 1 02
```
Sample Output

```
0 1
```
## 分析

题目给出家族的成员编号和该节点结点的孩子数，求每一层的叶节点的个数，即没有孩子的结点的个数

通过建立一个容器数组保存每个成员的孩子，若改成员的容器大小为0，则表示没有孩子，用数组表示每一层的页结点个数，通过深度遍历来计算每一层的叶节点个数。

最开始没有想好算法，导致浪费很多时间，在看了书后发现题目并不难，还是没有好好思考，要锻炼自己的自我思考能力。而且速度还是一如既往的慢 = =

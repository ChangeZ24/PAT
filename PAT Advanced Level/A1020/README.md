# 1020. Tree Traversals (25)

## 题目
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:

```
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
```
Sample Output:

```
4 1 6 3 5 7 2
```
## 分析

题目不难，要求给出树的后序遍历和中序遍历，输出树的层次遍历

按数据结构时学习的基本模板即可完成，注意层次遍历使用队列完成。

# 1043. Is It a Binary Search Tree (25)

## 题目

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:

```
7
8 6 5 7 10 8 11
```
Sample Output 1:

```
YES
5 7 6 8 11 10 8
```
Sample Input 2:

```
7
8 10 11 8 6 7 5
```
Sample Output 2:

```
YES
11 8 10 7 5 6 8
```
Sample Input 3:

```
7
8 6 8 5 10 9 11
```
Sample Output 3:

```
NO
```

## 分析

题意要求检查所给序列是不是排序二叉树或排序二叉树的镜像树（左右子树交换），若是则输出YES，并输出树的后序遍历，否则输出NO

题目不难，我的想法是直接检查所给序列，如果根结点后的结点出现比根大的数，且这个数的后面的数比根小，则不满足排序二叉树，或者根节点后的结点出现比它小的数，且这个数的后一个数比根节点大，则不满足。其余情况都满足情况，直接后序遍历输出

满分25，过了24分，最后一分想不明白为什么TAT

# 1089. Insert or Merge (25)

## 题目

According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:

```
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
```
Sample Output 1:

```
Insertion Sort
1 2 3 5 7 8 9 4 6 0
```
Sample Input 2:

```
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
```
Sample Output 2:

```
Merge Sort
1 2 3 8 4 5 7 9 0 6
```
## 分析

题意要求根据所给升序初始序列和部分排序后的序列，判断使用的是二路归并排序还是直接插入排序，并输出下一趟排序后的序列

起初先把二路归并和直接插入排序的函数写好，然后发现并没有用到

判断直接插入首先找出后项比前项小的位置，然后判断从这个位置起剩下的元素和原序列对应位置的元素是否相等，若相等则为直接插入，否则为归并排序

难点在于如何判断所给部分排序后的序列进行了几次拆分。

通过查询发现很多使用STL的equal函数比较，但由于起初使用的是数组而非容器，放弃此想法，看到有网友使用了如下方法，先将原序列按2，4，8的拆分依次排序，每次排序后检查是否与所给部分排序的序列相同，若相同则在此基础上再进行一次排序即为所求下一趟归并的排序

在本题中学到了很多，对于算法还是想的不够好，还需要锻炼。

# 1025. PAT Ranking (25)

## 题目

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:

```
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
```

Sample Output:

```
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
```
## 分析

题意大致为给出N个考场，每个考场有K个学生，排出每个考场的名次，再排出所有学生的名次

本题中使用了sort()函数，直接进行排序，省了很多问题。

在编码时出现段错误，数组越界，发现总共有N个考场，每个K个学生，所以整个的数组大小的最低为N*K个，即30000个

难点应该是循环时，如何确定循环的初值和循环的次数，使得通过一次输入，N次循环中把每个考场的学生信息存入同一个数组中。在这个过程中设置一个变量来记录学生总数，然后所有的循环变量通过这个总数和每个考场人数及循环初值之间的关系而形成整个循环。

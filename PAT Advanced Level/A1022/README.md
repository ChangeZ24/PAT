# 1022. Digital Library (30)

## 题目

A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:

Line #1: the 7-digit ID number;

Line #2: the book title -- a string of no more than 80 characters;

Line #3: the author -- a string of no more than 80 characters;

Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;

Line #5: the publisher -- a string of no more than 80 characters;

Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].

It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

1: a book title

2: name of an author

3: a key word

4: name of a publisher

5: a 4-digit number representing the year

Output Specification:

For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.

Sample Input:

```
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
```

Sample Output:

```
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
```

## 分析

题目要求给出一系列书本信息，包括id，书名，作者，关键字，出版商和出版年份，再给出要查询的关键信息，建立查询，最后按递增顺序输出负荷每个关键信息的id号，如果没有则输出Not Found

题目本身意思不难，难在创建结构

书中提示可以使用map结构来构建各个信息与id之间的映射，并使用set结构来存储可以自动构成递增顺序。

题中在写查询函数时，不能使用cout输出信息，在函数参数中要使用引用来减少遍历查询的时间否则都会使最后两个测试点提示错误。

set在插入时使用map[“string关键字”].insert(id)来对应每个关键信息插入所在序号，遍历使用it指针来进行遍历

题目不难但能学到很多，很有收获。

# 1091. Acute Stroke (30)

## 题目

One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M by N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are "connected" and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.

Figure 1
Output Specification:

For each case, output in a line the total volume of the stroke core.

Sample Input:

```
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
```

Sample Output:

26

## 分析

题目通过广度优先遍历要求找出中枢核心，并输出核心中1的个数之和。

给出三维数组，并将1,0存入数组，数组中与某一个元素相邻的元素为其上下左右前后六个方向的邻接元素，若干个相邻的1称为一个块，不需要两两相邻，只要与块中某一个1相邻就把它加入到块中，最终找到块中1的个数少于给出的T的块，则此块称为核心区。最终解出核心区中1的个数之和。

解题使用广度优先遍历，从数组中每一个元素开始，如果为0，则跳过，为1，则从这个1开始使用BFS查询与该位置相邻的六个方向上的元素，如果为1，则继续做同样的查询，直到块中没有1。

按照广度优先遍历的模板，BFS的格式为

```
BFS(int x,int y, int z)
```

通过算法，需要判断元素是否被选择。

被选择，则通过判断当前情况是否满足要求，若满足则更新当前元素位置，否则退出

BFS实现需要用到队列

模板为：

```
queue<type>q;
q.push(队头);
将当前位置设置为已入队
while(!q.empty()){
    top=q.front();//取出队首
    q.pop();
    操作;
    for(int i=0;i<6;i++){//以下为和题目要求相类似的坐标寻找的题目模板。
        int nowX=top.x+x;
        int nowY=top.y+y;
        int nowZ=top.z+z;
        if(判断满足题意要求){
            访问新位置
            更新位置坐标  //node.x=nowX ...
            q.push(node);
            将新位置设置为已入队
        }
    }
}
```

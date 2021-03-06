# 4-11 求自定类型元素序列的中位数   (25分)

本题要求实现一个函数，求N个集合元素A[]的中位数，即序列中第N/2+1（向下取整）大的元素。其中集合元素的类型为自定义的ElementType。

函数接口定义：

ElementType Median( ElementType A[], int N );

其中给定集合元素存放在数组A[]中，正整数N是数组元素个数。该函数须返回N个A[]元素的中位数，其值也必须是ElementType类型。

裁判测试程序样例：

```C

#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
```
输入样例：

3

12.3 34 -5

输出样例：

12.30

# 分析

此题看起来是先对数组排序再求中位数，但运用插入排序和简单快速排序时，总是部分正确，说明此题对复杂度要求较高。故对于O（n2）的排序算法都不能满分通过。

查询资料最后采用二分法的快速排序解决。很多网友使用希尔排序来通过此题。对于希尔排序了解甚少，下次时间研究后上传。

# 参考资料

http://wuchong.me/blog/2014/02/09/algorithm-sort-summary/

http://www.lai18.com/content/2546719.html

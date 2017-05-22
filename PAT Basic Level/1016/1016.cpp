#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
/*正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
现给定A、DA、B、DB，请编写程序计算PA + PB。
输入格式：
输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
输出格式：
在一行中输出PA + PB的值。
输入样例1：
3862767 6 13530293 3
输出样例1：
399*/
int main(){
	int A, B, DA, DB;
	int PA, PB;
	int a, b;
	while (scanf("%d%d%d%d", &A, &DA, &B, &DB) != EOF) {
		for (PA = 0,PB = 0;A != 0 || B != 0;A = A / 10, B = B / 10) {
			a = A % 10;
			b = B % 10;
			if (a == DA)
				PA = PA * 10 + DA;
			if (b == DB)
				PB = PB * 10 + DB;
		}
		printf("%d\n", PA + PB);
	}
	system("pause");
	return 0;
}
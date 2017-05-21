#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>

/*划拳是古老中国酒文化的一个有趣的组成部分。酒桌上两人划拳的方法为：每人口中喊出一个数字，同时用手比划出一个数字。
如果谁比划出的数字正好等于两人喊出的数字之和，谁就赢了，输家罚一杯酒。两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。
下面给出甲、乙两人的划拳记录，请你统计他们最后分别喝了多少杯酒。
输入格式：
输入第一行先给出一个正整数N（<=100），随后N行，每行给出一轮划拳的记录，格式为：
甲喊 甲划 乙喊 乙划
其中“喊”是喊出的数字，“划”是划出的数字，均为不超过100的正整数（两只手一起划）。
输出格式：
在一行中先后输出甲、乙两人喝酒的杯数，其间以一个空格分隔。
输入样例：
5
8 10 9 12
5 10 5 10
3 8 5 12
12 18 1 13
4 16 12 15
输出样例：
1 2*/
int main(){
	int play[100][4];
	int n, sum;
	int Alose = 0, Blose = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		for(int j = 0;j<4;j++)
			scanf("%d", &play[i][j]);
	}
	for (int i = 0;i < n;i++) {
		sum = play[i][0] + play[i][2];
		if (play[i][1] == sum&&play[i][3] != sum)
			Blose++;
		else if (play[i][3] == sum&&play[i][1] != sum)
			Alose++;
	}
	printf("%d %d\n", Alose,Blose);
	system("pause");
	return 0;
}
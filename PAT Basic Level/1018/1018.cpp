#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
/*输入格式：
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
输出格式：
输第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。
第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。
如果解不唯一，则输出按字母序最小的解。
输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
C>J,J>B,B>C
num
甲 赢 平 负
乙 赢 平 负
A
手势 C,J,B*/
int trans(char c) {
	if (c == 'B')
		return 0;
	else if (c == 'C')
		return 1;
	else
		return 2;
}
int main(){
	char play[3] = { 'B','C','J' }, p1, p2;
	int n, a[3] = { 0 }, b[3] = { 0 }, pa[3] = { 0 }, pb[3] = { 0 }, k1, k2;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		getchar();
		scanf("%c %c", &p1, &p2);
		k1 = trans(p1);
		k2 = trans(p2);
		if (k1 == k2) {
			a[1]++;
			b[1]++;
		}
		else if ((k1+1)%3==k2) {
			a[0]++;
			b[2]++;
			pa[k1]++;
		}
		else {
			a[2]++;
			b[0]++;
			pb[k2]++;
		}
	}
	printf("%d %d %d\n", a[0], a[1], a[2]);
	printf("%d %d %d\n", b[0], b[1], b[2]);
	k1 = 0, k2 = 0;
	for (int i = 0;i < 3;i++) {
		if (pa[i] > pa[k1])
			k1 = i;
		if (pb[i] > pb[k2])
			k2 = i;
	}
	printf("%c %c\n", play[k1], play[k2]);
	system("pause");
	return 0;
}

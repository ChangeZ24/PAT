#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
/*�����ʽ��
�����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�
C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�
�����ʽ��
���1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ���
��3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�
����ⲻΨһ�����������ĸ����С�Ľ⡣
����������
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
���������
5 3 2
2 3 5
B B
C>J,J>B,B>C
num
�� Ӯ ƽ ��
�� Ӯ ƽ ��
A
���� C,J,B*/
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

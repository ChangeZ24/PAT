#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
/*������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA�����磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��
�ָ���A��DA��B��DB�����д�������PA + PB��
�����ʽ��
������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��
�����ʽ��
��һ�������PA + PB��ֵ��
��������1��
3862767 6 13530293 3
�������1��
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
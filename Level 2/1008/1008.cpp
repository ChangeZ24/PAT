#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
/*һ������A�д���N��N>0�����������ڲ�����ʹ�����������ǰ���£���ÿ������ѭ��������M��M>=0����λ��
����A�е������ɣ�A0 A1����AN-1���任Ϊ��AN-M ���� AN-1 A0 A1����AN-M-1�������M����ѭ��������ǰ���M��λ�ã���
�����Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����
�����ʽ��ÿ���������һ��������������1������N ( 1<=N<=100)��M��M>=0������2������N��������֮���ÿո�ָ���
�����ʽ����һ�������ѭ������Mλ�Ժ���������У�֮���ÿո�ָ������н�β�����ж���ո�
����������
6 2
1 2 3 4 5 6
���������5 6 1 2 3 4*/
int main(){
	int N,M;
	int A[100];
	scanf("%d%d", &N,&M);
	for (int i = 0;i < N;i++)
		scanf("%d", &A[i]);
	M = M%N;
	if(M==0)
		for (int i = 0;i < N;i++) {
			printf("%d", A[i]);
			if (i < N - 1)
				printf(" ");
		}
	else {
		for (int i = N - M;i < N;i++) 
			printf("%d ", A[i]);
		for (int i = 0;i < N - M;i++) {
			printf("%d", A[i]);
			if (i < N - M - 1)
				printf(" ");
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

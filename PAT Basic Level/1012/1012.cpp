#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
int main(){
	int A1, A2, A3, A5, N;
	int num[1000], j, k;
	double A4;
	scanf("%d", &N);
	if (N < 1001) {
		A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0;
		j = 0, k = 0;
		for (int i = 0;i < N;i++) {
			scanf("%d", &num[i]);
			if (num[i] % 5 == 0 )
				if(num[i] % 2 == 0)
				    A1 += num[i];
			if (num[i] % 5 == 1) {
				if (j % 2 == 0) {
					A2 += num[i];
				}
				else
					A2 -= num[i];
				j++;
			}
			if (num[i] % 5 == 2)
				A3++;
			if (num[i] % 5 == 3) {
				A4 += num[i];
				k++;
			}
			if (num[i] % 5 == 4) {
				if (num[i] >= A5)
					A5 = num[i];
			}
		}
		if (A1 == 0)
			printf("N ");
		else
			printf("%d ", A1);
		if (j == 0)
			printf("N ");
		else
			printf("%d ", A2);
		if (A3 == 0)
			printf("N ");
		else
			printf("%d ", A3);
		if (k == 0)
			printf("N ");
		else
			printf("%.1f ", A4 / k);
		if (A5 == 0)
			printf("N\n");
		else
			printf("%d\n", A5);
	}
	system("pause");
	return 0;
}

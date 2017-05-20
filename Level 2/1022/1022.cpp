#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>

int main(){
	int A, B, D;
	int num, result[40], count = 0;
	scanf("%d%d%d", &A, &B, &D);
	if (A >= 0 && B >= 0 && D > 0 && D < 11) {
		num = A + B;
		do {
			result[count++] = num % D;
			num = num / D;
		} while (num != 0);
		for (int j = count - 1;j >= 0;j--)
			printf("%d", result[j]);
	}
	system("pause");
	return 0;
}

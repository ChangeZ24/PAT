#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>

int main(){
	int n,num=0;
	scanf("%d", &n);
	if (n > 0 && n < 1001) {
		if (n / 100 != 0) {
			for (int i = 0;i < n / 100;i++)
				printf("B");
			for (int i = 0;i < (n % 100 - n % 10) / 10;i++)
				printf("S");
			for (int i = 1;i <= n % 10;i++)
				printf("%d", i);
		}
		else if (n / 10 != 0) {
			for (int i = 0;i < n / 10;i++)
				printf("S");
			for (int i = 1;i <= n % 10;i++)
				printf("%d", i);
		}
		else
			for (int i = 1;i <= n;i++)
				printf("%d", i);
	}
	printf("\n");
	system("pause");
	return 0;
}

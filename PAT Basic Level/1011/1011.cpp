#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cmath>
int main(){
	int T;
	long long a[10], b[10], c[10];
	scanf("%d", &T);
	if (T > 0 && T <= 10) {
		for (int i = 0;i < T;i++)
			scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
		for (int i = 0;i < T;i++) {
			if ((a[i] <= pow(2, 31) && a[i] >= -pow(2, 31)) && (b[i] <= pow(2, 31) && b[i] >= -pow(2, 31)) && (c[i] <= pow(2, 31) && c[i] >= -pow(2, 31))) {
				if (a[i] + b[i] > c[i])
					printf("Case #%d: true\n", i + 1);
				else
					printf("Case #%d: false\n", i + 1);
			}
			else
				break;
		}
	}
	system("pause");
	return 0;
}

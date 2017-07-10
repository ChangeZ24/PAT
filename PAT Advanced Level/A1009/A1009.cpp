#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 1002
using namespace std;

int main() {
	double a[MAX] = { 0 };
	double c[2004] = { 0 };
	int e = 0, k1 = 0, count = 0, k2 = 0, j = 0;
	double  n = 0.0;
	scanf("%d", &k1);
	for (int i = 0;i < k1;i++) {
		scanf("%d %lf", &e, &n);
		a[e] = n;
	}
	scanf("%d", &k2);
	for (int i = 0;i < k2;i++) {
		scanf("%d %lf", &e, &n);
		count = 0;j = 0;
		while (count < k1) {
			if (a[j] != 0) {
				c[j + e] += n*a[j];
				j++;
				count++;
			}
			else
				j++;
		}
	}
	count = 0;
	for (int i = 0;i <2004;i++) {
		if (c[i] != 0.0)
			count++;
	}
	if (count != 0)
		printf("%d ", count);
	else
		printf("0");
	for (int i = 2003;i >= 0;i--) {
		if (c[i] != 0.0) {
			printf("%d %.1f", i, c[i]);
			count--;
			if (count != 0)
				printf(" ");
		}
	}
	system("pause");
	return 0;
}
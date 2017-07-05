#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 1002
using namespace std;

int main() {
	double a[MAX] = { 0 };
	int e = 0, k = 0, count = 0;
	double  n = 0.0;
	a[0] = 0;
	scanf("%d", &k);
	while (k--) {
		scanf("%d%lf", &e, &n);
		a[e] = n;
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d%lf", &e, &n);
		a[e] += n;
	}
	for (int i = 0;i <1002;i++) {
		if (a[i] != 0)
			count++;
	}
	if (count != 0)
		printf("%d ", count);
	else
		printf("0");
	for (int i = 1001;i >= 0;i--) {
		if (a[i] != 0) {
			printf("%d %.1f", i, a[i]);
			count--;
			if (count != 0)
				printf(" ");
		}
	}
	return 0;
}
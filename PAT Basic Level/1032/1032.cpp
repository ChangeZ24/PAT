#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cmath>

int main(){
	int n, j = 0, school, score;
	int sum[100000] = {0};
	int max;
	scanf("%d", &n);
	if (n >= 0 || n < 1000001) {
		for (int i = 0;i < n;i++) {
			scanf("%d %d", &school, &score);
			sum[school] += score;
		}
		max = sum[1];
		for (int i = 1;i <= n;i++)
			if (sum[i] >= max) {
				max = sum[i];
				j = i;
			}	
	}
	printf("%d %d\n", j, max);
	system("pause");
	return 0;
}

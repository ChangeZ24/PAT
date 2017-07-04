#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 100002
using namespace std;

int main() {
	int N, M, sum = 0;
	int D[MAX], d[MAX] = {0};
	int e1, e2;
	int r = 0,m = 0;
	scanf("%d", &N);
	for (int i = 1;i < N + 1;i++) {
		scanf("%d", &D[i]);
		sum += D[i];
		d[i] = sum;
	}
	if (N > 2) {
		scanf("%d", &M);
		for (int i = 0;i < M;i++) {
			r = 0;
			scanf("%d %d", &e1, &e2);
			if (e2 < e1) 
				swap(e1, e2);
			m = d[e2-1] - d[e1-1];
			r = sum - m;
			printf("%d\n", min(m, r));
		}
	}
	else
		return 0;
	system("pause");
	return 0;
}
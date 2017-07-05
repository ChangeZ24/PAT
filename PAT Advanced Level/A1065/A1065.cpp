#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 100002
using namespace std;

int main() {
	int N, X = 1;
	long long A, B, C;
	long long ex;
	scanf("%d", &N);
	if (N > 0 && N < 11) {
		while (N--) {
			scanf("%lld %lld %lld", &A, &B, &C);
			ex = A + B;
			printf("Case #%d: ", X);
			if (A > 0 && B > 0 && ex < 0) {
				printf("true\n");
				X++;
			}
			else if (A < 0 && B < 0 && ex >= 0) {
				printf("false\n");
				X++;
			}
			else if (ex > C) {
				printf("true\n");
				X++;
			}
			else {
				printf("false\n");
				X++;
			}
		}
	}
	system("pause");
	return 0;
}
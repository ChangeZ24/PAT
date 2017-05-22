#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cmath>

int main(){
	int n, m, l = 0, r = 0;
	char a;
	scanf("%d %c", &n, &a);
	m = n;
	if (n > 2 && n < 21) {
		if (n % 2 == 0)
			n = n / 2;
		else
			n = n / 2 + 1;
		for (r = 0;r < n;r++) {
			for (l = 0;l < m;l++) {
				if (r == 0 || r == n-1)
					printf("%c", a);
				if (r > 0 && r < n-1) {
					if (l == 0 || l == m - 1)
						printf("%c", a);
					else
						printf(" ");
				}
				if (l == m - 1)
					printf("\n");
			}
		}
	}
	system("pause");
	return 0;
}

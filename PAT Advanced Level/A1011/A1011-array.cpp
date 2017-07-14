#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAX 1002
using namespace std;

int main() {
	double odds[3];
	char result[3] = { 'W','T','L' };
	char r[3];
	double profit = 0.0, out = 1.0;
	double m;//max
	int temp = 0;
	for (int i = 0;i < 3;i++) {
		m = 0.0;
		for (int j = 0;j < 3;j++) {
			scanf("%lf", &odds[j]);
			if (m < odds[j]) {
				m = odds[j];
				temp = j;
			}
		}
		r[i] = result[temp];
		out *= m;
	}
	profit = (out*0.65 - 1) * 2;
	printf("%c %c %c %.2f", r[0], r[1], r[2], profit);
	return 0;
}


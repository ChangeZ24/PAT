#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
#define MAX 100004
#define MINF 1000000000;
using namespace std;


int main() {
	int n, p;
	int a[MAX];
	int distence = 1;
	cin >> n >> p;
	for (int i = 0;i < n;i++) 
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0;i < n;i++) {
		int index = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
		distence = max(distence, index - i);
	}
	printf("%d\n", distence);
	system("pause");
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int N, K, P, maxFacSum = -1;
vector<int>fac;
vector<int>temp, ans;
int power(int x) {
	int a = 1;
	for (int i = 0;i < P;i++) 
		a *= x;
	return a;
}
void init() {
	int i = 0, temp = 0;
	while (temp <= N) {
		fac.push_back(temp);
		temp = power(++i);
	}
}
void DFS(int index, int nowK, int sum, int facsum) {
	if (sum == N&&nowK == K) {
		if (facsum > maxFacSum) {
			maxFacSum = facsum;
			ans = temp;
		}
		return;
	}
	if (sum > N || nowK > K)
		return;
	if (index - 1 >= 0) {
		temp.push_back(index);
		DFS(index, nowK + 1, sum + fac[index], facsum + index);
		temp.pop_back();
		DFS(index - 1, nowK, sum, facsum);
	}
}
int main(){
	scanf("%d%d%d", &N, &K, &P);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if (maxFacSum == -1)
		cout << "Impossible" << endl;
	else {
		printf("%d = %d^%d", N, ans[0], P);
		//cout << N << " = " << ans[0] << "^" << P;
		for (int i = 1;i < ans.size();i++)
			printf(" + %d^%d", ans[i], P);
			//cout << " + " << ans[i] << "^" << P;
		cout << endl;
	}
	system("pause");
	return 0;
}
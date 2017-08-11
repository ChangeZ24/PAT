#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAX 104
using namespace std;
vector<int> tree[MAX];
int leaf[MAX] = { 0 };
int depth = 1;
void DFS(int node, int level) {
	depth = max(depth, level);
	if (tree[node].size() == 0) {
		leaf[level]++;
		return;
	}
	for (int i = 0;i < tree[node].size();i++)
		DFS(tree[node][i], level + 1);
}
int main() {
	int n, m, p, c;
	scanf("%d%d", &n, &m);
	int k;
	for (int i = 0;i < m;i++) {
		scanf("%d%d", &p, &k);
		for (int j = 0;j < k;j++) {
			scanf("%d", &c);
			tree[p].push_back(c);
		}
	}
	DFS(1, 1);
	printf("%d", leaf[1]);
	for (int i = 2;i < depth + 1;i++)
		printf(" %d", leaf[i]);
	system("pause");
	return 0;
}
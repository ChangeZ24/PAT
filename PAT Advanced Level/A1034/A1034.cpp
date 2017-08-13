#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
#define MAX 2010
using namespace std;

map<string, int>nametonum;
map<int, string>numtoname;
map<string, int>gang;
int pernum = 0;
int k;
int G[MAX][MAX], weight[MAX];
bool visit[MAX] = { false };


void DFS(int nowvisit, int &head,int &nummember,int &totalvalue) {
	nummember++;
	visit[nowvisit] = true;
	if (weight[nowvisit] > weight[head])
		head = nowvisit;
	for (int i = 0;i < pernum;i++) {
		if (G[nowvisit][i] > 0) {
			totalvalue += G[nowvisit][i];
			G[nowvisit][i] = G[i][nowvisit] = 0;
			if (visit[i] == false)
				DFS(i, head, nummember, totalvalue);
		}
	}
}
int findno(string str) {
	if (nametonum.find(str) != nametonum.end()) 
		return nametonum[str];
	else {
		nametonum[str] = pernum;
		numtoname[pernum] = str;
		return pernum++;
	}
}
void findgang() {
	for (int i = 0;i < pernum;i++) {
		if (visit[i] == false) {
			int head = i, totalvalue = 0, nummember = 0;
			DFS(i, head, nummember, totalvalue);
			if (nummember > 2 && totalvalue > k)
				gang[numtoname[head]] = nummember;
		}
	}
}
int main() {
	int n;
	string str1, str2;
	int weig;
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> str1 >> str2 >> weig;
		int id1 = findno(str1);
		int id2 = findno(str2);
		weight[id1] += weig;
		weight[id2] += weig;
		G[id1][id2] += weig;
		G[id2][id1] += weig;
	}
	findgang();
	cout << gang.size() << endl;
	for (map<string, int>::iterator it = gang.begin();it != gang.end();it++)
		cout << it->first << " " << it->second << endl;
	system("pause");
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#define MAX 100004
#define MINF 1000000000;
using namespace std;

map<string, set<int>>title, author, keywords, publisher, year;
void query(map<string, set<int>> &qu, string &str) {
	if (qu.find(str) == qu.end())
		cout << "Not Found" << endl;
	else
		for (set<int>::iterator it = qu[str].begin();it != qu[str].end();it++)
			printf("%07d\n", *it);

}
int main() {
	int n, id, m, type;
	string ti, au, key, pub, yer, info;
	cin >> n;
	for (int i = 0;i < n;i++) {
		scanf("%d", &id);
		int c = getchar();
		getline(cin, ti);
		title[ti].insert(id);
		getline(cin, au);
		author[au].insert(id);
		while (cin >> key) {
			keywords[key].insert(id);
			c = getchar();
			if (c == '\n')
				break;
		}
		getline(cin, pub);
		publisher[pub].insert(id);
		getline(cin, yer);
		year[yer].insert(id);
	}
	cin >> m;
	for (int i = 0;i < m;i++) {
		scanf("%d: ", &type);
		getline(cin, info);
		cout << type << ": " << info << endl;
		if (type == 1)
			query(title, info);
		if (type == 2)
			query(author, info);
		if (type == 3)
			query(keywords, info);
		if (type == 4)
			query(publisher, info);
		if (type == 5)
			query(year, info);
	}
	system("pause");
	return 0;
}
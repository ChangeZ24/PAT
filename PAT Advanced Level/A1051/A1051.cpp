#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<iostream>
#include<algorithm>
#define MAX 1010
using namespace std;
stack<int> st;
int main() {
	int n, m, k, temp;
	bool flag = true;
	int num[MAX];
	cin >> m >> n >> k;
	while (k--) {
		while (!st.empty())
			st.pop();
		for (int i = 1;i <= n;i++)
			scanf("%d", &num[i]);
		temp = 1;
		flag = true;
		for (int i = 1;i <= n;i++) {
			st.push(i);
			if (st.size() > m) {
				flag = false;
				break;
			}
			while (!st.empty() && st.top() == num[temp]) {
				st.pop();
				temp++;
			}
		}
		if (st.empty() == true && flag == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}
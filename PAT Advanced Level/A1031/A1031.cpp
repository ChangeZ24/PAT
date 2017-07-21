#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<algorithm>
#define MAX 1002
using namespace std;

int main() {
	int n;
	int n1 = 0, n2 = 0, n3 = 0;
	char c[MAX];
	gets(c);
	n = strlen(c);
	if(n%2==0)
		for (n2 = 4;(n - n2) / 2 - n2 >= 0;n2 += 2);
	else
		for (n2 = 3;(n - n2) / 2 - n2 >= 0;n2 += 2);
	n1 = (n - n2) / 2;
	for (int i = 0;i < n1;i++) {
		printf("%c", c[i]);
		for (int j = 0;j < n2 - 2;j++)
			printf(" ");
		printf("%c\n", c[n - i - 1]);
	}
	for (int i = 0;i < n2;i++)
		printf("%c", c[n1+i]);
	system("pause");
	return 0;
}


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX 1002
using namespace std;

typedef struct student {
	char no[7];
	char name[10];
	int grade;
}stu;
bool cmpno(stu s1, stu s2) {
	return strcmp(s1.no,s2.no)<0;
}
bool cmpna(stu s1, stu s2) {
	int s = strcmp(s1.name, s2.name);
	if (s != 0)
		return s < 0;
	else
		return strcmp(s1.no, s2.no) < 0;
}
bool cmp(stu s1, stu s2) {
	if (s1.grade != s2.grade)
		return s1.grade < s2.grade;
	else
		return strcmp(s1.no, s2.no) < 0;
}
//char course[4] = { 'A','C','M','E' };
int main() {
	stu s[100004];
	//int rank[1000000][4] = { 0 };
	int C, n;
	cin >> n >> C;
	for (int i = 0;i < n;i++) 
		scanf("%s%s%d", &s[i].no, &s[i].name, &s[i].grade);
	switch (C) {
	case 1:
		sort(s, s + n, cmpno);
		break;
	case 2:
		sort(s, s + n, cmpna);
		break;
	case 3:
		sort(s, s + n, cmp);
		break;
	}
	for (int i = 0;i < n;i++)
		printf("%s %s %d\n", s[i].no, s[i].name, s[i].grade);
	system("pause");
	return 0;
}
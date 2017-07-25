#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX 1002
using namespace std;

typedef struct student {
	char no[15];
	int grade;
	int local;
	int rank;
	int testlocation;
}stu;
bool cmp(stu s1, stu s2) {
	if (s1.grade != s2.grade)
		return s1.grade > s2.grade;
	else
		return strcmp(s1.no, s2.no) < 0;
}
int main() {
	stu s[30002];
	int n, k, num = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> k;
		for (int j = 0;j < k;j++) {
			scanf("%s%d", &s[num].no, &s[num].grade);
			s[num].testlocation = i + 1;
			num++;
		}
		sort(s + num - k, s + num, cmp);
		s[num - k].local = 1;
		//printf("%s %d", s[num-k].no, s[num-k].local);
		for (int j = num - k + 1;j < num;j++) {
			if (s[j].grade == s[j - 1].grade)
				s[j].local = s[j - 1].local;
			else
				s[j].local = j + 1 - (num - k);
			//printf("%s %d\n", s[j].no, s[j].local);
		}
	}
	sort(s, s + num, cmp);
	s[0].rank = 1;
	printf("%d\n", num);
	printf("%s %d %d %d\n", s[0].no, s[0].rank, s[0].testlocation, s[0].local);
	for (int i = 1;i < num;i++) {
		if (s[i].grade == s[i - 1].grade)
			s[i].rank = s[i - 1].rank;
		else
			s[i].rank = i + 1;
		printf("%s %d %d %d\n", s[i].no, s[i].rank, s[i].testlocation, s[i].local);
	}
	//system("pause");
	return 0;
}